#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 5;
int n, m, q, l, r;
int p[M], a[M], lg[M], val[M], loc[M], jump[M][20], st[M][20];
bool rmq(int l, int r) {
  int tmp = lg[r - l + 1];
  return max(st[l][tmp], st[r - (1 << tmp) + 1][tmp]) >= l;
}
int main() {
  for (int i = 1; i <= 2e5; i++) lg[i] = lg[i >> 1] + 1;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
  p[0] = p[n];
  for (int i = 1; i <= n; i++) val[p[i]] = p[i - 1];
  for (int i = 1; i <= m; i++) {
    jump[i][0] = loc[val[a[i]]];
    loc[a[i]] = i;
  }
  for (int i = 1; i <= lg[n]; i++)
    for (int j = 1; j <= m; j++) jump[j][i] = jump[jump[j][i - 1]][i - 1];
  for (int i = 1; i <= m; i++) {
    st[i][0] = i;
    for (int j = 0; j <= lg[n - 1]; j++)
      if ((n - 1) & (1 << j)) st[i][0] = jump[st[i][0]][j];
  }
  for (int i = 1; i <= lg[m]; i++)
    for (int j = 1; j + (1 << i) - 1 <= m; j++)
      st[j][i] = max(st[j][i - 1], st[j + (1 << i - 1)][i - 1]);
  while (q--) {
    scanf("%d %d", &l, &r);
    printf("%d", rmq(l, r));
  }
}
