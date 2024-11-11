#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
class CMP {
 public:
  bool operator()(long long int a, long long int b) { return !(a <= b); }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  map<long long int, long long int>::iterator jt;
  jt = m.find(x);
  if (jt == m.end())
    m.insert(make_pair(x, cnt));
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  map<long long int, long long int>::iterator jt;
  jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
const long long int mod = 1000000007L;
long long int T, n, i, j, k, in, cnt, l, r, u, v;
long long int m;
string s;
vector<long long int> a[250005];
long long int p[250005];
long long int d[250005];
long long int bst, lf;
vector<long long int> b;
vector<long long int>::iterator it;
void dfs(long long int u, long long int pa = -1, long long int dis = 1) {
  if (p[u]) return;
  p[u] = pa;
  d[u] = dis;
  long long int cnt = 0;
  if (bst < dis) {
    bst = dis;
    lf = u;
  }
  for (auto x : a[u]) {
    if (x == pa) continue;
    if (p[x]) continue;
    dfs(x, u, dis + 1);
    cnt++;
  }
  if (!cnt) b.push_back(u);
}
void PATH() {
  cout << "PATH"
       << "\n";
  cout << bst << "\n";
  u = lf;
  while (u != -1) {
    cout << u << " ";
    u = p[u];
  }
}
long long int dis(long long int u, long long int v) { return abs(d[u] - d[v]); }
void prt(long long int u, long long int v, long long int x = -1) {
  if (d[u] < d[v]) swap(u, v);
  if (x != -1) {
    cout << 2 + dis(u, v) << "\n";
    cout << x << " ";
  } else {
    cout << 1 + dis(u, v) << "\n";
  }
  while (v != u) {
    cout << v << " ";
    v = p[v];
  }
  cout << u << "\n";
}
void rep(long long int v) {
  long long int x = -1, y = -1;
  for (auto z : a[v]) {
    if (z == p[v]) continue;
    if (x == -1)
      x = z;
    else if (y == -1)
      y = z;
    else
      break;
  }
  if ((dis(x, v) + 1) % 3)
    prt(x, v);
  else if ((dis(y, v) + 1) % 3)
    prt(y, v);
  else
    prt(x, y, v);
}
void CYCLE() {
  cout << "CYCLES"
       << "\n";
  long long int i = 0;
  for (auto x : b) {
    if (i == k) break;
    i++;
    rep(x);
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n >> m >> k;
    for (i = 0; i < (m); ++i) {
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    dfs(1);
    if (bst >= k)
      PATH();
    else
      CYCLE();
  }
  aryanc403();
  return 0;
}
