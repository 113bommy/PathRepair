#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
const long long mod = 998244353;
long long binpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = (ans * a) % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int n, m;
int a[N][N];
vector<pair<int, pair<int, int> > > cells;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x;
      scanf("%d", &x);
      a[i][j] = x;
    }
  }
  int r, c;
  scanf("%d%d", &r, &c);
  --r;
  --c;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] < a[r][c]) cells.emplace_back(a[i][j], make_pair(i, j));
    }
  }
  sort(cells.rbegin(), cells.rend());
  long long sumexpect = binpow(cells.size(), mod - 2);
  long long sumi = 2 * r * sumexpect % mod, sumj = 2 * c * sumexpect % mod,
            sumSquarei = ((sumexpect * r) % mod * r) % mod,
            sumSquarej = (sumexpect * c % mod) * c % mod;
  long long ans = 0;
  for (int i = 0; i < cells.size(); ++i) {
    int j = i;
    while (j < cells.size() && cells[j].first == cells[i].first) {
      auto p = cells[j].second;
      ans -= sumi * p.first % mod;
      ans -= sumj * p.second % mod;
      ans += mod * mod;
      ans %= mod;
      ans += sumSquarei;
      ans += sumSquarej;
      ans %= mod;
      ans += (sumexpect * p.first % mod) * p.first % mod;
      ans += (sumexpect * p.second % mod) * p.second % mod;
      ans %= mod;
      ++j;
    }
    long long newexpect = sumexpect * binpow(cells.size() - j, mod - 2);
    for (int v = i; v < j; ++v) {
      auto p = cells[v].second;
      sumi += 2 * p.first * newexpect;
      sumi %= mod;
      sumj += 2 * p.second * newexpect;
      sumj %= mod;
      sumSquarei += (newexpect * p.first % mod) * p.first % mod;
      sumSquarej += (newexpect * p.second % mod) * p.second % mod;
      sumSquarei %= mod;
      sumSquarej %= mod;
    }
    sumexpect += newexpect * (j - i) % mod;
    sumexpect %= mod;
    i = j - 1;
  }
  cout << ans;
  return 0;
}
