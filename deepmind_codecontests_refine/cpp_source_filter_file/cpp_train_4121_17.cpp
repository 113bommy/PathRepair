#include <bits/stdc++.h>
using namespace std;
long long n;
vector<long long> adj[35];
long long fx[] = {0, +1, 0, -1};
long long fy[] = {-1, 0, 1, 0};
bool vis[35];
pair<long long, long long> pos[35];
long long t = 0;
void dfs(long long u, long long x, long long y, long long pox, long long poy,
         long long type) {
  vis[u] = true;
  pos[u] = make_pair(x, y);
  long long t = 0;
  for (long long i = 0; i < adj[u].size(); i++) {
    long long v = adj[u][i];
    if (vis[v] == false) {
      if (type == 0 && t == 1)
        t = 2;
      else if (type == 1 && t == 0)
        t = 1;
      else if (type == 2 && t == 3)
        t = 0;
      else if (type == 3 && t == 2)
        t = 3;
      long long tx = x + fx[t] * pox;
      long long ty = y + fy[t] * poy;
      dfs(v, tx, ty, pox / 2, poy / 2, t);
      t++;
      t = t % 4;
    }
  }
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (long long i = 1; i <= n; i++) {
    if (adj[i].size() > 4) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES" << endl;
  long long INF = 100000000000;
  memset(vis, false, sizeof vis);
  dfs(1, 0, 0, INF, INF, -1);
  for (long long i = 1; i <= n; i++) {
    cout << pos[i].first << " " << pos[i].second << endl;
  }
}
