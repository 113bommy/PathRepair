#include <bits/stdc++.h>
using namespace std;
const int N = 101, INF = 1e9 + 10;
int n, m, u, v, x, y;
long long A[N], B[N];
vector<int> vec;
int vis[N];
int c = 0;
int P[500005];
vector<int> adj[500005];
void dfs(int n, int p) {
  P[n] = p;
  for (int v : adj[n])
    if (v != p) dfs(v, n);
}
int main() {
  cin >> n >> x >> y;
  for (int i = 1; i <= n; ++i) {
    if (i == x) continue;
    int p;
    scanf("%d", &p);
    adj[i].push_back(p), adj[p].push_back(i);
  }
  dfs(y, 0);
  for (int i = 1; i <= n; ++i)
    if (i != y) printf("%d ", P[i]);
}
