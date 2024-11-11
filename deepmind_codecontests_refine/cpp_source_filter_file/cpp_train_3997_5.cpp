#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
long long a[100010], b[100010], D[100010], d[100010];
int l[100010], r[100010], n, m, k, x, y;
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) scanf("%I64d", a + i);
  for (int i = 1; i <= m; i++) scanf("%d%d%I64d", l + i, r + i, d + i);
  for (int i = 1; i <= k; i++) {
    scanf("%d%d", &x, &y);
    b[x]++, b[y + 1]--;
  }
  for (int i = 1; i <= n; i++) b[i] += b[i - 1];
  for (int i = 1; i <= n; i++) {
    D[l[i]] += (d[i] * b[i]), D[r[i] + 1] -= (d[i] * b[i]);
  }
  for (int i = 1; i <= n; i++) D[i] += D[i - 1];
  for (int i = 1; i <= n; i++) printf("%I64d ", D[i] + a[i]);
  puts("");
}
