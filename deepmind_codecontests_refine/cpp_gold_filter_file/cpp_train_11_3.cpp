#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353, dt = 320;
int b[100010], a[100010], pre[100010], d[100010];
int f[100010];
int q[320][645];
int n, k, now;
int sum[320];
inline int mo(int x) {
  if (x >= MOD) return x - MOD;
  return x;
}
void ins(int x, int y) {
  b[x] = y;
  int z = x / dt;
  if (z == now) return;
  sum[z] = 0;
  for (int i = 0; i <= dt + dt; i++) q[z][i] = 0;
  for (int i = z * dt + dt - 1; i >= z * dt; i--)
    sum[z] += b[i], q[z][sum[z] + dt] = mo(q[z][sum[z] + dt] + f[i]);
  for (int i = 1; i <= dt + dt; i++) q[z][i] = mo(q[z][i] + q[z][i - 1]);
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++)
    scanf("%d", &a[i]), pre[i] = d[a[i]], d[a[i]] = i;
  f[0] = 1;
  for (int i = 1; i <= n; i++) {
    now = i / dt;
    ins(i - 1, 1);
    if (pre[i]) {
      ins(pre[i] - 1, -1);
      if (pre[pre[i]]) ins(pre[pre[i]] - 1, 0);
    }
    int tot = 0;
    for (int j = i - 1; j / dt == now && j >= 0; j--) {
      tot += b[j];
      if (tot <= k) f[i] = mo(f[i] + f[j]);
    }
    for (int j = now - 1; j >= 0; j--) {
      if (tot <= k + dt) f[i] = mo(f[i] + q[j][min(dt + dt, k + dt - tot)]);
      tot += sum[j];
    }
  }
  printf("%d\n", f[n]);
}
