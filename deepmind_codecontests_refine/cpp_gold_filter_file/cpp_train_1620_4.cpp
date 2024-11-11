#include <bits/stdc++.h>
char ans[100000];
int main() {
  bool psb = true;
  long long int a, b, c, d;
  scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
  if (a + b + c + d == 0) {
    printf("0\n");
    return 0;
  }
  long long int l0 = (b + c != 0), l1 = (b + c != 0);
  while (l0 * (l0 - 1) < (a << 1)) l0++;
  if ((l0 * (l0 - 1)) / 2 != a) psb = false;
  while (l1 * (l1 - 1) < (d << 1)) l1++;
  if ((l1 * (l1 - 1)) / 2 != d) psb = false;
  if (a + b + c + d != ((l0 + l1) * (l0 + l1 - 1)) / 2) psb = false;
  if (!psb) {
    printf("Impossible\n");
    return 0;
  }
  if (!l1) {
    for (int i = 0; i < l0; i++) printf("0");
    printf("\n");
    return 0;
  }
  long long int hop = l0 * l1 - b, cnt = hop / l1, rem = hop % l1;
  for (int i = 0; i < l0 + l1; i++) ans[i] = '0';
  for (int i = l0 - cnt - 1; i < l0 - cnt + l1; i++) ans[i] = '1';
  ans[l0 - cnt + rem - 1] = '0';
  printf("%s\n", ans);
  return 0;
}
