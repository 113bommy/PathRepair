#include <bits/stdc++.h>
using namespace std;
template <class C>
void mini(C &a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C &a4, C b4) {
  a4 = max(a4, b4);
}
template <class TH>
void _dbg(const char *sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, a...);
}
template <class T>
ostream &operator<<(ostream &os, vector<T> V) {
  os << "[";
  for (auto v : V) os << v << ",";
  os << ']';
  return os;
}
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> P) {
  return os << "(" << P.first << ", " << P.second << ")";
}
struct Rozw {
  long long n, m, s, t;
  vector<vector<long long>> d;
  vector<pair<long long, long long>> res;
  vector<long long> low, po, typ, par;
  long long io = 0;
  bool xx = 0;
  void dfs_low(long long nr, long long oj) {
    if (po[nr] != -1) return;
    par[nr] = oj;
    po[nr] = low[nr] = io;
    io++;
    for (long long ak : d[nr]) {
      if (ak != oj) {
        dfs_low(ak, nr);
      }
    }
    for (long long ak : d[nr]) {
      if (ak != oj) {
        mini(low[nr], low[ak]);
      }
    }
    if (oj != -1 && low[nr] >= po[oj] && nr != s) xx = 1;
  }
  void licz(long long nr) {
    typ[po[par[nr]]] = !typ[low[nr]];
    for (long long ak : d[nr]) {
      if (po[ak] < po[nr]) {
        if (typ[po[ak]]) {
          res.push_back({nr, ak});
        } else {
          res.push_back({ak, nr});
        }
      } else if (par[ak] == nr) {
        licz(ak);
      }
    }
  }
  void go() {
    cin >> n >> m >> s >> t;
    s--;
    t--;
    d.resize(n);
    low.resize(n);
    po.resize(n, -1);
    par.resize(n);
    typ.resize(n);
    d[t].push_back(s);
    for (long long i = (0); i <= ((long long)(m)-1); i++) {
      long long a, b;
      cin >> a >> b;
      a--;
      b--;
      if ((a == s && b == t) || (a == t && b == s)) {
        res.push_back({s, t});
      } else {
        d[a].push_back(b);
        d[b].push_back(a);
      }
    }
    dfs_low(t, -1);
    if (xx) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      licz(s);
      for (pair<long long, long long> el : res) {
        cout << el.first + 1 << " " << el.second + 1 << "\n";
      }
    }
  }
};
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(11);
  if (0) cout << fixed << setprecision(6);
  long long t;
  cin >> t;
  while (t--) {
    Rozw rozw;
    rozw.go();
  }
}
