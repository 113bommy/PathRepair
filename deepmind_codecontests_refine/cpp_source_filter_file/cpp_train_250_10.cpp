#include <bits/stdc++.h>
using namespace std;
const int MOD = (int)1e9 + 7;
const int MAXN = 205;
int a[MAXN];
int b[MAXN];
int c[MAXN];
int sz0, sz1;
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int ans = -2100000000;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      sz0 = sz1 = 0;
      for (int i = l; i <= r; i++) b[sz0++] = a[i];
      for (int i = 1; i < l; i++) c[sz1++] = a[i];
      for (int i = r + 1; i <= n; i++) c[sz1++] = a[i];
      sort(b, b + sz0);
      sort(c, c + sz1);
      int p1 = 0, p2 = sz1 - 1;
      int cnt = 10;
      while (p1 < sz0 && p2 >= 0 && cnt) {
        if (c[p2] > b[p1])
          b[p1] = c[p2];
        else
          break;
        cnt--;
        p1++;
        p2--;
      }
      int res = 0;
      for (int i = 0; i < sz0; i++) res += b[i];
      ans = max(ans, res);
    }
  }
  printf("%d\n", ans);
  return 0;
}
