#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
const int MOD = 1e9 + 7;
const long long INF = 1e18 + 8;
const int maxn = 1e5 + 5;
int a[maxn], vis[maxn];
int main() {
  long long x, y, n, d, j, z, m, w,
      minn = 0, mi = 0, ma = 0, maxx = 0, temp1 = 0, temp2 = 0, temp = 0,
      sum = 0, sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, flag1 = 0, flag2 = 0,
      flag3 = 0, flag4 = 0, flag = 0, len2 = 0, len1 = 0, len = 0;
  scanf("%lld", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > maxx) {
      maxx = a[i];
    }
  }
  flag = 1;
  sum = a[0];
  while (flag) {
    ma = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] >= ma) {
        ma = i;
      }
    }
    if (ma == 0) {
      flag = 0;
    } else {
      a[ma]--;
      a[0]++;
    }
  }
  printf("%d\n", a[0] - sum);
  return 0;
}
