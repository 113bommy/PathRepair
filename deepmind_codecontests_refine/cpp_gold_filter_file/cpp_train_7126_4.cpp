#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = INT_MAX;
const long long LINF = LLONG_MAX;
const int maxn = 2e5 + 4;
vector<int> g_arr[maxn], t_arr[maxn];
vector<int> *g = g_arr + maxn / 2, *t = t_arr + maxn / 2;
int n, a, b, p[maxn], scc_arr[maxn], cnt;
map<int, int> mp;
stack<int> f;
int *scc = scc_arr + maxn / 2;
bool visited_arr[maxn];
bool *visited = visited_arr + maxn / 2;
void add(int x, int y) {
  g[x].push_back(y);
  t[y].push_back(x);
  g[-y].push_back(-x);
  t[-x].push_back(-y);
  g[-x].push_back(-y);
  t[-y].push_back(-x);
  g[y].push_back(x);
  t[x].push_back(y);
}
void dfs1(int v) {
  visited[v] = 1;
  for (int u : g[v])
    if (!visited[u]) dfs1(u);
  f.push(v);
}
void dfs2(int v) {
  visited[v] = 1;
  scc[v] = cnt;
  for (int u : t[v])
    if (!visited[u]) dfs2(u);
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    mp[p[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (mp.find(a - p[i]) != mp.end())
      add(i, mp[a - p[i]]);
    else {
      g[i].push_back(-i);
      t[-i].push_back(i);
    }
    if (mp.find(b - p[i]) != mp.end())
      add(i, mp[b - p[i]]);
    else {
      g[-i].push_back(i);
      t[i].push_back(-i);
    }
  }
  for (int i = -n; i <= n; i++)
    if (!visited[i]) dfs1(i);
  memset(visited_arr, 0, sizeof visited_arr);
  while (f.size()) {
    int v = f.top();
    if (!visited[v]) {
      cnt++;
      dfs2(v);
    }
    f.pop();
  }
  for (int i = 1; i <= n; i++)
    if (scc[i] == scc[-i]) return cout << "NO" << endl, 0;
  cout << "YES" << endl;
  for (int i = 1; i <= n; i++) cout << (scc[-i] < scc[i] ? 0 : 1) << ' ';
  cout << endl;
}
