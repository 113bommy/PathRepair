#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > matmul(vector<vector<long long> > &a,
                                  vector<vector<long long> > &b) {
  int i, j, k, n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++) {
      long long temp = 0;
      for (k = 0; k < n; k++)
        temp = (temp + a[i][k] * b[k][j]) % (1000000007LL);
      ans[i][j] = temp;
    }
  return ans;
}
vector<vector<long long> > matpwr(vector<vector<long long> > &a, long long p) {
  int n = a.size();
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (int i = 0; i < n; i++) ans[i][i] = 1;
  while (p) {
    if (p & 1) ans = matmul(ans, a);
    a = matmul(a, a);
    p >>= 1;
  }
  return ans;
}
long long pwr(long long base, long long p, long long mod = (1000000007LL)) {
  long long ans = 1;
  while (p) {
    if (p & 1) ans = (ans * base) % mod;
    base = (base * base) % mod;
    p /= 2;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long invMod(long long n, long long mod = (1000000007LL)) {
  return pwr(n, mod - 2);
}
int n, le, he, comp[100005], state[100005];
vector<int> adj[100005], adj2[100005];
vector<pair<int, int> > hate_edges;
void bfs(int v, int c) {
  queue<int> qq;
  comp[v] = c;
  qq.push(v);
  while (!qq.empty()) {
    int v = qq.front();
    qq.pop();
    for (int i = 0; i < (int)adj[v].size(); i++) {
      int vv = adj[v][i];
      if (comp[vv] == -1) {
        comp[vv] = c;
        qq.push(vv);
      }
    }
  }
}
bool invalid;
vector<int> traversed;
void dfs(int v) {
  if (invalid) return;
  traversed.push_back(v);
  for (int i = 0; i < (int)adj[v].size(); i++) {
    int vv = adj[v][i];
    if (state[vv] == -1) {
      state[vv] = 1 - state[v];
      dfs(vv);
      continue;
    }
    if (state[vv] != state[v]) {
      invalid = true;
      return;
    }
  }
  for (int i = 0; i < (int)adj2[v].size(); i++) {
    int vv = adj2[v][i];
    if (state[vv] == -1) {
      state[vv] = 1 - state[v];
      dfs(vv);
      continue;
    }
    if (state[vv] == state[v]) {
      invalid = true;
      return;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  int e;
  cin >> n >> e;
  while (e--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1) {
      adj[a].push_back(b);
      adj[b].push_back(a);
      le++;
    } else {
      he++;
      adj2[a].push_back(b);
      adj2[b].push_back(a);
      hate_edges.push_back(pair<int, int>(a, b));
    }
  }
  memset(state, -1, sizeof(state));
  for (int i = 1; i <= n; i++)
    if (state[i] == -1) {
      invalid = false;
      state[i] = 0;
      traversed.clear();
      dfs(i);
      if (!invalid) continue;
      for (int j = 0; j < (int)traversed.size(); j++) state[traversed[j]] = -1;
      state[i] = 1;
      invalid = false;
      dfs(i);
      if (invalid) {
        cout << "0";
        return 0;
      }
    }
  int c = 0;
  memset(comp, -1, sizeof(comp));
  for (int i = 1; i <= n; i++)
    if (comp[i] == -1) bfs(i, ++c);
  for (int i = 1; i <= n; i++) adj[i].clear();
  n = c;
  for (int i = 0; i < he; i++) {
    int a = hate_edges[i].first, b = hate_edges[i].second;
    if (comp[a] == comp[b]) {
      cout << "0";
      return 0;
    }
    adj[comp[a]].push_back(comp[b]);
    adj[comp[b]].push_back(comp[a]);
  }
  c = 0;
  memset(comp, -1, sizeof(comp));
  for (int i = 1; i <= n; i++)
    if (comp[i] == -1) bfs(i, ++c);
  n = c;
  long long ans = pwr(2, n - 1) % (1000000007LL);
  cout << ans;
  return 0;
}
