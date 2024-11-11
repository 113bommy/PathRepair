#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 100;
const long long mod = 1e9 + 7;
char s1[MAXN];
char s2[MAXN];
int a[26];
int b[26];
long long p[MAXN];
void init() {
  p[0] = 1;
  for (int i = 1; i < MAXN; i++) p[i] = p[i - 1] * i % mod;
}
long long f(int index, int len, char *aim) {
  long long ans = 0;
  if (index == len) return 1;
  for (int i = 0; i < 26; i++) {
    if (!a[i]) continue;
    if (i < aim[index] - 'a') {
      ans += a[i] * p[len - index - 1] % mod;
      ans %= mod;
    } else if (i > aim[index] - 'a') {
      return ans;
    } else {
      a[i]--;
      ans += (a[i] + 1) * f(index + 1, len, aim) % mod;
      ans %= mod;
      a[i]++;
    }
  }
  return ans;
}
long long ex_gcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ex_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
long long inverse(long long a) {
  long long x, y;
  long long d = ex_gcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}
int main() {
  init();
  scanf("%s", s1);
  scanf("%s", s2);
  if (strcmp(s1, s2) > 0) {
    cout << 0 << "\n";
    return 0;
  }
  char *ptr = s1;
  char *_ptr = s2;
  while (*ptr) {
    a[*ptr - 'a']++;
    b[*_ptr - 'a']++;
    _ptr++;
    ptr++;
  }
  int flag = 1;
  for (int i = 0; i < 26; i++) {
    if (a[i] != b[i]) {
      flag = 0;
      break;
    }
  }
  long l = f(0, strlen(s1), s1);
  for (int i = 0; i < 26; i++) {
    l = l * inverse(p[a[i]]) % mod;
  }
  long r = f(0, strlen(s2), s2);
  for (int i = 0; i < 26; i++) {
    r = r * inverse(p[a[i]]) % mod;
  }
  cout << (((r - l - flag) % mod) + mod) % mod << "\n";
}
