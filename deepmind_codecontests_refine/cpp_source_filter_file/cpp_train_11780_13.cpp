#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 50;
const int t = 20;
int a[maxn], b[maxn];
int pre[maxn], res[maxn], mx[maxn], f[maxn][22], last[maxn];
vector<int> g[maxn];
int vis[maxn];
queue<int> q;
int main() {
  int n, m, q1;
  scanf("%d%d%d", &n, &m, &q1);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
  for (int i = 2; i <= n; i++) pre[a[i]] = a[i - 1];
  pre[a[1]] = a[n];
  for (int i = 1; i <= m; i++) {
    f[i][0] = last[pre[b[i]]];
    for (int j = 1; j <= t; j++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
    }
    int now = i;
    for (int j = t; j >= 0; j--) {
      if ((n - 1) & (1 << j)) now = f[i][j];
    }
    if (now) res[i] = now;
    last[b[i]] = i;
  }
  mx[1] = res[1];
  for (int i = 2; i <= m; i++) mx[i] = max(mx[i - 1], res[i]);
  while (q1--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (mx[r] >= l)
      printf("1");
    else
      printf("0");
  }
}
