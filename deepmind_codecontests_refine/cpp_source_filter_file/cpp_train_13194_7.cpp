#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], c[N];
vector<int> divs[N];
vector<int> G[N];
vector<int> cnt[N];
long long tot[N], ans[N];
int mu[N], np[N];
void getAns(int n) {
  for (int i = n; i >= 1; i--) {
    ans[i] = tot[i];
    for (int j = i + i; j <= n; j += i) ans[i] -= ans[j];
  }
}
void dfs(int v, int p = -1) {
  for (auto u : G[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  for (auto x : divs[a[v]]) {
    c[x] = 1;
    tot[x]++;
  }
  for (auto u : G[v]) {
    if (u == p) continue;
    for (int i = 0; i < cnt[u].size(); i++) {
      int x = divs[a[u]][i];
      if (a[v] % x == 0) {
        tot[x] += (long long)c[x] * cnt[u][i];
        c[x] += cnt[u][i];
      }
    }
  }
  for (auto x : divs[a[v]]) {
    cnt[v].push_back(c[x]);
    c[x] = 0;
  }
}
int main() {
  int n = 200000;
  for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j += i) divs[j].push_back(i);
  int V;
  scanf("%d", &V);
  for (int i = 1; i <= V; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < V; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1);
  getAns(n);
  for (int i = 1; i <= n; i++) {
    if (ans[i] > 0) {
      printf("%d %d\n", i, ans[i]);
    }
  }
}
