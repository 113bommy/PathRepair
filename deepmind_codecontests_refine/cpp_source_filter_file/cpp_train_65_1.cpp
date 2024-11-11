#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
const long long INF = 1e12;
const double PI = acos(-1.0);
const double eps = 1e-10;
const int M = 1e9 + 9;
int de[N];
vector<int> G[N];
int num[N], vis[N];
void cot(int u, int p) {
  num[u] = 0;
  for (int v : G[u])
    if (v != p) {
      cot(v, u);
      num[u] += num[v];
    }
}
void dfs(int u, int p) {
  for (int v : G[u])
    if (v != p && !(de[v] & 1)) dfs(v, u);
  printf("%d ", u);
  for (int v : G[u])
    if (v != p && (de[v] & 1)) dfs(v, u);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1, j; i <= n; i++) {
    scanf("%d", &j);
    if (j) {
      de[i] ^= 1;
      de[j] ^= 1;
      G[i].push_back(j);
      G[j].push_back(i);
    }
  }
  bool f = n & 1;
  printf("%s\n", f ? "YES" : "NO");
  if (f) {
    cot(1, 0);
    dfs(1, 0);
  }
  return 0;
}
