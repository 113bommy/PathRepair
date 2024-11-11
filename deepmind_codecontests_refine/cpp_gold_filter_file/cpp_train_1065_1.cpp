#include <bits/stdc++.h>
using namespace std;
void err(const istream_iterator<string>& it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << '\n';
  err(++it, args...);
}
long double eps = (long double)1 / 1e6;
long long inf_ll = 1e18 + 1, mod1 = 1e9 + 7, mod2 = 998244353;
long long mersen_mod = 2305843009213693951;
long long sqr(long long a) { return a * a; }
long long qb(long long a) { return a * a * a; }
long long gcd(long long a, long long b) { return !a ? b : gcd(b % a, a); }
long long binpow(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (a * (sqr(binpow(a, b / 2, mod)) % mod)) % mod
                    : sqr(binpow(a, b / 2, mod)) % mod)
           : 1;
}
long long binmult(long long a, long long b, long long mod) {
  return b ? (b % 2 ? (2 * binmult(a, b / 2, mod) + a) % mod
                    : (2 * binmult(a, b / 2, mod)) % mod)
           : 0;
}
int id[1002][1002], ans = 1;
void dfs(int i, int j) {
  id[i][j] = ans;
  if (id[i - 1][j] == -1) dfs(i - 1, j);
  if (id[i + 1][j] == -1) dfs(i + 1, j);
  if (id[i][j - 1] == -1) dfs(i, j - 1);
  if (id[i][j + 1] == -1) dfs(i, j + 1);
}
int main() {
  cout.tie(0), cin.tie(0), ios_base::sync_with_stdio(0);
  int n, m, i, j, er = 0, ec = 0;
  bool e = 0;
  char c;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      cin >> c;
      if (c == '#')
        id[i][j] = -1;
      else
        id[i][j] = -2;
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= m; j++) {
      if (id[i][j] == -1) dfs(i, j), ans++;
    }
  }
  for (i = 1; i <= n; i++) {
    bool bl = 0;
    int k = 0;
    for (j = 1; j <= m; j++) {
      if (id[i][j] != -2) bl = 1;
      if (id[i][j] != -2 && k == 0) k = 1;
      if (id[i][j] == -2 && k == 1) k = 2;
      if (id[i][j] != -2 && k == 2) k = 3;
    }
    if (k == 3) e = 1;
    if (!bl) er++;
  }
  for (j = 1; j <= m; j++) {
    bool bl = 0;
    int k = 0;
    for (i = 1; i <= n; i++) {
      if (id[i][j] != -2) bl = 1;
      if (id[i][j] != -2 && k == 0) k = 1;
      if (id[i][j] == -2 && k == 1) k = 2;
      if (id[i][j] != -2 && k == 2) k = 3;
    }
    if (k == 3) e = 1;
    if (!bl) ec++;
  }
  if ((er && !ec) || (!er && ec)) e = 1;
  cout << (e ? -1 : --ans);
  return 0;
}
