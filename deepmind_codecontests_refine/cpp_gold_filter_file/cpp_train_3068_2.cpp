#include <bits/stdc++.h>
using namespace std;
vector<int> G[5005];
struct node {
  int l, r, maxn;
  double p;
  node() {}
  node(int L, int R, double P, int Maxn) { l = L, r = R, p = P, maxn = Maxn; }
} op[5005];
double dp[5005][5005];
int n, m, lg[100005], arr[100005], f[100005][105];
void inti() {
  for (int i = 1; i <= n; i++) f[i][0] = arr[i];
  int t = lg[n] + 1;
  for (int j = 1; j < t; j++) {
    for (int i = 1; i <= n - (1 << j) + 1; i++) {
      f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
  }
}
int query(int l, int r) {
  int k = lg[r - l + 1];
  return max(f[l][k], f[r - (1 << k) + 1][k]);
}
void read(int &x) {
  int f = 1;
  x = 0;
  char c = getchar();
  while (!('0' <= c && c <= '9')) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while ('0' <= c && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  x *= f;
}
inline bool cmp(node x, node y) { return x.l ^ y.l ? x.l < y.l : x.r > y.r; }
void DP(int u) {
  int v;
  for (int i = 0; i < (int)G[u].size(); i++) DP(G[u][i]);
  dp[u][0] = 1 - op[u].p;
  for (int i = 0; i < (int)G[u].size(); i++)
    v = G[u][i], dp[u][0] *= dp[v][op[u].maxn - op[v].maxn];
  for (int i = 1; i <= m; i++) {
    double p1 = 1, p2 = 1;
    for (int j = 0; j < (int)G[u].size(); j++) {
      v = G[u][j];
      p1 *= dp[v][min(i - op[v].maxn + op[u].maxn - 1, m)];
      p2 *= dp[v][min(i - op[v].maxn + op[u].maxn, m)];
    }
    dp[u][i] = op[u].p * p1 + (1 - op[u].p) * p2;
  }
}
int main() {
  int maxn = -1;
  read(n);
  read(m);
  for (int i = 1; i <= n; i++) {
    read(arr[i]);
    maxn = max(maxn, arr[i]);
    if (i != 1) lg[i] = lg[i >> 1] + 1;
  }
  inti();
  for (int i = 1; i <= m; i++) {
    read(op[i].l);
    read(op[i].r);
    scanf("%lf", &op[i].p);
    op[i].maxn = query(op[i].l, op[i].r);
  }
  op[++m] = node(1, n, 0.0, query(1, n));
  sort(op + 1, op + 1 + m, cmp);
  for (int i = 2; i <= m; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (op[j].l <= op[i].l && op[i].r <= op[j].r) {
        G[j].push_back(i);
        break;
      }
    }
  }
  DP(1);
  double ans = 0;
  for (int i = 0; i <= m; i++)
    ans += ((dp[1][i] - (!i ? 0 : dp[1][i - 1])) * (i + maxn));
  printf("%.9f", ans);
  return 0;
}
