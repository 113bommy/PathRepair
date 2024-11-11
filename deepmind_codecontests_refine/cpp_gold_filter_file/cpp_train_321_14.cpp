#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
const int K = 200;
const int mod = 998244353;
int power(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) {
      res = 1LL * res * a % mod;
    }
    a = 1LL * a * a % mod;
    b >>= 1;
  }
  return res;
}
vector<int> adj[1005];
int par[1005];
void dfs(int node, int p) {
  par[node] = p;
  for (auto child : adj[node]) {
    if (child == p) continue;
    dfs(child, node);
  }
}
int main() {
  int test, n, u, v, k1, k2, val;
  scanf("%d", &test);
  while (test--) {
    set<int> s1, s2;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      par[i] = -1;
    }
    for (int i = 1; i < n; i++) {
      scanf("%d %d", &u, &v);
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    scanf("%d", &k1);
    for (int i = 1; i <= k1; i++) {
      scanf("%d", &val);
      s1.insert(val);
    }
    scanf("%d", &k2);
    for (int i = 1; i <= k2; i++) {
      scanf("%d", &val);
      s2.insert(val);
    }
    int a1 = *s1.begin(), a2, b1, b2;
    printf("A %d\n", a1);
    fflush(stdout);
    scanf("%d", &b1);
    if (s2.find(b1) != s2.end()) {
      printf("C %d\n", a1);
      fflush(stdout);
      continue;
    }
    b2 = *s2.begin();
    printf("B %d\n", b2);
    fflush(stdout);
    scanf("%d", &a2);
    if (s1.find(a2) != s1.end()) {
      printf("C %d\n", a2);
      fflush(stdout);
      continue;
    }
    dfs(a1, 0);
    while (a2) {
      if (s1.find(a2) != s1.end()) {
        break;
      }
      a2 = par[a2];
    }
    if (a2) {
      printf("A %d\n", a2);
      fflush(stdout);
      scanf("%d", &b2);
      if (s2.find(b2) != s2.end()) {
        printf("C %d\n", a2);
        fflush(stdout);
        continue;
      }
    }
    printf("C -1\n");
    fflush(stdout);
  }
  return 0;
}
