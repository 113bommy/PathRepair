#include <bits/stdc++.h>
using namespace std;
char s[100010], t[100010];
int qzhsb[100010], qzhtb[100010], hztotsa[100010], hztotta[100010];
int n, m, q;
int main() {
  scanf("%s%s", s + 1, t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  scanf("%d", &q);
  for (int i = 1; i <= n; ++i) {
    qzhsb[i] = qzhsb[i - 1] + (s[i] != 'A');
    hztotsa[i] = (s[i] == 'A' ? hztotsa[i - 1] + 1 : 0);
  }
  for (int i = 1; i <= m; ++i) {
    qzhtb[i] = qzhtb[i - 1] + (t[i] != 'A');
    hztotta[i] = (t[i] == 'A' ? hztotta[i - 1] + 1 : 0);
  }
  for (int i = 1; i <= q; ++i) {
    int l1, r1, l2, r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    int totsb = qzhsb[r1] - qzhsb[l1 - 1], tottb = qzhtb[r2] - qzhtb[l2 - 1],
        hzsa = min(hztotsa[r1], r1 - l1 + 1),
        hzta = min(hztotta[r2], r2 - l2 + 1);
    if ((hzta > hzsa) || ((tottb - totsb) & 1) ||
        (tottb - ((hzta - hzsa) % 3 > 0) * 2 < totsb) ||
        (totsb == 0 && tottb && hzsa == hzta))
      printf("0");
    else
      printf("1");
  }
}
