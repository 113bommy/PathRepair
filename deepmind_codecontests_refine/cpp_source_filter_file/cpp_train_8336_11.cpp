#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  char ch = getchar();
  long long p = 1, data = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    data = data * 10 + (ch ^ 48);
    ch = getchar();
  }
  return p * data;
}
inline long long qpow(long long a, long long b) {
  long long r = 1;
  while (b) {
    if (b & 1) r = a * r;
    a = a * a;
    b >>= 1;
  }
  return r;
}
inline long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
inline long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
void exgcd(long long a, long long b, long long &x, long long &y) {
  if (!b)
    x = 1, y = 0;
  else {
    exgcd(b, a % b, y, x);
    y -= x * (a / b);
  }
}
const int mod = 1e9 + 7;
const int maxn = 120005;
long long a[maxn], ans;
unordered_map<long long, int> mp;
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), mp[a[i]]++;
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    for (long long b = 1; b <= 1e9; b *= 2)
      if ((b > a[i] && mp[b - a[i]] && b - a[i] != a[i]) ||
          (b > a[i] && mp[a[i]] >= 2 && a[i] * 2 == b))
        flag = 1;
    if (!flag) ans++;
  }
  printf("%lld\n", ans);
  return 0;
}
