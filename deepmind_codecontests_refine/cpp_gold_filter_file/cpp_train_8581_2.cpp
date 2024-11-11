#include <bits/stdc++.h>
int a[4], cnt, ans2[1005];
char ans1[1005];
void jia(int x) {
  a[x]++;
  a[(x + 1) % 4]++;
  ++cnt;
  ans1[cnt] = '+';
  ans2[cnt] = x;
}
void chu(int x) {
  a[x] >>= 1;
  a[(x + 1) % 4] >>= 1;
  ++cnt;
  ans1[cnt] = '/';
  ans2[cnt] = x;
}
int main() {
  for (int i = (int)0, _y = 3; i <= _y; i++) scanf("%d", &a[i]);
  for (;;) {
    int k = 0;
    for (int i = (int)1, _y = 3; i <= _y; i++)
      if (a[k] < a[i]) k = i;
    if (a[k] == 1) break;
    int l = (k - 1 + 4) % 4, r = (k + 1) % 4;
    if (a[k] & 1) {
      if (a[l] & 1)
        jia(l), chu(l);
      else if (a[r] & 1)
        jia(k), chu(k);
      else
        jia(l), chu(k);
    } else {
      if ((a[l] & 1) ^ 1)
        chu(l);
      else if ((a[r] & 1) ^ 1)
        chu(k);
      else
        jia(l), jia(k), chu(l);
    }
  }
  for (int i = (int)1, _y = cnt; i <= _y; i++)
    printf("%c%d\n", ans1[i], ans2[i] + 1);
}
