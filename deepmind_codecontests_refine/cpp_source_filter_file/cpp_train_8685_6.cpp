#include <bits/stdc++.h>
using namespace std;
const int maxn = 100050;
int n, m;
int a[maxn], b[maxn];
void get(int x[], int k) {
  int i;
  if (k == 1)
    x[1] = 1;
  else if (k == 2)
    x[1] = 3, x[2] = 4;
  else if (k & 1)
    for (x[1] = (k - 1) / 2, x[2] = 2, i = 3; i <= k; i++) x[i] = 1;
  else
    for (x[1] = k / 2 - 1, i = 2; i <= k; i++) x[i] = 1;
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  get(a, n);
  get(b, m);
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) printf("%d%c", a[i] * b[j], j < m ? ' ' : '\n');
  return 0;
}
