#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000;
const int MAXH = 20;
const long long int INF = 100000000000000LL;
struct EDGE {
  long long int w, c;
  int first, second, ind;
  EDGE() {}
};
EDGE e[MAXN];
bool operator<(EDGE a, EDGE b) { return a.w < b.w; }
struct UFS {
  int fa[MAXN];
  void init(int n) {
    for (int i = 0; i <= n; ++i) fa[i] = i;
  }
  int root(int x) { return fa[x] = (fa[x] == x) ? x : root(fa[x]); }
  bool same(int a, int b) { return root(a) == root(b); }
  void uni(int a, int b) { fa[root(a)] = root(b); }
};
UFS ufs;
struct NODE {
  int first, second, ind;
  NODE() {}
  NODE(int first, int second, int ind)
      : first(first), second(second), ind(ind) {}
};
struct SPARSETABLE {
  int dep[MAXN];
  int anc[MAXN][MAXH];
  int ind[MAXN][MAXH];
  long long int dpm[MAXN][MAXH];
  void build(int n, vector<NODE> G[]) {
    memset(dep, 0, sizeof(dep));
    dep[1] = 1;
    dpm[1][0] = -INF;
    anc[1][0] = 1;
    ind[1][0] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      for (auto k : G[now]) {
        int v = k.first;
        if (dep[v]) continue;
        dep[v] = dep[now] + 1;
        anc[v][0] = now;
        dpm[v][0] = k.second;
        ind[v][0] = k.ind;
        q.push(k.first);
      }
    }
    for (int i = 1; i < MAXH; ++i) {
      for (int j = 1; j <= n; ++j) {
        anc[j][i] = anc[anc[j][i - 1]][i - 1];
        if (dpm[anc[j][i - 1]][i - 1] > dpm[j][i - 1]) {
          dpm[j][i] = dpm[anc[j][i - 1]][i - 1];
          ind[j][i] = ind[anc[j][i - 1]][i - 1];
        } else {
          dpm[j][i] = dpm[j][i - 1];
          ind[j][i] = ind[j][i - 1];
        }
      }
    }
  }
  pair<long long int, int> querymax(int a, int b) {
    if (dep[b] > dep[a]) swap(a, b);
    long long int maxi = -INF;
    int ansind = 0;
    int diff = dep[a] - dep[b];
    for (int i = 0; i < MAXH; ++i) {
      if ((diff >> i) & 1) {
        if (dpm[a][i] > maxi) {
          maxi = dpm[a][i];
          ansind = ind[a][i];
        }
        a = anc[a][i];
      }
    }
    for (int i = MAXH - 1; i >= 0; --i) {
      if (anc[a][i] != anc[b][i]) {
        if (dpm[a][i] > maxi) {
          maxi = dpm[a][i];
          ansind = ind[a][i];
        }
        if (dpm[b][i] > maxi) {
          maxi = dpm[b][i];
          ansind = ind[b][i];
        }
        a = anc[a][i];
        b = anc[b][i];
      }
    }
    if (a != b) {
      if (dpm[a][0] > maxi) {
        maxi = dpm[a][0];
        ansind = ind[a][0];
      }
      if (dpm[b][0] > maxi) {
        maxi = dpm[b][0];
        ansind = ind[b][0];
      }
    }
    return make_pair(maxi, ansind);
  }
};
SPARSETABLE sp;
int n, m;
vector<NODE> G[MAXN];
long long int S;
int main(void) {
  long long int totalcost = 0;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) cin >> e[i].w;
  for (int i = 0; i < m; ++i) cin >> e[i].c;
  for (int i = 0; i < m; ++i) cin >> e[i].first >> e[i].second;
  for (int i = 0; i < m; ++i) e[i].ind = i;
  cin >> S;
  sort(e, e + m);
  ufs.init(n);
  vector<pair<int, long long int> > vec;
  for (int i = 0; i < m; ++i) {
    int u = e[i].first, v = e[i].second;
    if (ufs.same(u, v)) continue;
    ufs.uni(u, v);
    G[u].push_back(NODE(v, e[i].w, e[i].ind));
    G[v].push_back(NODE(u, e[i].w, e[i].ind));
    vec.push_back(make_pair(e[i].ind, e[i].w));
    totalcost += e[i].w;
  }
  sort(e, e + m, [](EDGE a, EDGE b) { return a.ind < b.ind; });
  long long int mini = totalcost;
  int det = 0, add = 0;
  sp.build(n, G);
  for (int i = 0; i < m; ++i) {
    pair<long long int, int> tmp = sp.querymax(e[i].first, e[i].second);
    if (totalcost - tmp.first + e[i].w - S / e[i].c < mini) {
      mini = totalcost - tmp.first + e[i].w - S / e[i].c;
      det = tmp.second;
      add = i;
    }
  }
  cout << mini << endl;
  for (int i = 0; i < (int)vec.size(); ++i) {
    if (vec[i].first == det) {
      swap(vec[i], vec.back());
      vec.pop_back();
      break;
    }
  }
  vec.push_back(make_pair(add, e[add].w - S / e[add].c));
  for (auto zz : vec) {
    cout << zz.first + 1 << ' ' << zz.second << endl;
  }
  return 0;
}
