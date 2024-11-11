#include <bits/stdc++.h>
using namespace std;
inline int init() {
  int now = 0, ju = 1;
  char c;
  bool flag = false;
  while (1) {
    c = getchar();
    if (c == '-')
      ju = -1;
    else if (c >= '0' && c <= '9') {
      now = now * 10 + c - '0';
      flag = true;
    } else if (flag)
      return now * ju;
  }
}
inline long long llinit() {
  long long now = 0, ju = 1;
  char c;
  bool flag = false;
  while (1) {
    c = getchar();
    if (c == '-')
      ju = -1;
    else if (c >= '0' && c <= '9') {
      now = now * 10 + c - '0';
      flag = true;
    } else if (flag)
      return now * ju;
  }
}
char str[200005];
long long mod;
long long fastpow(long long base, long long power) {
  long long ret = 1;
  for (; power; power >>= 1) {
    if (power & 1) {
      ret = (ret * base) % mod;
    }
    base = (base * base) % mod;
  }
  return ret;
}
int main() {
  long long ans = 0x7fffffffffffll, nowans = 0;
  scanf("%s", str + 1);
  mod = llinit();
  int n = strlen(str + 1);
  for (int i = 1; i <= n; i++) {
    nowans *= 10;
    nowans %= mod;
    nowans += (str[i] - '0');
    nowans %= mod;
  }
  ans = min(ans, nowans);
  for (int i = 1; i <= n - 1; i++) {
    nowans -= (1LL * (str[i] - '0') * fastpow(10, n - 1));
    while (nowans < 0) nowans += mod;
    nowans %= mod;
    nowans *= 10;
    nowans %= mod;
    nowans += (str[i] - '0');
    nowans %= mod;
    if (str[i + 1] != '0') {
      ans = min(ans, nowans);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
