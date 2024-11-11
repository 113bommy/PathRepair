#include <bits/stdc++.h>
using namespace std;
const long long inf = (long long)1e18 + 1ll;
const int maxn = 100050;
vector<int> G[maxn];
long long f[66];
long double Pow(long long x, long long n) {
  long double ans = 1, base = x;
  while (n) {
    if (n & 1) ans = ans * base;
    base = base * base;
    n >>= 1;
    if (ans >= inf) return inf;
  }
  return ans;
}
long long solve(long long n, int k) {
  long long ans = exp((long double)log((long double)n) / k);
  ans = max(0ll, ans - 2);
  while (Pow(ans + 1, k) <= n) ans++;
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    long long n;
    scanf("%lld", &n);
    for (int i = 60; i >= 1; --i) {
      f[i] = solve(n, i);
      for (int j = i + i; j <= 60; j += i) f[i] -= f[j];
    }
    cout << f[1] + 1 << endl;
  }
  return 0;
}
