#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;
int n, s, subtree[N], deg[N], par[N];
vector<int> adj[N];
bool mark[N];
void read_input() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a) {
      a--;
      adj[i].push_back(a);
      adj[a].push_back(i);
      deg[a]++, deg[i]++;
    }
  }
}
void dstr(int v) {
  if (!mark[v]) {
    cout << v + 1 << '\n';
    mark[v] = true;
  }
  for (int q : adj[v])
    if (!mark[q] && q != par[v]) dstr(q);
}
void dfs(int s) {
  subtree[s] = 1;
  for (int u : adj[s])
    if (u != par[s]) {
      par[u] = s;
      dfs(u);
      subtree[s] += subtree[u];
    }
  if (!(subtree[s] % 2)) dstr(s);
}
void solve() {
  if (n % 2 == 0) {
    cout << "NO";
    exit(0);
  }
  for (int i = 0; i < n; i++)
    if (deg[i] == 1) s = i;
  cout << "YES\n";
  if (n == 1)
    cout << 1;
  else {
    par[s] = -1;
    dfs(s);
  }
  cout << s + 1;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read_input();
  solve();
}
