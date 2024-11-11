#include <bits/stdc++.h>
using namespace std;
long long n, k, i, j, tot, s, Ans, Now, Num[1005];
long long a[100005], f[1005][1005];
long long check(long long x);
long long sumi(long long a, long long b);
int main() {
  scanf("%I64d %I64d", &n, &k);
  for (i = 1; i <= n; i++) scanf("%I64d", &a[i]);
  sort(a + 1, a + n + 1);
  s = n;
  for (i = 1; i <= n; i++)
    if (check(a[i]) == 1) {
      s--;
      if (a[i] != a[i - 1])
        tot++, Num[tot] = 1;
      else
        Num[tot]++;
    }
  f[0][0] = 1;
  for (i = 1; i <= tot; i++) {
    f[i][0] = 1;
    for (j = 1; j <= i; j++)
      f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * Num[i]) % 1000000007;
  }
  Ans = 0;
  if (s + tot < k) {
    printf("0\n");
    return 0;
  }
  for (i = 0; i <= s; i++) {
    if (i > k) break;
    if (i == 0)
      Now = 1;
    else {
      Now *= (s - i + 1);
      Now %= 1000000007;
      Now *= sumi(i, 1000000007 - 2);
      Now %= 1000000007;
    }
    if (k - i <= tot) {
      Ans += (Now * f[tot][k - i] % 1000000007);
      Ans %= 1000000007;
    }
  }
  printf("%I64d\n", Ans);
  return 0;
}
long long check(long long x) {
  long long tag = 1;
  while (x > 0) {
    if (x % 10 != 4 && x % 10 != 7) tag = 0;
    x /= 10;
  }
  return tag;
}
long long sumi(long long a, long long b) {
  long long ret = 1, c = a, i;
  for (i = 1; i <= b; (i <<= 1)) {
    if ((b & i) > 0) ret *= c, ret %= 1000000007;
    c *= c, c %= 1000000007;
  }
  return ret;
}
