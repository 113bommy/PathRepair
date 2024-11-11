#include <bits/stdc++.h>
using namespace std;
const int inf = 1e7;
const long long MOD = 1e9 + 7;
const long long mod = 998244353;
const int MAX_N = 1e5 + 5;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
vector<int> adj[1005];
int tsz[1005];
bool ga[1005];
void dfs(int u, int v = -1) {
  tsz[u] = 1;
  if (adj[u].size() == 1) ga[u] = true;
  for (auto xd : adj[u]) {
    if (xd == v) continue;
    dfs(xd, u);
    tsz[u] += tsz[xd];
  }
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    for (int i = 0; i < 1005; i++) {
      adj[i].clear();
      tsz[i] = 0;
    }
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    dfs(x);
    if (adj[x].size() == 1) {
      cout << "Ayush" << endl;
      continue;
    }
    long long p = tsz[x] - 1;
    if (p % 2 == 0)
      cout << "Ashish" << endl;
    else
      cout << "Ayush" << endl;
  }
}
