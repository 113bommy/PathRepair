#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);
int n, a[300300];
int dp[33][300300];
int calc(int bon, int ind) {
  if (ind == n) return 0;
  int &res = dp[bon][ind];
  if (res != -1) return res;
  res = a[ind] + calc(min(bon + a[ind] / 10, 31), ind + 1);
  for (int i = 1; i <= bon && i <= a[ind]; i++) {
    res = min(res, a[ind] - i + calc(bon - i, ind + 1));
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
    a[i] /= 100;
  }
  memset(dp, -1, sizeof dp);
  printf("%d\n", calc(0, 0) * 100);
  return 0;
}
