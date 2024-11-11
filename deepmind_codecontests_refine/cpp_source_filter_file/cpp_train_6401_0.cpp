#include <bits/stdc++.h>
using namespace std;
const int Maxn = 300020;
long long sum[Maxn];
int cntl[1000020], cntr[1000020], vial[1000020], viar[1000020];
int a[Maxn];
int n, k;
int tot;
long long solve(int l, int r) {
  if (l == r) return 0;
  if (r == l + 1) return (a[l] + a[r] - max(a[l], a[r])) % k == 0;
  int mid = (l + r) >> 1;
  long long ret = 0;
  ret += solve(l, mid);
  ret += solve(mid + 1, r);
  tot++;
  int L = mid, R = mid + 1, curmax = -1;
  for (; L >= l || R <= r;) {
    bool flag = 0;
    if (R > r)
      flag = 0;
    else if (L < l)
      flag = 1;
    else if (a[R] < a[l])
      flag = 1;
    if (!flag) {
      curmax = a[L];
      while (L >= l && a[L] <= curmax) {
        if (vial[sum[L - 1]] < tot) {
          cntl[sum[L - 1]] = 0;
          vial[sum[L - 1]] = tot;
        }
        cntl[sum[L - 1]]++;
        if (viar[(sum[L - 1] + curmax) % k] == tot)
          ret += cntr[(sum[L - 1] + curmax) % k];
        L--;
      }
    } else {
      curmax = a[R];
      while (R <= r && a[R] <= curmax) {
        if (viar[sum[R]] < tot) {
          cntr[sum[R]] = 0;
          viar[sum[R]] = tot;
        }
        cntr[sum[R]]++;
        if (vial[((sum[R] - curmax) % k + k) % k] == tot)
          ret += cntl[((sum[R] - curmax) % k + k) % k];
        R++;
      }
    }
  }
  return ret;
}
void scanf(int &x) {
  char c;
  while ((c = getchar()) < '0' || c > '9')
    ;
  x = c - '0';
  while ((c = getchar()) >= '0' && c <= '9') x = x * 10 + c - '0';
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf(a[i]);
    sum[i] = sum[i - 1] + a[i];
    sum[i] %= k;
  }
  printf("%lld\n", solve(1, n));
}
