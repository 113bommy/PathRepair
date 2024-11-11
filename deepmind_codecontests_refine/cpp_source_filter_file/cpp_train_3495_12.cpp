#include <bits/stdc++.h>
using namespace std;
ostream& operator<<(ostream& os, vector<int>& x) {
  for (int i = 0; i < x.size(); i++) os << x[i] << ' ';
  return os;
}
ostream& operator<<(ostream& os, pair<int, int> x) {
  cout << x.first << ' ' << x.second << ' ';
  return os;
}
ostream& operator<<(ostream& os, vector<pair<int, int> >& x) {
  for (int i = 0; i < x.size(); i++) os << x[i] << '\n';
  return os;
}
const int mod = 1e9 + 7;
int primes[1000005];
int f[1000005][31];
void eratosthene() {
  for (int i = 2; i <= 1000005 - 5; i++)
    if (primes[i] == 0)
      for (int j = i; j <= 1000005 - 5; j += i) primes[j] = i;
}
int cal(int lev, int u) {
  int ret = f[lev][u] - (u >= 1 ? f[lev][u - 1] : 0);
  ret %= mod;
  if (ret < 0) ret += mod;
  return ret;
}
int solve(int r, int X) {
  int ret = 1;
  while (X > 1) {
    int val = primes[X];
    int cnt = 0;
    while (primes[X] == val) {
      X /= val;
      cnt++;
    }
    ret = ret * 1LL * cal(r, cnt) % mod;
  }
  return ret;
}
void prep() {
  for (int i = 0; i <= 30; i++)
    f[0][i] = min(2, i + 1) + (i >= 1 ? f[0][i - 1] : 0) % mod;
  for (int lev = 1; lev <= 1000005 - 5; lev++) {
    for (int i = 0; i <= 30; i++)
      f[lev][i] = f[lev - 1][i] + (i >= 1 ? f[lev][i - 1] : 0) % mod;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  eratosthene();
  prep();
  int T;
  cin >> T;
  while (T--) {
    int r, n;
    cin >> r >> n;
    cout << solve(r, n) << '\n';
  }
}
