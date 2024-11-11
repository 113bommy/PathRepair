#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n, L, x, best[N], b[N], w[N], h[N], p[N][20];
long long S, s[N];
vector<int> v[N];
int res;
void pre(int node, int pnode) {
  s[node] = s[pnode] + w[node];
  p[node][0] = pnode;
  h[node] = h[pnode] + 1;
  for (int cur = 1; (1 << cur) <= n; cur++)
    p[node][cur] = p[p[node][cur - 1]][cur - 1];
  b[node] = node;
  for (int cur = 19; cur >= 0; cur--) {
    if (p[b[node]][cur] == 0) continue;
    if (h[node] - h[p[b[node]][cur]] + 1 > L) continue;
    if (s[node] - s[p[b[node]][cur]] + w[p[b[node]][cur]] > S) continue;
    b[node] = p[b[node]][cur];
  }
  for (auto &i : v[node]) pre(i, node);
}
void dfs(int node) {
  best[node] = -1;
  for (auto &i : v[node]) {
    dfs(i);
    if (best[i] == i) continue;
    if (best[node] == -1 || h[best[i]] < h[best[node]]) best[node] = i;
  }
  if (best[node] == -1) {
    res++;
    best[node] = b[node];
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> L >> S;
  for (int i = 1; i <= n; i++) {
    cin >> w[i];
    if (w[i] > S) return cout << -1 << endl, 0;
  }
  for (int i = 2; i <= n && cin >> x; i++) v[x].push_back(i);
  pre(1, 0);
  dfs(1);
  cout << res << endl;
}
