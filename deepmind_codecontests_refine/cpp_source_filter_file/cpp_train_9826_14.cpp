#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000005;
int vis[MAXN];
int ans[MAXN];
int x[MAXN];
int n;
void solve() {
  memset(vis, 0, sizeof vis);
  for (int i = (n - 1); i >= (0); --i)
    if (!vis[i]) {
      int tmp = i ^ x[i];
      ans[i] = tmp;
      ans[tmp] = i;
      vis[i] = vis[tmp] = 1;
    }
  printf("%I64d\n", (long long)n * (n - 1));
  for (int i = (0); i < (n); ++i)
    printf("%d%c", ans[i], i < n - 1 ? ' ' : '\n');
}
void preprocess() {
  int t = 1;
  for (int i = (0); i < (MAXN); ++i) {
    if (i < t)
      x[i] = t - 1;
    else
      t <<= 1, x[i] = t - 1;
  }
}
int main() {
  preprocess();
  while (~scanf("%d", &n)) solve();
  return 0;
}
