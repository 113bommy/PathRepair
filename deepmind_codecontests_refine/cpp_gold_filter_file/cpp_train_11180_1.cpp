#include <bits/stdc++.h>
int a[100100];
int n, m;
void op1() {
  int x, v;
  scanf("%d %d", &x, &v);
  a[x] = v;
}
long long f[100100];
void op2() {
  int l, r, L;
  long long ans = 0;
  scanf("%d %d", &l, &r);
  L = l;
  while (l <= r) {
    ans = (ans + f[l - L] * a[l]) % 1000000000;
    l++;
  }
  printf("%d\n", (int)ans);
}
void op3() { puts("lol"); }
int main() {
  int i, t;
  scanf("%d %d", &n, &m);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);
  f[0] = f[1] = 1;
  for (i = 2; i < 100100; i++) f[i] = (f[i - 1] + f[i - 2]) % 1000000000;
  while (m--) {
    scanf("%d", &t);
    if (t == 1)
      op1();
    else if (t == 2)
      op2();
    else
      op3();
  }
  return 0;
}
