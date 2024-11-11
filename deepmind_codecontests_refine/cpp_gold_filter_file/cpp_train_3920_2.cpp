#include <bits/stdc++.h>
#pragma GCC optimize("-O2")
using namespace std;
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\t";
  err(++it, args...);
}
template <typename T1, typename T2>
ostream& operator<<(ostream& c, pair<T1, T2>& v) {
  c << "(" << v.first << "," << v.second << ")";
  return c;
}
template <template <class...> class TT, class... T>
ostream& operator<<(ostream& out, TT<T...>& c) {
  out << "{ ";
  for (auto& x : c) out << x << " ";
  out << "}";
  return out;
}
const int LIM = 1e5 + 5, MOD = 1e9 + 9;
int t, n, m, k, x, y;
struct dsu {
  vector<int> par, rk;
  void reset(int n) {
    par.resize(n), rk.assign(n, 0);
    iota(par.begin(), par.end(), 0);
  }
  int getpar(int i) { return (par[i] == i) ? i : (par[i] = getpar(par[i])); }
  bool join(int i, int j) {
    i = getpar(i), j = getpar(j);
    if (i == j) return 0;
    if (rk[i] > rk[j])
      par[j] = i;
    else {
      par[i] = j;
      if (rk[i] == rk[j]) rk[j]++;
    }
    return 1;
  }
} d;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  d.reset(n);
  int ans = 1;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    --x, --y;
    if (!d.join(x, y)) ans = ans * 2 % MOD;
    cout << (MOD - 1 + ans) % MOD << '\n';
  }
  return 0;
}
