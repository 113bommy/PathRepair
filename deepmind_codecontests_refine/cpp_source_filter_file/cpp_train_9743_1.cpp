#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 4;
int pre[maxn], vis[maxn];
vector<int> G[maxn];
void inist(int n) {
  for (int i = 1; i <= n; i++) pre[i] = i;
}
int find(int x) { return x == pre[x] ? x : pre[x] = find(pre[x]); }
void join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) pre[x] = y;
}
long long C(long long x, long long y) {
  if (x < y) return 0;
  long long ans = 1, q = 1;
  for (int i = 1; i <= y; i++) ans *= (x + 1 - i);
  for (int i = 1; i <= y; i++) q *= i;
  return ans / q;
}
int main() {
  int n, m;
  int loop = 0;
  cin >> n >> m;
  inist(n);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    vis[u] = vis[v] = 1;
    if (u == v) {
      loop++;
    } else {
      join(u, v);
      G[u].push_back(v);
      G[v].push_back(u);
    }
  }
  int root;
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) continue;
    root = find(i);
    break;
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) continue;
    if (find(i) != root) flag = 1;
  }
  if (flag) {
    printf("0\n");
    return 0;
  }
  long long ans = 0;
  ans += C(loop, 2) + loop * (m - loop);
  for (int i = 1; i <= n; i++) {
    long long sz = G[i].size();
    if (sz <= 1) continue;
    ans += sz * (sz - 1) / 2;
  }
  printf("%lld\n", ans);
}
