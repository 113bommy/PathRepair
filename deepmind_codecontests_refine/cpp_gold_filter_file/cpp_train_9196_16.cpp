#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, k, h[maxn];
string s1, s2;
queue<int> q;
vector<int> adj[maxn];
bool mark[maxn];
void bfs(int st) {
  q.push(st);
  mark[st] = true;
  while (!q.empty()) {
    int u = q.front();
    for (auto v : adj[u])
      if (!mark[v]) {
        h[v] = h[u] + 1;
        if (h[v] > (v >= n ? v - n + 1 : v + 1)) h[v] = 1000000000;
        mark[v] = true;
        q.push(v);
      }
    q.pop();
  }
}
void build_adj() {
  for (int i = 0; i < n; i++) {
    if (i - 1 >= 0)
      if (s1[i - 1] == '-') adj[i].push_back(i - 1);
    if (i + 1 < n)
      if (s1[i + 1] == '-') adj[i].push_back(i + 1);
    if (i + k < n)
      if (s2[i + k] == '-') adj[i].push_back(i + n + k);
    if (i - k >= 0)
      if (s2[i - k] == '-') adj[i].push_back(i + n - k);
  }
  for (int i = 0; i < n; i++) {
    if (i - 1 >= 0)
      if (s2[i - 1] == '-') adj[i + n].push_back(i + n - 1);
    if (i + 1 < n)
      if (s2[i + 1] == '-') adj[i + n].push_back(i + n + 1);
    if (i + k < n)
      if (s1[i + k] == '-') adj[i + n].push_back(i + k);
    if (i - k >= 0)
      if (s1[i - k] == '-') adj[i + n].push_back(i - k);
  }
}
void read_input() {
  memset(h, 63, sizeof h);
  cin >> n >> k;
  cin >> s1 >> s2;
}
void solve() {
  build_adj();
  h[0] = 1;
  bfs(0);
  bool check = false;
  for (int i = n - k; i < n; i++)
    if (h[i] <= i + 1 && s1[i] == '-') check = true;
  for (int i = 2 * n - k; i < 2 * n; i++)
    if (h[i] <= i - n + 1 && s2[i - n] == '-') check = true;
  cout << (!check ? "NO" : "YES");
}
int main() {
  read_input(), solve();
  return 0;
}
