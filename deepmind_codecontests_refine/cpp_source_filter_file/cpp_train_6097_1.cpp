#include <bits/stdc++.h>
using namespace std;
int fastio() {
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  cin.tie(nullptr);
  return 0;
}
int __fastio = fastio();
template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  string sep = "{";
  for (auto e : v) os << sep << e, sep = ", ";
  return os << "}";
}
template <typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  os << '(' << p.first << ", " << p.second << ')';
  return os;
}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
class DSU {
  vector<int> par;

 public:
  DSU(int size) {
    par = vector<int>(size);
    for (int i = 0; i < size; ++i) {
      par[i] = i;
    }
  }
  int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
  }
  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
      par[a] = b;
      return true;
    }
    return false;
  }
};
const int MAXN = 200100;
const int MAXH = 18;
vector<pair<int, pair<int, int> > > ed[MAXN];
pair<int, pair<int, int> > jumppar[MAXN][MAXH];
int depth[MAXN];
void dfs(int cur, pair<int, pair<int, int> > prv = pair<int, pair<int, int> >(),
         int d = 0) {
  jumppar[cur][0] = prv;
  depth[cur] = d;
  for (auto p : ed[cur]) {
    if (p.first == prv.first) continue;
    dfs(p.first, pair<int, pair<int, int> >(cur, p.second), d + 1);
  }
}
pair<int, int> maxpath(int a, int b) {
  pair<int, int> ret;
  if (depth[a] > depth[b]) swap(a, b);
  int diff = depth[b] - depth[a];
  for (int i = 0; i < MAXH; ++i) {
    if ((diff >> i) & 1) {
      ret = max(ret, jumppar[b][i].second);
      b = jumppar[b][i].first;
    }
  }
  for (int i = MAXH - 1; i >= 0; --i) {
    if (jumppar[a][i].first != jumppar[b][i].first) {
      ret = max(ret, jumppar[b][i].second);
      b = jumppar[b][i].first;
      ret = max(ret, jumppar[a][i].second);
      a = jumppar[b][i].first;
    }
  }
  if (a != b) {
    ret = max(ret, jumppar[b][0].second);
    b = jumppar[b][0].first;
    ret = max(ret, jumppar[a][0].second);
    a = jumppar[b][0].first;
  }
  return ret;
}
bool inmst[MAXN];
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<pair<pair<int, int>, pair<int, int> >, int> > edges(m);
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first.first.first;
  }
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first.first.second;
  }
  for (int i = 0; i < m; ++i) {
    cin >> edges[i].first.second.first >> edges[i].first.second.second;
    edges[i].second = i + 1;
  }
  int S;
  cin >> S;
  sort(edges.begin(), edges.end());
  DSU dsu(n + 1);
  long long mstcost = 0;
  for (int i = 0; i < m; ++i) {
    int a = edges[i].first.second.first;
    int b = edges[i].first.second.second;
    int w = edges[i].first.first.first;
    if (dsu.join(a, b)) {
      ;
      mstcost += w;
      ed[a].push_back(pair<int, pair<int, int> >(b, pair<int, int>(w, i)));
      ed[b].push_back(pair<int, pair<int, int> >(a, pair<int, int>(w, i)));
      inmst[i] = true;
    }
  }
  dfs(1);
  for (int h = 0; h + 1 < MAXH; ++h) {
    for (int i = 1; i <= n; ++i) {
      jumppar[i][h + 1] = pair<int, pair<int, int> >(
          jumppar[jumppar[i][h].first][h].first,
          max(jumppar[i][h].second, jumppar[jumppar[i][h].first][h].second));
    }
  };
  long long ans = mstcost + 1;
  int ansi = -1;
  for (int i = 0; i < m; ++i) {
    int a = edges[i].first.second.first;
    int b = edges[i].first.second.second;
    pair<int, int> maxp = maxpath(a, b);
    long long curcost =
        edges[i].first.first.first - (S / edges[i].first.first.second);
    long long cand = mstcost - maxp.first + curcost;
    if (cand < ans) {
      ans = cand;
      ansi = i;
    }
  }
  cout << ans << "\n";
  int a = edges[ansi].first.second.first;
  int b = edges[ansi].first.second.second;
  pair<int, int> maxp = maxpath(a, b);
  for (int i = 0; i < m; ++i) {
    if (i == ansi) {
      cout << edges[i].second << " "
           << edges[i].first.first.first - (S / edges[i].first.first.second)
           << "\n";
    } else if (inmst[i]) {
      if (maxp.second == i) continue;
      cout << edges[i].second << " " << edges[i].first.first.first << "\n";
    }
  }
}
