#include <bits/stdc++.h>
int a[500005][9] = {0};
int nnf[500005] = {0};
int pn[200005] = {0};
int val[200005];
int x, in;
void print(int *a, int n) {
  int i;
  for (i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
}
long long int check(int cnt, int val, int d) {
  if (in == -1) nnf[val] += in;
  long long int q = d * nnf[val], i;
  for (i = cnt + 1; i <= a[x][0]; i++) q += check(i, val * a[x][i], -d);
  if (in == 1) nnf[val] += in;
  return q;
}
int main() {
  a[1][0] = 1;
  a[1][1] = 1;
  int i, j;
  for (i = 1; i < 500001; i++) {
    if (a[i][0] == 1) {
      for (j = i; j < 500001; j += i) {
        a[j][0] += 1;
        a[j][a[j][0]] = i;
      }
    }
  }
  a[1][0] = 1;
  int n, q;
  long long int ans = 0;
  scanf("%d %d", &n, &q);
  for (i = 1; i <= n; i++) scanf("%d", &val[i]);
  for (i = 0; i < q; i++) {
    scanf("%d", &j);
    if (pn[j] == 1)
      in = -1;
    else
      in = 1;
    pn[j] = pn[j] ^ 1;
    x = val[j];
    ans += check(1, 1, in);
    printf("%lld\n", ans);
  }
  return 0;
}
