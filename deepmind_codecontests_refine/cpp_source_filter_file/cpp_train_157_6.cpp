#include <bits/stdc++.h>
using namespace std;
long long n, m, a, b;
long long p[1000111];
long long par[100111];
long long c;
vector<long long> g[1000111];
bool used[1000111];
priority_queue<long long> curs[1000111];
void dfs(long long x) {
  used[x] = true;
  par[x] = c;
  curs[c].push(p[x]);
  for (long long i = 0; i <= (long long)g[x].size() - 1; ++i) {
    if (!used[g[x][i]]) dfs(g[x][i]);
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (long long i = 1; i <= n; ++i) {
    cin >> p[i];
  }
  for (long long i = 1; i <= m; ++i) {
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (long long i = 1; i <= n; ++i) {
    if (!used[i]) {
      c = i;
      dfs(i);
    }
  }
  for (long long i = 1; i <= n; ++i) {
    cout << curs[par[i]].top() << ' ';
    curs[par[i]].pop();
  }
}
