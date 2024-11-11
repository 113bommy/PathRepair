#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int dev[maxn];
long long qpow(long long base, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) {
      ans *= base;
      ans %= mod;
    }
    base = base * base;
    base %= mod;
    n /= 2;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  int u, v;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &u, &v);
    dev[u]++, dev[v]++;
  }
  int num = 0;
  for (int i = 1; i <= n; i++) {
    if (dev[i] == 1) {
      num++;
    }
  }
  long long ans = 0;
  ans += ((n - num) * qpow(2, n - num)) % mod;
  ans %= mod;
  ans += (num * qpow(2, n - num + 1)) % mod;
  ans %= mod;
  cout << ans;
  return 0;
}
