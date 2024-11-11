#include <bits/stdc++.h>
using namespace std;
int all, n, m, t, now;
int who[20010];
int tt[20010], a, b, c, zhan[20010], bt, tp, big;
int main() {
  int i;
  scanf("%d%d%d", &n, &m, &t);
  for (i = 1; i <= n; i++)
    scanf("%d:%d:%d", &a, &b, &c), tt[i] = a * 60 * 60 + b * 60 + c;
  for (i = 1; i <= n; i++) {
    while (bt < tp && zhan[bt] < tt[i]) bt++, now--;
    if (bt == tp || now < m) {
      who[i] = ++all, now++;
      zhan[tp++] = tt[i] + t - 1;
    } else {
      who[i] = all;
      zhan[tp - 1] = tt[i] + t - 1;
    }
    if (now > big) big = now;
  }
  if (big < m)
    printf("No solution\n");
  else {
    printf("%d\n", all);
    for (i = 1; i <= n; i++) printf("%d\n", who[i]);
  }
  return 0;
}
