#include <bits/stdc++.h>
using namespace std;
int ta[200005], a[200005], b[200005], p[200005], k[200005];
int n, r, Q;
long long Ans = -2333333333LL;
void work(int f) {
  if (f) {
    for (int i = 1; i <= n; i++) ta[i] = a[i] + r;
    for (int i = 1; i <= n; i++) a[i] = ta[p[i]];
  } else {
    for (int i = 1; i <= n; i++) ta[i] = a[i] - r;
    for (int i = 1; i <= n; i++) a[p[i]] = ta[i];
  }
}
void dfs(int re, int la) {
  if (!(re & 1)) {
    long long Ret = 0;
    for (int i = 1; i <= n; i++) Ret += a[i] * k[i];
    Ans = max(Ans, Ret);
  }
  if (re == 0) return;
  if (!la) {
    for (int i = 1; i <= n; i++) a[i] ^= b[i];
    dfs(re - 1, 1);
    for (int i = 1; i <= n; i++) a[i] ^= b[i];
  }
  work(1);
  dfs(re - 1, 0);
  work(0);
}
int main() {
  scanf("%d%d%d", &n, &Q, &r);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &k[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  dfs(Q, 0);
  printf("%I64d\n", Ans);
}
