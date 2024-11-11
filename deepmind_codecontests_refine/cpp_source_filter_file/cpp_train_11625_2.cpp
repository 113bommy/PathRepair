#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
const int MAX_LOG = 20;
vector<int> vertex[MAXN];
vector<int> e;
int h[MAXN];
int z[MAXN];
int dp[MAXN];
bool check[MAXN];
long long res;
void dfs(int v) {
  check[v] = true;
  h[v] = 1;
  e.clear();
  for (int i = 0; i < vertex[v].size(); i++) {
    if (!check[vertex[v][i]]) {
      e.push_back(dp[vertex[v][i]]);
    }
  }
  e.push_back(0);
  sort(e.begin(), e.end());
  dp[v] = 0;
  int w = 0;
  for (int i = (long long)(e.size()) - 1; i >= 0; i--) {
    int k = i;
    if (w >= e[i]) {
      dp[v] = w;
      break;
    }
    while (k >= 0 && e[k] > 0 && e[k] == e[i]) {
      w++;
      k--;
    }
    if (w >= e[i]) {
      dp[v] = e[i];
      break;
    }
    i = k + 1;
  }
  if (dp[v] == 0) {
    dp[v] = w;
  }
  for (int i = 0; i < vertex[v].size(); i++) {
    if (!check[vertex[v][i]]) {
      dfs(vertex[v][i]);
      h[v] = max(h[v], h[vertex[v][i]] + 1);
    }
  }
}
void calc(int v) {
  check[v] = true;
  z[v] = dp[v];
  for (int i = 0; i < vertex[v].size(); i++) {
    if (!check[vertex[v][i]]) {
      calc(vertex[v][i]);
      z[v] = max(z[vertex[v][i]], z[v]);
    }
  }
  res += max(0, z[v] - 1);
}
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < (n - 1); i++) {
    int v, u;
    cin >> v >> u;
    vertex[v].push_back(u);
    vertex[u].push_back(v);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = n;
  }
  res = (n - 1) * n;
  for (int i = 1; i < MAX_LOG; i++) {
    fill(check, check + MAXN, false);
    dfs(1);
    fill(check, check + MAXN, false);
    calc(1);
  }
  for (int i = 1; i <= n; i++) {
    res += h[i];
  }
  cout << res;
}
