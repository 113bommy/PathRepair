#include <bits/stdc++.h>
#pragma GCC optimize(2)
const long long mod = 1e9 + 7;
const int maxn = 1e6 + 5;
const int INF = 1e9 + 7;
using namespace std;
const double eps = 1e-8;
long long n, m;
int prime[maxn];
int vis[maxn];
long long num[maxn];
long long cnt = 0;
map<long long, long long> mp;
long long a[maxn], b[maxn];
void restart() {
  vis[1] = 1;
  for (int i = 2; i < 1005; i++) {
    if (!vis[i]) {
      prime[++cnt] = i;
      for (int k = i * 2; k < 1005; k += i) vis[k] = 1;
    }
  }
}
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a;
    b /= 2;
    a = a * a;
  }
  return ans;
}
int main() {
  restart();
  scanf("%lld%lld", &n, &m);
  mp.clear();
  for (int i = 1; i <= n; i++) scanf("%lld", &num[i]);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    long long temp = num[i];
    long long now = 1;
    for (int k = 1; k <= cnt; k++) {
      int cot = 0;
      while (temp % prime[k] == 0) {
        temp /= prime[k];
        cot++;
      }
      cot %= m;
      if (cot) now = now * qpow(prime[k], cot);
    }
    if (temp > 1) now *= temp;
    a[i] = now;
    mp[a[i]]++;
    b[i] = 1;
    for (int k = 1; k <= cnt; k++) {
      int cot = 0;
      while (now % prime[k] == 0) {
        now /= prime[k];
        cot++;
      }
      cot %= m;
      if (cot) b[i] = b[i] * qpow(prime[k], m - cot);
    }
    if (now > 1) b[i] *= qpow(now, m - 1);
    if (b[i] == a[i])
      res += mp[b[i]] - 1;
    else
      res += mp[b[i]];
  }
  printf("%lld\n", res);
  return 0;
}
