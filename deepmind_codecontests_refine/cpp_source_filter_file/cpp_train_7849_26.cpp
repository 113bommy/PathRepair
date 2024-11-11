#include <bits/stdc++.h>
using namespace std;
long long prime[7] = {2, 3, 5, 7, 11, 13};
long long ans[10000];
long long ak = 0;
long long N;
long long v;
int flag[7];
int maxx_fl[7];
void dfs(long long top, long long d, long long ap, bool fla) {
  if (ap > top)
    return;
  else if (d == -1 && fla) {
    int i, j;
    ans[ak++] = ap;
    return;
  } else if (d == -1) {
    ak++;
    return;
  } else {
    long long cf = top;
    long long as = ap;
    while (cf > prime[d]) {
      cf /= prime[d];
      as *= prime[d];
      flag[d]++;
      dfs(cf, d - 1, as, fla);
    }
    dfs(top, d - 1, ap, fla);
  }
}
int main(void) {
  long long n;
  while (scanf("%I64d", &n) != EOF) {
    memset(flag, 0, sizeof(flag));
    long long i, j;
    ak = 0;
    v = n;
    for (i = 0; i <= 5; i++) {
      ak = 0;
      dfs(2 * n * n, i, 1, false);
      if (ak >= v) {
        break;
      }
    }
    ak = 0;
    dfs(2 * n * n, i, 1, true);
    printf("%I64d", ans[0]);
    for (i = 1; i < n; i++) printf(" %I64d", ans[i]);
    printf("\n");
  }
  return 0;
}
