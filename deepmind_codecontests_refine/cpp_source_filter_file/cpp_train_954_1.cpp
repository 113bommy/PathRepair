#include <bits/stdc++.h>
using namespace std;
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') {
    cerr << *sdbg++;
  }
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
  bool operator<(const Triple& t) const {
    if (first != t.first) return first < t.first;
    if (second != t.second) return second < t.second;
    return third < t.third;
  }
};
template <class T>
void ResizeVec(T&, vector<long long>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<long long> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
template <class A, class B, class C>
ostream& operator<<(ostream& out, Triple<A, B, C> t) {
  return out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class T>
ostream& operator<<(ostream& out, set<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
template <class L, class R>
ostream& operator<<(ostream& out, map<L, R> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
struct LCA {
  LCA(const vector<vector<long long> >& their_slo, long long root = 1) {
    M = 1;
    while (M <= 2 * ((long long)(their_slo).size())) {
      M *= 2;
    }
    my_slo.resize(M);
    for (long long i = 0; i < (((long long)(their_slo).size())); ++i) {
      for (auto nei : their_slo[i]) {
        my_slo[i].push_back(nei);
      }
    }
    drz.resize(2 * M + 5);
    pre.resize(M);
    inv.resize(M);
    vis.resize(M);
    ind.resize(M);
    dep.resize(M);
    d = 1;
    akt = 1;
    dfs(root);
    for (long long i = M - 1; i >= 1; i--) {
      drz[i] = min(drz[2 * i], drz[2 * i + 1]);
    }
  }
  long long M;
  vector<long long> drz;
  vector<long long> pre;
  vector<long long> inv;
  vector<long long> vis;
  vector<long long> ind;
  vector<long long> dep;
  vector<vector<long long> > my_slo;
  long long d;
  long long akt;
  long long Lca(long long a, long long b) {
    a = pre[a];
    b = pre[b];
    long long w;
    w = czyt(min(ind[a], ind[b]), max(ind[a], ind[b]));
    return inv[w];
  }
  long long Dis(long long a, long long b) {
    return dep[a] + dep[b] - 2 * dep[Lca(a, b)];
  }

 private:
  long long czyt(long long a, long long b) {
    a += M - 1;
    b += M - 1;
    long long mini = M;
    mini = min(mini, drz[a]);
    mini = min(mini, drz[b]);
    while (a / 2 != b / 2) {
      if (a % 2 == 0) {
        mini = min(mini, drz[a + 1]);
      }
      if (b % 2 == 1) {
        mini = min(mini, drz[b - 1]);
      }
      a /= 2;
      b /= 2;
    }
    return mini;
  }
  void dfs(long long v) {
    vis[v] = 1;
    pre[v] = d;
    inv[d] = v;
    d++;
    drz[akt + M - 1] = pre[v];
    ind[pre[v]] = akt;
    akt++;
    for (long long nei : my_slo[v]) {
      if (vis[nei]) {
        continue;
      }
      dep[nei] = dep[v] + 1;
      dfs(nei);
      drz[akt + M - 1] = pre[v];
      ind[pre[v]] = akt;
      akt++;
    }
  }
};
const long long N = 2e5 + 5;
long long dep[N];
long long hei[N];
long long par[N];
long long vis[N];
vector<vector<long long> > slo;
long long furthest;
long long dis0[N], dis1[N], dis2[N];
void Dfs(long long v) {
  vis[v] = 1;
  if (dis0[v] > dis0[furthest]) {
    furthest = v;
  }
  hei[v] = 0;
  for (auto nei : slo[v]) {
    if (vis[nei]) {
      continue;
    }
    dis0[nei] = dis0[v] + 1;
    par[nei] = v;
    Dfs(nei);
    maxi(hei[v], hei[nei] + 1);
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  if (0) cout << fixed << setprecision(10);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  slo.resize(n + 2);
  for (long long i = (1); i <= (n - 1); ++i) {
    long long a, b;
    cin >> a >> b;
    slo[a].push_back(b);
    slo[b].push_back(a);
  }
  LCA lca(slo);
  Dfs(1);
  long long e1 = furthest;
  for (long long i = (1); i <= (n); ++i) {
    vis[i] = 0;
    dis0[i] = 0;
  }
  Dfs(e1);
  for (long long i = (1); i <= (n); ++i) {
    vis[i] = 0;
    dis1[i] = dis0[i];
    dis0[i] = 0;
  }
  long long e2 = furthest;
  Dfs(e2);
  for (long long i = (1); i <= (n); ++i) {
    dis2[i] = dis0[i];
    vis[i] = 0;
    dis0[i] = 0;
  }
  Dfs(e1);
  long long diam = dis1[e2];
  if (k == 2 || diam < k - 1) {
    cout << "Yes\n";
    for (long long i = (1); i <= (n); ++i) {
      cout << 1 + (dis1[i] % 2) << " ";
    }
    cout << endl;
    return 0;
  }
  vector<long long> res(n + 2);
  for (long long i = (1); i <= (n); ++i) {
    long long is_on_diam = ((dis1[i] + dis2[i]) == diam);
    vector<long long> sons;
    for (auto son : slo[i]) {
      if (par[i] == son) {
        continue;
      }
      sons.push_back(hei[son] + 1);
    }
    sort((sons).begin(), (sons).end(), greater<long long>());
    long long third = 0;
    if (((long long)(sons).size()) <= is_on_diam) {
      third = 0;
    } else {
      third = sons[is_on_diam];
    }
    if (is_on_diam && min(dis1[i], dis2[i]) + 1 >= k) {
      cout << "No\n";
      return 0;
    }
    long long to_diam = (dis1[i] + dis2[i] - diam) / 2;
    if (dis2[i] <= dis1[i]) {
      res[i] = dis1[i] % k;
    } else {
      res[i] = (dis1[i] - 2 * to_diam) % k;
    }
  }
  cout << "Yes\n";
  for (long long i = (1); i <= (n); ++i) {
    cout << res[i] + 1 << " ";
  }
  cout << endl;
  return 0;
}
