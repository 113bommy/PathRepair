#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
vector<int> G[N];
int n, k, x, a, b;
bool flag[N];
int size = ~0u >> 2, ans;
int son[N];
void getc(int rt, int f) {
  if (flag[rt]) son[rt] = 1;
  int tmp = 0;
  for (int i = 0; i < G[rt].size(); ++i) {
    int v = G[rt][i];
    if (v == f) continue;
    getc(v, rt);
    son[rt] += son[v];
    tmp = max(tmp, son[v]);
  }
  tmp = max(tmp, 2 * k - son[rt]);
  if (tmp < size || tmp == size && rt < ans) {
    size = tmp;
    ans = rt;
  }
}
long long sum = 0;
void dfs(int rt, int f, long long d) {
  if (flag[rt]) sum += d;
  for (int i = 0; i < G[rt].size(); ++i) {
    int v = G[rt][i];
    if (v == f) continue;
    dfs(v, rt, d + 1);
  }
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k * 2; ++i) {
    scanf("%d", &x);
    flag[x] = 1;
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &a, &b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  getc(1, 1);
  dfs(ans, ans, 0);
  printf("%lld\n", sum);
}
