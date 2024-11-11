#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
inline void smin(T &a, const U &b) {
  if (a > b) a = b;
}
template <typename T, typename U>
inline void smax(T &a, const U &b) {
  if (a < b) a = b;
}
template <class T>
inline void gn(T &first) {
  char c, sg = 0;
  while (c = getchar(), (c > '9' || c < '0') && c != '-')
    ;
  for ((c == '-' ? sg = 1, c = getchar() : 0), first = 0; c >= '0' && c <= '9';
       c = getchar())
    first = (first << 1) + (first << 3) + c - '0';
  if (sg) first = -first;
}
template <class T1, class T2>
inline void gn(T1 &x1, T2 &x2) {
  gn(x1), gn(x2);
}
int power(int a, int b, int m, int ans = 1) {
  for (; b; b >>= 1, a = 1LL * a * a % m)
    if (b & 1) ans = 1LL * ans * a % m;
  return ans;
}
const int mod = 1000000007;
int f[510], sz[510];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    gn(f[i]);
    if (~f[i]) sz[f[i]]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) ans = (ans + power(2, sz[i], mod) - 1) % mod;
  ans = power(2, n - 1, mod) - 1 - ans;
  if (ans < 0) ans++;
  cout << ans << endl;
  return 0;
}
