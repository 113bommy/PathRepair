#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0;
  int f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + (ch ^ 48);
  return x * f;
}
void print(long long x) {
  if (x < 0) x = -x, putchar('-');
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}
long long a, n, phi, p, tmp, ans, l1, l2, fla;
char s1[1000010], s2[1000010];
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % p;
    a = a * a % p;
    b >>= 1;
  }
  return ans;
}
signed main() {
  scanf("%s %s", s1 + 1, s2 + 1), p = read();
  l1 = strlen(s1 + 1), l2 = strlen(s2 + 1);
  phi = tmp = p, a = n = fla = 0;
  for (int i = 2; i * i <= p; i++)
    if (tmp % i == 0) {
      phi -= phi / i;
      while (tmp % i == 0) tmp /= i;
    }
  for (int i = 1; i <= l1; i++) a = (a * 10 + (s1[i] ^ 48)) % p;
  if (tmp > 1) phi -= phi / tmp;
  for (int i = l2; i >= 1; i--)
    if (s2[i] == 0)
      s2[i] = '9';
    else {
      s2[i]--;
      break;
    }
  for (int i = 1; i <= l2; i++)
    n = n * 10 + (s2[i] ^ 48), fla += (n >= phi), n %= phi;
  if (fla) n += phi;
  ans = ((a - 1) * qpow(a, n) % p + p) % p;
  if (!ans) ans = p;
  ::print(ans), putchar('\n');
}
