#include <bits/stdc++.h>
using namespace std;
char s[601000];
long long m;
long long ans = 0;
long long len;
long long ll;
long long mod = 1;
long long reget(long long x) {
  long long reans = (10 * (ll - ((long long)(s[x] - '0') * mod) % m + m) % m +
                     (long long)(s[x] - '0') + m) %
                    m;
  return reans;
}
long long get(long long l, long long r) {
  long long t = l;
  long long temp = 0;
  while (t <= r) {
    if (temp >= m) temp = (temp % m + m) % m;
    while (temp < m && t <= r) {
      temp = temp * 10 + (long long)(s[t] - '0');
      t++;
    }
  }
  temp = (temp + m) % m;
  return temp;
}
int main() {
  cin >> s;
  len = strlen(s);
  cin >> m;
  ans = get(0, len - 1);
  for (long long i = 1; i < len; i++) mod = (mod * 10 + m) % m;
  ll = ans;
  for (long long i = 0; i < len - 1; i++) {
    ll = reget(i);
    if (s[i + 1] == '0') continue;
    ans = min(ll, ans);
  }
  printf("%I64d\n", ans);
  return 0;
}
