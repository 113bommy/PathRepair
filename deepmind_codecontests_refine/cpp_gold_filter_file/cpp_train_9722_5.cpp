#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const long long MOD = 1e9 + 7;
char s[N], w[N];
long long ret1, ret2, ret, ans;
int main() {
  int n;
  scanf("%d %s %s", &n, s + 1, w + 1);
  ans = ret1 = ret2 = ret = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i] == '?') ans = ans * 10 % MOD;
    if (w[i] == '?') ans = ans * 10 % MOD;
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == '?' && w[i] == '?') {
      ret1 = ret1 * 55 % MOD;
      ret2 = ret2 * 55 % MOD;
      ret = ret * 10 % MOD;
    } else if (s[i] == '?') {
      ret1 = ret1 * ('9' - w[i] + 1) % MOD;
      ret2 = ret2 * (w[i] - '0' + 1) % MOD;
    } else if (w[i] == '?') {
      ret1 = ret1 * (s[i] - '0' + 1) % MOD;
      ret2 = ret2 * ('9' - s[i] + 1) % MOD;
    } else {
      if (s[i] < w[i]) ret1 = ret = 0;
      if (s[i] > w[i]) ret2 = ret = 0;
    }
  }
  ans = ((ans - ret1 - ret2 + ret) % MOD + MOD) % MOD;
  printf("%I64d\n", ans);
}
