#include <bits/stdc++.h>
using namespace std;
int n, a[110000], b[110000], num[20];
long long calc(int t) {
  long long p = t;
  b[0] = 0;
  while (p) {
    b[++b[0]] = p % 10;
    p /= 10;
  }
  long long h = t;
  long long ret = 0, k = 0, u = 1, w = 0;
  for (int i = 1; i <= 9; i++) {
    k = (k + b[i] * u % 998244353) % 998244353;
    u = (u * 100) % 998244353;
    t = t / 10;
    if (i <= b[0]) w = (t * u % 998244353 + k) % 998244353;
    ret = (ret + w * num[i]) % 998244353;
  }
  u = 10;
  k = 0;
  w = 0;
  for (int i = 1; i <= 9; i++) {
    if (i <= b[0]) w = (h * u % 998244353 + k) % 998244353;
    ret = (ret + w * num[i]) % 998244353;
    k = (k + b[i] * u % 998244353) % 998244353;
    u = u * 100 % 998244353;
    h /= 10;
  }
  return ret;
}
int digit(int t) {
  int ret = 0;
  while (t) {
    ret++;
    t /= 10;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    num[digit(a[i])]++;
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = (ans + calc(a[i])) % 998244353;
  }
  cout << ans;
  return 0;
}
