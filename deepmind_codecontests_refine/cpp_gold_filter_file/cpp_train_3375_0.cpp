#include <bits/stdc++.h>
using namespace std;
const int MOD = 5000000;
const double pi = acos(-1);
const double EPS = 1e-9;
const int N = 1e5 + 10;
const int M = 2e6 + 10;
long long binpowmod(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) ret = ret * a;
    a = a * a;
    b >>= 1;
  }
  return ret;
}
int n, m;
vector<int> a;
vector<vector<int> > adj;
int sTime[N], eTime[N], dfsOrder[N], cnt, qi[N], qs[N], qe[N], qk[N], ans[N], s,
    e;
void dfs(int u, int p) {
  dfsOrder[sTime[u] = cnt++] = u;
  for (int i = 0; i < (int)adj[u].size(); ++i) {
    int v = adj[u][i];
    if (v != p) dfs(v, u);
  }
  eTime[u] = cnt;
}
int BIT[N + 100];
void insert(int pos, int v) {
  for (++pos; pos <= N; pos += (pos & (-pos))) BIT[pos] += v;
}
int get(int pos) {
  int ret = 0;
  for (++pos; pos; pos -= (pos & (-pos))) ret += BIT[pos];
  return ret;
}
int freq[N];
void add(int x) {
  if (freq[x]) insert(freq[x], -1);
  freq[x]++;
  insert(freq[x], 1);
}
void rem(int x) {
  insert(freq[x], -1);
  freq[x]--;
  if (freq[x]) insert(freq[x], 1);
}
void updatese(int idx) {
  while (e < qe[idx] + 1) add(a[dfsOrder[e++]]);
  while (s > qs[idx]) add(a[dfsOrder[--s]]);
  while (s < qs[idx]) rem(a[dfsOrder[s++]]);
  while (e > qe[idx] + 1) rem(a[dfsOrder[--e]]);
}
void solve() {
  cin >> n >> m;
  a.assign(n, 0);
  for (int i = 0; i < n; ++i) cin >> a[i];
  adj.assign(n, vector<int>());
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  for (int i = 0; i < m; ++i) {
    int v, k;
    cin >> v >> k;
    v--;
    qi[i] = i;
    qs[i] = sTime[v];
    qe[i] = eTime[v] - 1;
    qk[i] = k;
  }
  int sq = sqrt(n);
  sort(qi, qi + m, [&](int x, int y) {
    return make_pair(qs[x] / sq, qe[x]) < make_pair(qs[y] / sq, qe[y]);
  });
  for (int i = 0; i < m; ++i) {
    updatese(qi[i]);
    ans[qi[i]] = get(N - 1) - get(qk[qi[i]] - 1);
  }
  for (int i = 0; i < m; ++i) cout << ans[i] << '\n';
}
int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    solve();
  }
}
