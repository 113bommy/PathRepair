#include <bits/stdc++.h>
using namespace std;
struct data {
  long long dau, cuoi, ttrai, tphai, tmax, slcon;
};
data tree[400005];
long long n, dp[100005], a[100005], b[100005];
void taocay(long long nut, long long dau, long long cuoi) {
  long long giua;
  tree[nut].dau = dau;
  tree[nut].cuoi = cuoi;
  if (dau == cuoi) {
    tree[nut].slcon = 1;
    tree[nut].tmax = a[dau];
    tree[nut].ttrai = a[dau];
    tree[nut].tphai = a[dau];
    return;
  }
  giua = (dau + cuoi) / 2;
  taocay(nut * 2, dau, giua);
  taocay(nut * 2 + 1, giua + 1, cuoi);
  tree[nut].slcon = cuoi - dau + 1;
  tree[nut].tmax = tree[nut * 2].tmax + tree[nut * 2 + 1].tmax;
  tree[nut].tphai = tree[nut].tmax;
  tree[nut].ttrai = tree[nut].tmax;
}
void update(long long vt, long long nut) {
  int giua;
  if (tree[nut].dau == tree[nut].cuoi) {
    tree[nut].slcon = 0;
    tree[nut].tmax = 0;
    tree[nut].ttrai = 0;
    tree[nut].tphai = 0;
    return;
  }
  giua = (tree[nut].dau + tree[nut].cuoi) / 2;
  if (vt > giua)
    update(vt, nut * 2 + 1);
  else
    update(vt, nut * 2);
  tree[nut].ttrai = tree[nut * 2].ttrai;
  tree[nut].slcon = tree[nut * 2].slcon + tree[nut * 2 + 1].slcon;
  if (tree[nut * 2].slcon == tree[nut * 2].cuoi - tree[nut * 2].dau + 1)
    tree[nut].ttrai += tree[nut * 2 + 1].ttrai;
  tree[nut].tphai = tree[nut * 2 + 1].tphai;
  if (tree[nut * 2 + 1].slcon ==
      tree[nut * 2 + 1].cuoi - tree[nut * 2 + 1].dau + 1)
    tree[nut].tphai += tree[nut * 2].tphai;
  tree[nut].tmax = max(max(tree[nut * 2].tmax, tree[nut * 2 + 1].tmax),
                       tree[nut * 2].tphai + tree[nut * 2 + 1].ttrai);
}
void solve() {
  int i;
  taocay(1, 1, n);
  for (i = 1; i <= n; i++) {
    update(b[i], 1);
    printf("%I64d\n", tree[1].tmax);
  }
}
int main() {
  int i;
  while (scanf("%I64d", &n) > 0) {
    dp[0] = 0;
    for (i = 1; i <= n; i++) {
      scanf("%I64d", &a[i]);
      dp[i] = dp[i - 1] + a[i];
    }
    for (i = 1; i <= n; i++) scanf("%I64d", &b[i]);
    solve();
  }
  return 0;
}
