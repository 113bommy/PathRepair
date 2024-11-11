#include <bits/stdc++.h>
using namespace std;
int n, p, cnt, res, tmp, aa[50011], a[26], dy[26], ans[26];
int main() {
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &aa[i]);
    if (aa[i] <= 24) a[++cnt] = aa[i], dy[a[cnt]] = i;
  }
  int nn = min(24, n);
  int maxs = (1 << nn) - 1;
  for (int s = 1; s <= maxs; s++) {
    res = 0;
    tmp = 0;
    for (int i = 1; i <= nn; i++)
      if (s & (1 << (i - 1))) {
        tmp = tmp ^ a[i];
        if (a[i] < 10)
          res = ((res * 10) % p + a[i]) % p;
        else
          res = ((res * 100) % p + a[i]) % p;
      }
    if ((!tmp) && (!res)) {
      printf("Yes\n");
      int ccnt = 0;
      for (int i = 1; i <= nn; i++)
        if (s & (1 << (i - 1))) ccnt++;
      printf("%d\n", ccnt);
      ccnt = 0;
      for (int i = 1; i <= nn; i++)
        if (s & (1 << (i - 1))) ans[++ccnt] = dy[a[i]];
      sort(ans + 1, ans + ccnt + 1);
      for (int i = 1; i <= ccnt; i++) printf("%d ", ans[i]);
      return 0;
    }
  }
  printf("No\n");
}
