#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0;
  char ch = getchar();
  bool f = false;
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - 48, ch = getchar();
  return f ? -x : x;
}
void write(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
int n, A[20][200005], B[20][200005];
long long ans = 0;
int ask(int l, int r, bool k) {
  int len = log2(r - l + 1);
  return k ? max(A[len][l], A[len][r - (1 << len) + 1])
           : min(B[len][l], B[len][r - (1 << len) + 1]);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) A[0][i] = read();
  for (int i = 1; i <= n; i++) B[0][i] = read();
  for (int i = 1; 1 << i <= n; i++) {
    int up = n - (1 << i) + 1;
    for (int j = 1; j <= up; j++)
      A[i][j] = max(A[i - 1][j], A[i - 1][j + (1 << (i - 1))]),
      B[i][j] = min(B[i - 1][j], B[i - 1][j + (1 << (i - 1))]);
  }
  for (int i = 1; i <= n; i++) {
    int l = i, r = n, mid;
    int lans, rans;
    while (l < r) {
      mid = (l + r) >> 1;
      if (ask(l, mid, 1) >= ask(l, mid, 0))
        r = mid;
      else
        l = mid + 1;
    }
    lans = l;
    l = i, r = n;
    while (l < r) {
      mid = (l + r + 1) >> 1;
      if (ask(l, mid, 1) <= ask(l, mid, 0))
        l = mid;
      else
        r = mid - 1;
    }
    rans = l;
    if (ask(i, lans, 1) != ask(i, lans, 0)) continue;
    ans += rans - lans + 1;
  }
  cout << ans;
  return 0;
}
