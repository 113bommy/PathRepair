#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, m;
  scanf("%d%d", &n, &m);
  long long MOD = 1e9 + 7, ret = 1, two = 1;
  for (int i = 0; i < m; i++) two = two * 2 % MOD;
  for (int i = 1; i <= n; i++) ret = ret * (--two) % MOD;
  printf("%I64d\n", ret);
  return 0;
}
