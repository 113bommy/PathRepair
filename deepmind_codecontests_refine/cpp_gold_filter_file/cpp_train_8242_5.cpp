#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
set<int> A[100010], B[100010];
int n, m, k;
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= k; ++i) {
    int x = read(), y = read();
    A[x].insert(y);
    B[y].insert(x);
  }
  for (int i = 1; i <= n; ++i) {
    A[i].insert(m + 1);
    A[i].insert(0);
  }
  for (int i = 1; i <= m; ++i) {
    B[i].insert(n + 1);
    B[i].insert(0);
  }
  long long len = 0;
  int x1 = 1, x2 = n, ysgh = 0, y2 = m;
  int type = 0;
  while (true) {
    if (x1 > x2 || ysgh > y2) break;
    if (type == 0) {
      int R = min(*A[x1].upper_bound(ysgh), y2 + 1);
      --R;
      if (R == ysgh) break;
      len += R - ysgh;
      y2 = R;
      ++ysgh;
    } else if (type == 1) {
      int D = min(*B[y2].upper_bound(x1), x2 + 1);
      --D;
      if (D == x1) break;
      len += D - x1;
      x2 = D;
      ++x1;
    } else if (type == 2) {
      int L = max(*--A[x2].lower_bound(y2), ysgh - 1);
      ++L;
      if (L == y2) break;
      len += y2 - L;
      ysgh = L;
      --y2;
    } else {
      int U = max(*--B[ysgh].lower_bound(x2), x1 - 1);
      ++U;
      if (U == x2) break;
      len += x2 - U;
      x1 = U;
      --x2;
    }
    type = (type + 1) % 4;
  }
  printf(1LL * n * m == len + k ? "Yes\n" : "No\n");
  return 0;
}
