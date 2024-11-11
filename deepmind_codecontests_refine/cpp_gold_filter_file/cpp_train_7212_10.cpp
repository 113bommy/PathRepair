#include <bits/stdc++.h>
int n, k;
long long ans = 0, f[3005];
std::vector<long long> a[3005];
inline int read() {
  register int x = 0, f = 1;
  register char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
inline int min(const int &x, const int &y) { return x < y ? x : y; }
inline long long max(const long long &x, const long long &y) {
  return x > y ? x : y;
}
inline void update(int v, long long w) {
  for (register int j = k; j >= v; --j) f[j] = max(f[j], f[j - v] + w);
}
inline void solve(int l, int r) {
  if (l == r) {
    for (register int i = 0; i <= min(a[l].size() - 1, k); ++i)
      ans = max(ans, f[k - i] + a[l][i]);
    return;
  }
  int mid = l + r >> 1;
  std::vector<long long> tmp;
  for (register int i = 0; i <= k; ++i) tmp.push_back(f[i]);
  for (register int i = mid + 1; i <= r; ++i)
    update(a[i].size() - 1, a[i][a[i].size() - 1]);
  solve(l, mid);
  for (register int i = 0; i <= k; ++i) f[i] = tmp[i];
  for (register int i = l; i <= mid; ++i)
    update(a[i].size() - 1, a[i][a[i].size() - 1]);
  solve(mid + 1, r);
  for (register int i = 0; i <= k; ++i) f[i] = tmp[i];
}
int main() {
  n = read();
  k = read();
  for (register int i = 1; i <= n; ++i) {
    int m = read();
    a[i].push_back(0);
    for (register int j = 1; j <= m; ++j) {
      a[i].push_back(a[i][j - 1] + read());
    }
  }
  solve(1, n);
  printf("%lld\n", ans);
  return 0;
}
