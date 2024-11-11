#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500;
vector<int> adj[maxn];
pair<long double, long double> a[maxn], P;
int par[maxn], s[maxn], ans[maxn], ord[maxn];
bool mark[maxn];
void dfs(int v) {
  s[v] = 1;
  for (int i = 0; i < adj[v].size(); i++) {
    int u = adj[v][i];
    if (u - par[v]) {
      par[u] = v;
      dfs(u);
      s[v] += s[u];
    }
  }
}
bool cmp(int i, int j) {
  pair<long double, long double> A = pair<long double, long double>(
      a[i].first - P.first, a[i].second - P.second);
  pair<long double, long double> B = pair<long double, long double>(
      a[j].first - P.first, a[j].second - P.second);
  long double cross = A.first * B.second - A.second * B.first;
  if (cross > 0) return true;
  return false;
}
void f(int l, int r, int root) {
  int idx = l;
  for (int i = l; i < r; i++) {
    if (a[ord[i]].first < a[ord[idx]].first) idx = i;
    if (a[ord[i]].first == a[ord[idx]].first &&
        a[ord[i]].second < a[ord[idx]].second)
      idx = i;
  }
  ans[ord[idx]] = root;
  P = a[ord[idx]];
  swap(ord[l], ord[idx]);
  l++;
  sort(ord + l, ord + r);
  int st = l;
  for (int i = 0; i < adj[root].size(); i++) {
    int u = adj[root][i];
    if (u != par[root]) {
      f(st, st + s[u], u);
      st += s[u];
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  par[0] = -1;
  dfs(0);
  for (int i = 0; i < n; i++) ord[i] = i;
  f(0, n, 0);
  for (int i = 0; i < n; i++) cout << ans[i] + 1 << ' ';
  return 0;
}
