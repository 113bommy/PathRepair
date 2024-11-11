#include <bits/stdc++.h>
const int W = 18;
int al[W + 1], ar[W + 1], ans, c[10];
long long L, R;
int chk(int t, int tgl, int tgr) {
  if (t > W) return 1;
  if (tgl + tgr == 0) return 1;
  for (int i = 0; i < 10; i++) {
    if (!c[i]) continue;
    if ((tgl && i < al[t]) || (tgr && i > ar[t])) continue;
    c[i]--;
    int di = chk(t + 1, tgl & (i == al[t]), tgr & (i == ar[t]));
    c[i]++;
    if (di) return 1;
  }
  return 0;
}
void dfs(int t, int x) {
  if (t > W) {
    ans += chk(0, 1, 1);
    return;
  }
  for (int i = x; i < 10; i++) {
    c[i]++;
    dfs(t + 1, i);
    c[i]--;
  }
}
int main() {
  scanf("%lld%lld", &L, &R);
  for (int i = W; i >= 0; i--, L /= 10) al[i] = L % 10;
  for (int i = W; i >= 0; i--, R /= 10) ar[i] = R % 10;
  dfs(0, 0);
  printf("%d\n", ans);
}
