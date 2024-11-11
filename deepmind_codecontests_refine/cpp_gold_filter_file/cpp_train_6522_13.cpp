#include <bits/stdc++.h>
const int N = 100050;
int a[N], n, d, b;
int s[N];
inline int getl(int i) { return (i + d) / (d + 1); }
inline int getr(int i) { return (i + (long long)(n + 1) * d) / (d + 1); }
bool check(int m) {
  int L = m + 1, R = n - m;
  for (int i = L; i <= R; ++i) s[i] = 0;
  int j = L;
  for (int i = 1; i <= n && j <= R; ++i) {
    int l = getl(i), r = getr(i);
    if (l > R || L > r) continue;
    int ai = a[i];
    if (j < l) return false;
    while (ai && j <= R && j <= r) {
      int t = std::min(ai, b - s[j]);
      ai -= t;
      if ((s[j] += t) == b) ++j;
    }
  }
  for (int i = L; i <= R; ++i)
    if (s[i] < b) return false;
  return true;
}
int main() {
  scanf("%d%d%d", &n, &d, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  int l = 0, r = n / 2;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid + 1;
  }
  printf("%d\n", l);
  return 0;
}
