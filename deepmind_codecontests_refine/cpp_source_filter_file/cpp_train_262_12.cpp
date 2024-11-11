#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long maxn = 4e5 + 7;
const long long maxe = 1e6 + 7;
const long long INF = 1e9 + 7;
const double PI = acos(-1);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
inline void Max(int &a, int b) {
  if (b > a) a = b;
}
inline void Min(int &a, int b) {
  if (a == -1 || b < a) a = b;
}
int n, k;
vector<int> G[maxn];
pair<pair<int, int>, pair<int, int> > f1[maxn];
int f2[maxn];
int Si[maxn];
bool dp[maxn];
void dfs1(int u, int fa) {
  Si[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs1(v, u);
    Si[u] += Si[v];
  }
}
void dfs2(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    dfs2(v, u);
    f1[u].second = max(make_pair(f1[v].first.first, v), f1[u].second);
    if (Si[v] <= k) f1[u].second = max(f1[v].first, make_pair(Si[v], v));
    if (f1[u].second > f1[u].first) swap(f1[u].second, f1[u].first);
  }
}
void dfs3(int u, int fa) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    f2[v] = f2[u];
    if (v == f1[u].first.second)
      f2[v] = max(f2[v], f1[u].second.first);
    else
      f2[v] = max(f2[v], f1[u].first.first);
    if (n - Si[v] <= k) f2[v] = n - Si[v];
    dfs3(v, u);
  }
}
void dfs4(int u, int fa) {
  int cnt = 0;
  bool ok = true;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == fa) continue;
    if (Si[v] > k) {
      if (Si[v] - f1[v].first.first <= k)
        cnt++;
      else
        ok = false;
    }
    dfs4(v, u);
  }
  if (n - Si[u] > k) {
    if (n - Si[u] - f2[u] <= k)
      cnt++;
    else
      ok = false;
  }
  if (cnt > 1) ok = false;
  dp[u] = ok;
}
int main() {
  cin >> n;
  k = n / 2;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  f2[1] = 0;
  dfs1(1, 0);
  dfs2(1, 0);
  dfs3(1, 0);
  dfs4(1, 0);
  for (int i = 1; i <= n; i++)
    if (dp[i])
      cout << "1 ";
    else
      cout << "0 ";
  cout << endl;
  return 0;
}
