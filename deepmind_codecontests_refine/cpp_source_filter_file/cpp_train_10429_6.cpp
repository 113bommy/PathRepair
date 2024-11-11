#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool chkmin(T &x, T y) {
  return x > y ? x = y, 1 : 0;
}
template <typename T>
inline bool chkmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
template <typename T>
inline void read(T &x) {
  char ch = getchar();
  int f = 1;
  x = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  x *= f;
}
template <typename T, typename... Args>
inline void read(T &x, Args &...args) {
  read(x), read(args...);
}
int n, _k, prime[1000050], mark[1000050], phi[1000050], ptot;
void prepare() {
  for (register int i = 2; i <= n; ++i) {
    if (!mark[i]) prime[++ptot] = i, phi[i] = i - 1;
    int k;
    for (int j = 1; j <= ptot && (k = i * prime[j]) <= n; ++j) {
      mark[k] = 1;
      if (i % prime[j] == 0) {
        phi[k] = phi[i] * prime[j];
        break;
      } else
        phi[k] = phi[i] * (prime[j] - 1);
    }
  }
}
int main() {
  read(n, _k);
  if (_k == 1) return cout << 3 << endl, 0;
  prepare();
  sort(phi + 3, phi + n + 1);
  int ans = 0;
  for (register int i = 3; i <= _k + 2; ++i) ans += phi[i];
  cout << ans + 2 << endl;
  return 0;
}
