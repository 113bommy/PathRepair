#include <bits/stdc++.h>
using namespace std;
int a[100000];
vector<int> tree[100000];
long long dfs(int u, int prev) {
  vector<long long> tmp;
  for (int i = 0; i < (tree[u].size()); i++) {
    int v = tree[u][i];
    if (v != prev && a[v] >= 1) {
      a[v]--;
      tmp.push_back(1 + dfs(v, u) + 1);
    }
  }
  sort(tmp.begin(), tmp.end(), greater<long long>());
  int lim = min(a[u], (int)tmp.size());
  long long res = accumulate(tmp.begin(), tmp.begin() + lim, 0LL);
  a[u] -= lim;
  for (int i = 0; i < (tree[u].size()); i++) {
    int v = tree[u][i];
    if (v != prev) {
      long long m = min(a[u], a[v]);
      res += 2 * m;
      a[u] -= m;
      a[v] -= m;
    }
  }
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) scanf("%d", a + i);
  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  int s;
  scanf("%d", &s);
  s--;
  printf("%I64d\n", dfs(s, -1));
  return 0;
}
