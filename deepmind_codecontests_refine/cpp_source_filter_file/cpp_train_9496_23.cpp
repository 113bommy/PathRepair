#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
long long fpow(long long x, long long y, long long mod) {
  long long ans = 1ll;
  for (; y; y >>= 1) {
    if (y & 1) ans = ans * x % mod;
    x = x * x % mod;
  }
  return ans;
}
const long long maxd = 205;
char s[maxd], ans[maxd];
long long a[105][30], b[105][30], c[105][30], num[26], now[26];
int main() {
  long long n;
  scanf("%lld", &n);
  if (n == 1) {
    cout << "? 1 1" << endl;
    cout.flush();
    scanf("%s", s);
    printf("! %s", s);
    return 0;
  }
  cout << "? 2 " << n / 2 + 1 << endl;
  cout.flush();
  for (long long i = 0; i < (n / 2 + 1) * (n / 2) / 2; i++) {
    scanf("%s", s);
    long long len = strlen(s);
    for (long long j = 1; j <= len; j++) a[len][s[j - 1] - 'a']++;
  }
  cout << "? 1 " << n / 2 + 1 << endl;
  cout.flush();
  for (long long i = 0; i < (n / 2 + 2) * (n / 2 + 1) / 2; i++) {
    scanf("%s", s);
    long long len = strlen(s);
    for (long long j = 1; j <= len; j++) b[len][s[j - 1] - 'a']++;
  }
  for (long long i = 1; i <= (n / 2) + 1; i++) {
    for (long long j = 0; j <= 25; j++) {
      if (a[i][j] != b[i][j]) {
        ans[i] = 'a' + j;
        for (long long k = i + 1; k <= n / 2 + 1; k++) a[k][j]++;
        break;
      }
    }
  }
  cout << "? 1 " << n << endl;
  cout.flush();
  for (long long i = 0; i < (n + 1) * (n) / 2; i++) {
    scanf("%s", s);
    long long len = strlen(s);
    for (long long j = 1; j <= len; j++) c[len][s[j - 1] - 'a']++;
  }
  for (long long i = 2; i <= n / 2 + 1; i++) {
    for (long long j = 0; j <= 25; j++) {
      now[j] = c[1][j] - (c[i][j] - c[i - 1][j]);
    }
    for (long long j = 0; j <= 25; j++) {
      if (num[j] != now[j] && (ans[i - 1] - 'a' != j || now[j] - ans[j] > 1))
        ans[n - i + 2] = 'a' + j;
      num[j] = now[j], now[j] = 0;
    }
  }
  printf("! %s", ans + 1);
  return 0;
}
