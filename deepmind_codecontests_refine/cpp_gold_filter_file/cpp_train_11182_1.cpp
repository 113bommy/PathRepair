#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
inline bool Min(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
inline bool Max(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
inline int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
inline ll nl() {
  ll a;
  scanf("%lld", &a);
  return a;
}
inline double nd() {
  double a;
  scanf("%lf", &a);
  return a;
}
inline void pi(int a) { printf("%d ", a); }
inline void pl(ll a) { printf("%lld ", a); }
inline void pd(double a) { printf("%.12lf ", a); }
const int N = 1e5 + 10;
int edge_len[N];
vector<pii> edges;
vector<int> gp[N];
bool used[N];
int comp[N];
int best_city[N];
ll road_length[N];
int parent[N];
void Make(int v) { parent[v] = v; }
int Find(int v) { return (parent[v] == v) ? v : parent[v] = Find(parent[v]); }
void Union(int a, int b) { parent[Find(a)] = Find(b); }
int n, m, p, q;
int components = 0;
void dfs(int v) {
  used[v] = true;
  comp[v] = components;
  for (int next : gp[v])
    if (!used[next]) dfs(next), Union(v, next);
}
void solve() {
  n = ni();
  m = ni();
  p = ni();
  q = ni();
  for (int i = 0; i < (int)(m); ++i) {
    int a = ni();
    int b = ni();
    int l = ni();
    edge_len[edges.size()] = l;
    edges.push_back({a, b});
    gp[a].push_back(b);
    gp[b].push_back(a);
  }
  for (int i = (int)(1); i <= (int)(n); ++i) Make(i);
  for (int i = (int)(1); i <= (int)(n); ++i) {
    if (!used[i]) {
      components++;
      dfs(i);
      best_city[components] = i;
    }
  }
  if (components < q or (components - p > q)) {
    cout << "NO";
    return;
  }
  for (int i = 0; i < (int)(m); ++i)
    road_length[comp[edges[i].first]] += edge_len[i];
  set<pll> xs;
  vector<pii> ans;
  for (int i = (int)(1); i <= (int)(components); ++i)
    xs.insert({road_length[i], i});
  while (xs.size() > q) {
    pll one = *xs.begin();
    xs.erase(xs.begin());
    pll two = *xs.begin();
    xs.erase(xs.begin());
    ll newLen = min(1LL * int(1e9), one.first + two.first + 1);
    ans.push_back({best_city[one.second], best_city[two.second]});
    Union(best_city[one.second], best_city[two.second]);
    road_length[one.second] = one.first + two.first + newLen;
    xs.insert(make_pair(road_length[one.second], one.second));
    p--;
  }
  map<int, int> was;
  int a = -1, b = -1;
  for (int i = (int)(1); i <= (int)(n); ++i) {
    if (was.count(comp[Find(i)])) {
      a = was[comp[Find(i)]];
      b = i;
      break;
    }
    was[comp[Find(i)]] = i;
  }
  if (p > 0 and a == -1) {
    cout << "NO";
    return;
  }
  for (int i = 0; i < (int)(p); ++i) ans.push_back({a, b});
  puts("YES");
  for (int i = 0; i < (int)(ans.size()); ++i)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
