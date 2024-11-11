#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
const int N = 2e5 + 5, inf = 0x3f3f3f3f;
int n, L, a[N << 1], b[N << 2];
inline bool check(int x) {
  int mx = -inf, j1 = 1, j2 = 1;
  for (int i = (1); i <= (2 * n); ++i) {
    while (j1 <= 4 * n && b[j1] < a[i] - x) j1++;
    while (j2 <= 4 * n && b[j2] <= a[i] + x) j2++;
    mx = max(mx, j1 - i);
    if (j2 - i - 1 < mx) return 0;
  }
  return 1;
}
int main() {
  n = read(), L = read();
  for (int i = (1); i <= (n); ++i) a[i] = read();
  sort(a + 1, a + n + 1);
  for (int i = (1); i <= (n); ++i) b[i] = read();
  sort(b + 1, b + n + 1);
  for (int i = (1); i <= (n); ++i) a[i] += L, a[i + n] = a[i] + L;
  for (int i = (1); i <= (3 * n); ++i) b[i + n] = b[i] + L;
  int l = 0, r = L / 2;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  cout << l << endl;
  return 0;
}
