#include <bits/stdc++.h>
using namespace std;
int fa[400010][21], sum[400010][21];
int main() {
  int q;
  scanf("%d", &q);
  fa[2][0] = 1;
  long long ans = 0, res, tot = 2;
  while (q--) {
    int cas;
    long long p, q;
    scanf("%d%lld%lld", &cas, &p, &q);
    long long r = p ^ ans, w = q ^ ans;
    r++;
    if (cas == 1) {
      tot++;
      fa[tot][0] = r, sum[tot][0] = w;
      while (sum[fa[tot][0]][0] < sum[tot][0] && fa[tot][0] > 1)
        fa[tot][0] = fa[fa[tot][0]][0];
      for (int i = 1; i < 20; ++i) {
        fa[tot][i] = fa[fa[tot][i - 1]][i - 1];
        sum[tot][i] = sum[tot][i - 1] + sum[fa[tot][i - 1]][i - 1];
      }
    } else {
      res = 0;
      for (int i = 19; ~i; --i)
        if (fa[r][i] && sum[r][i] <= w) {
          w -= sum[r][i];
          res += (1 << i);
          r = fa[r][i];
        }
      printf("%lld\n", res);
      ans = res;
    }
  }
  return 0;
}
