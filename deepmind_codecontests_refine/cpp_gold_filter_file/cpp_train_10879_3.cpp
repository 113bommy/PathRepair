#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long n, l, k, cnt, ans, num, p, c1, c2;
long long a[1000005], b[1000005], dp[2][1000005], tem[1000005], c[1000006];
map<long long, int> mp;
int main() {
  scanf("%I64d%I64d%I64d", &n, &l, &k);
  long long x;
  for (int i = 0; i < n; i++) {
    scanf("%I64d", &x);
    a[i] = b[i] = x;
  }
  sort(b, b + n);
  cnt = 0;
  for (int i = 0; i < n; i++)
    if (mp.find(b[i]) == mp.end()) mp[b[i]] = ++cnt;
  for (int i = 0; i < n; i++) b[i] = mp[a[i % n]];
  num = l / n;
  p = l % n;
  for (int i = 0; i < p; i++) c[i] = b[i];
  sort(b, b + n);
  sort(c, c + p);
  for (int i = 0; i < n; i++) dp[0][b[i]] = i + 1;
  ans = l % MOD;
  cnt = 0;
  c1 = num;
  c2 = num;
  k = min(k, num + (p == 0 ? 0 : 1));
  for (int i = 2; i <= k; i++) {
    cnt++;
    c2 = (num - i + 1) % MOD;
    c1 = (c2 + 1) % MOD;
    if (i <= num) {
      for (int j = 0; j < n; j++)
        if (j == 0)
          dp[cnt & 1][b[j]] = (dp[(cnt - 1) & 1][b[j]]) % MOD;
        else
          dp[cnt & 1][b[j]] =
              (dp[cnt & 1][b[j - 1]] + dp[(cnt - 1) & 1][b[j]]) % MOD;
      ans = (ans + dp[cnt & 1][b[n - 1]] * c2 % MOD) % MOD;
    }
    for (int j = 0; j < p; j++)
      if (j == 0)
        tem[c[j]] = (dp[(cnt - 1) & 1][c[j]]) % MOD;
      else
        tem[c[j]] = (tem[c[j - 1]] + dp[(cnt - 1) & 1][c[j]]) % MOD;
    if (p > 0) ans = (ans + tem[c[p - 1]] % MOD) % MOD;
  }
  printf("%I64d\n", ans);
}
