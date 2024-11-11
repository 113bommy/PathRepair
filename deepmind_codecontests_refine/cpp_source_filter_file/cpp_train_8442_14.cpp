#include <bits/stdc++.h>
const int N = 100005, mod = 1000000007;
void up(int &x, int y, int z) { x = (x + (long long)y * z) % mod; }
int pow(int x, int y, int ans = 1) {
  for (; y; y >>= 1, x = (long long)x * x % mod)
    if (y & 1) ans = (long long)ans * x % mod;
  return ans;
}
int factor[N], ifactor[N];
void init(int n) {
  factor[0] = 1;
  for (int i = 1; i <= n; ++i) factor[i] = (long long)factor[i - 1] * i % mod;
  ifactor[n] = pow(factor[n], mod - 2);
  for (int i = n; i; --i) ifactor[i - 1] = (long long)ifactor[i] * i % mod;
}
int C(int x, int y) {
  if (x == y) return 1;
  if (x < 0 || y < 0 || x < y) return 0;
  return (long long)factor[x] * ifactor[y] % mod * ifactor[x - y] % mod;
}
int calc(int x, int y) { return C(x + y - 1, y - 1); }
int c[2][2], d[2][2], la, lb;
char a[N], b[N];
int solve(char *a, int la) {
  int l = c[0][0] + c[0][1] + c[1][0] + c[1][1] + 1;
  if (l > la) return 0;
  if (l < la)
    return (long long)calc(c[1][1], c[0][1] + 1) * calc(c[0][0], c[1][0]) % mod;
  d[0][0] = c[0][0], d[0][1] = c[0][1];
  d[1][0] = c[1][0], d[1][1] = c[1][1];
  int ret = 0;
  for (int i = la - 2; ~i; --i) {
    if (a[i]) {
      if (--d[a[i + 1]][0] >= 0)
        up(ret, calc(d[1][1], d[0][1]), calc(d[0][0], d[1][0] + 1));
      ++d[a[i + 1]][0];
    }
    if (--d[a[i + 1]][a[i]] < 0) break;
  }
  return ret;
}
int main() {
  std::ios::sync_with_stdio(0), std::cin.tie(0);
  std::cin >> a >> b, init(100000);
  la = std::strlen(a), lb = std::strlen(b);
  std::reverse(a, a + la), std::reverse(b, b + lb);
  for (int i = 0; i < la; ++i) a[i] -= '0';
  for (int i = 0; i < lb; ++i) b[i] -= '0';
  for (int i = 0; b[i] ^= 1; ++i)
    ;
  if (b[lb]) ++lb;
  std::cin >> c[0][0] >> c[0][1] >> c[1][0] >> c[1][1];
  if (c[1][0] != c[0][1] && c[1][0] != c[0][1] + 1)
    return std::cout << "0\n", 0;
  std::cout << (solve(b, lb) - solve(a, la) + mod) % mod << '\n';
  return 0;
}
