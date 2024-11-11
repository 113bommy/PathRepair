#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
struct node {
  int a, b;
} num[maxn];
inline bool cmp(node x, node y) {
  if (x.b != y.b) return x.b > y.b;
  return x.a > y.a;
}
int f[maxn][maxn * maxn], n, m, res, numm, tot, sum;
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++)
    scanf("%d", &num[i].a), sum = sum + num[i].a;
  for (register int i = 1; i <= n; i++) scanf("%d", &num[i].b);
  sort(num + 1, num + n + 1, cmp);
  for (register int i = 1; i <= n; i++) {
    tot += num[i].b;
    if (tot >= sum) {
      numm = i;
      break;
    }
  }
  printf("%d ", numm);
  memset(f, -1, sizeof(f));
  f[0][0] = 0;
  for (register int i = 1; i <= n; i++)
    for (register int k = tot; k >= num[i].b; k--)
      for (register int j = 1; j <= numm; j++)
        if (f[j - 1][k - num[i].b] != -1)
          f[j][k] = max(f[j][k], f[j - 1][k - num[i].b] + num[i].a);
  for (register int i = sum; i <= tot; i++) res = max(res, f[numm][i]);
  printf("%d\n", sum - res);
  return 0;
}
