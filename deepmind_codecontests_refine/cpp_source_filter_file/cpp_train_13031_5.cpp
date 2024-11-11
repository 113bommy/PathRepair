#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
bool sortinrev(const pair<int, int>& a, const pair<int, int>& b) {
  if (a.first == b.first) return b.second > a.second;
  return a.first > b.first;
}
void run(vector<int> v) {
  for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << endl;
}
int modInverse(long long int a, long long int m) {
  long long int m0 = m;
  long long int y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1) {
    long long int q = a / m;
    long long int t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
void numberOfNodes(int n, vector<long long int> adj[],
                   vector<long long int>& count1, int s, int e) {
  vector<long long int>::iterator u;
  count1[s] = 1;
  for (u = adj[s].begin(); u != adj[s].end(); u++) {
    if (*u == e) continue;
    numberOfNodes(n, adj, count1, *u, s);
    count1[s] += count1[*u];
  }
}
void solve() {
  int n, k, unhappy = 0;
  cin >> n >> k;
  vector<pair<int, int>> edges;
  vector<int> adj[n + 1];
  unordered_map<int, int> mp[n + 1];
  vector<bool> vis(n + 1, 0);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (mp[x].find(y) == mp[x].end()) {
      mp[x][y]++;
      mp[y][x]++;
      edges.push_back({x, y});
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
  }
  unhappy += (k - edges.size());
  k -= unhappy;
  queue<int> q;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      q.push(i);
      vector<int> vec;
      vis[i] = 1;
      vec.push_back(i);
      while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int j = 0; j < adj[p].size(); j++) {
          if (!vis[adj[p][j]]) {
            vec.push_back(adj[p][j]);
            vis[adj[p][j]] = 1;
            q.push(adj[p][j]);
          }
        }
      }
      ans += (vec.size() - 1);
    }
  }
  cout << unhappy + k - ans << endl;
}
int main() {
  int t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
