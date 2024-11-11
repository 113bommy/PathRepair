#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long c;
char sa[N], sb[N];
long long readpow(char *s, long long m) {
  long long ans = 0;
  int ls = strlen(s + 1);
  for (int i = 1; i <= ls; i++) ans = ((ans * 10) + s[i] - '0') % m;
  return ans % m;
}
long long euler_phi(long long n) {
  long long m = (long long)sqrt(n + 0.5), ans = n;
  for (int i = 2; i <= m; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  if (n > 1) ans = ans / n * (n - 1);
  return ans;
}
long long qpow(long long a, long long b, long long m) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
int main() {
  scanf("%s %s %lld", sa + 1, sb + 1, &c);
  int l1 = strlen(sa + 1), l2 = strlen(sb + 1);
  long long phic = euler_phi(c);
  long long b = readpow(sa, c);
  for (int i = l2; i; i--) {
    if (sb[i] != '0') {
      sb[i]--;
      break;
    } else
      sb[i] = '9';
  }
  long long n = 0;
  bool flag = 0;
  for (int i = 1; i <= l2; i++) {
    n = (n * 10) + sb[i] - '0';
    if (n >= phic) flag = 1;
    n %= phic;
  }
  if (flag) n += phic;
  long long ans = ((b - 1) % c * qpow(b, n, c) + c) % c;
  if (ans)
    printf("%lld", ans);
  else
    printf("%lld", c);
}
