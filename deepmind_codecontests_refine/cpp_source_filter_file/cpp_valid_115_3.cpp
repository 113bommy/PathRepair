#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 1) + (x << 3) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
inline void Prin(long long x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) Prin(x / 10);
  putchar(x % 10 + '0');
}
const long long mod = 998244353;
const int qs = 1e6 + 7;
map<pair<int, int>, int> mp;
long long f[qs];
int n, m, k;
struct node {
  int c[3], s[qs][2];
  void erase(int x, int y, int z) {
    c[(!s[x][0]) + (!s[x][1])] -= 1;
    s[x][(y ^ z) & 1] -= 1;
    c[(!s[x][0]) + (!s[x][1])] += 1;
  }
  void add(int x, int y, int z) {
    c[(!s[x][0]) + (!s[x][1])] -= 1;
    s[x][(y ^ z) & 1] += 1;
    c[(!s[x][0]) + (!s[x][1])] += 1;
  }
  long long ans() { return c[0] ? 0 : f[c[2]]; }
  void init(int nm) { c[2] = nm; }
} R, C;
int main() {
  n = read(), m = read(), k = read();
  f[0] = 1;
  for (int i = 1; i <= n; ++i) f[i] = f[i - 1] * 2 % mod;
  R.init(n);
  C.init(m);
  int c[2] = {0};
  for (int i = 1; i <= k; ++i) {
    int x, y, z;
    x = read(), y = read(), z = read();
    if (mp.count({x, y})) {
      c[(x ^ y ^ mp[{x, y}]) & 1]--;
      R.erase(x, y, mp[{x, y}]);
      C.erase(y, x, mp[{x, y}]);
      mp.erase({x, y});
    }
    if (z != -1) {
      c[(x ^ y ^ z) & 1]++;
      R.add(x, y, z);
      C.add(y, x, z);
      mp[{x, y}] = z;
    }
    long long ans = R.ans() + C.ans() + mod - (!c[0]) - (!c[1]);
    ans %= mod;
    Prin(ans);
    puts("");
  }
  return 0;
}
