#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int n, m;
int u, v;
int a[maxn], dis[maxn];
vector<int> gr[maxn];
int ans = -1;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> u >> v;
  --u;
  --v;
  memset(a, 0, sizeof a);
  for (int i = (0); i < (n); ++i) {
    cin >> m;
    a[i] = m;
    a[i]--;
  }
  fill(dis, dis + n + 1, -1);
  dis[u] = 0;
  while (u != v) {
    int nxt = a[u];
    if (dis[nxt] != -1) break;
    dis[nxt] = dis[u] + 1;
    u = nxt;
  }
  cout << dis[v];
}
