#include <bits/stdc++.h>
using namespace std;
long long n, m, l, j, t, S, k, x, b, p[2100000], v[2100000], a[2100000],
    sum[2010000];
string s;
long long K(long long b, long long p) {
  x = 1, k = 1000000007;
  while (t) {
    if (t % 2) x = x * b % k;
    b = b * b % k;
    t /= 2;
  }
  return x % k;
}
signed main() {
  cin >> n >> m >> s, l = s.size(), s = " " + s;
  for (long long i = 2; i <= l; i++) {
    while (j > 0 && s[i] != s[j + 1]) j = p[j];
    if (s[i] == s[j + 1]) j++;
    p[i] = j;
  }
  for (long long i = l; i; i = p[i]) v[i] = 1;
  for (long long i = 1; i <= m; i++)
    scanf("%lld", &a[i]), sum[a[i]]++, sum[a[i] + l]--;
  for (long long i = 2; i <= m; i++)
    if (a[i] - a[i - 1] < l && !v[a[i - 1] + l - a[i]]) return printf("0"), 0;
  t = S = 0;
  for (long long i = 1; i <= n; i++) S += sum[i], t += (S == 0);
  if (t == 0)
    return puts("1"), 0;
  else
    cout << K(26, t);
  return 0;
}
