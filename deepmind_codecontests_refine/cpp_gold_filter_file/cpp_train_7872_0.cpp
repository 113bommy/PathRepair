#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
vector<int> adj[N];
bool vis[N];
int par[N], depth[N], P[N], l, r, a, b;
long long PR[N];
void dfs(int v, int p) {
  vis[v] = 1;
  par[v] = p;
  depth[v] = depth[p] + 1;
  for (int i : adj[v]) {
    if (!vis[i])
      dfs(i, v);
    else if (i != p && depth[v] > depth[i]) {
      vector<int> cycle;
      int j = v;
      while (j != i) {
        cycle.push_back(j);
        j = par[j];
      }
      cycle.push_back(i);
      int mn = INT_MAX, mx = INT_MIN;
      for (int j : cycle) {
        mn = min(mn, j);
        mx = max(mx, j);
      }
      P[mn] = mx;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  while (m--) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    if (!vis[i]) dfs(i, i);
  P[n + 1] = n + 1;
  for (int i = n; i >= 1; i--) {
    if (P[i] == 0) P[i] = n + 1;
    P[i] = min(P[i], P[i + 1]);
  }
  for (int i = 1; i <= n; i++) PR[i] = PR[i - 1] + P[i];
  int Q;
  cin >> Q;
  while (Q--) {
    cin >> l >> r;
    if (P[l] > r) {
      cout << 1ll * (r - l + 1) * (r - l + 2) / 2 << '\n';
    } else {
      int cl = l, cr = r;
      while (cl != cr) {
        m = (cl + cr + 1) / 2;
        if (P[m] <= r)
          cl = m;
        else
          cr = m - 1;
      }
      cout << (PR[cl] - PR[l - 1]) + 1ll * (r - cl) * (r - cl + 1) / 2 -
                  1ll * (cl + l) * (cl - l + 1) / 2
           << '\n';
    }
  }
}
