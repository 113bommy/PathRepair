#include <bits/stdc++.h>
using namespace std;
const long long modc = 1000000007;
long long n, m;
long long poww(long long x, long long n) {
  if (n == 0) return 1;
  long long res = poww(x, n / 2);
  (res *= res) %= modc;
  if (n & 1) (res *= x) %= modc;
  return res;
}
const int maxn = 1000005;
long long jc[maxn], njc[maxn];
int main() {
  cin >> n >> m;
  jc[0] = 1;
  njc[0] = poww(jc[0], modc - 2);
  for (int i = 1; i <= n; i++) {
    jc[i] = jc[i - 1] * i % modc;
    njc[i] = poww(jc[i], modc - 2);
  }
  long long ans = poww(m, n);
  for (int s = 1; s <= n; s++) {
    long long tans = poww(m - 1, n - s) * poww(m, s) % modc;
    (tans *= jc[n] * njc[s - 1] % modc * njc[n - s + 1] % modc) %= modc;
    (ans += tans) %= modc;
  }
  cout << ans;
  return 0;
}
