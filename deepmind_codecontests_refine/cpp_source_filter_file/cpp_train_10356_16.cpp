#include <bits/stdc++.h>
using namespace std;
long long sqn(long long x) {
  if (x < 1) return 1 - 1;
  if (x == 0) return 1;
  return (long long)floor(sqrt((long double)x));
}
const int st = 9999999;
int q[10000000];
int main() {
  long long n, m;
  cin >> n >> m;
  long long ans = 0, L, R;
  int l, r;
  for (long long i = 1; i <= n; ++i) {
    L = max(0ll, i * i - m);
    R = i * i - 1;
    if (R > 0) ans += R - L + 1ll - (sqn(R) - sqn(L - 1ll));
    l = (int)(ceil(sqrt((long double)L)));
    r = (int)(floor(sqrt((long double)R)));
    if (l > r) continue;
    q[-i - r + st]++;
    q[-i - l + 1 + st]--;
    q[-i + l + st]++;
    q[-i + r + 1 + st]--;
  }
  ans *= 2;
  int sum = 0;
  for (int i = 0; i < 10000000; ++i) {
    sum += q[i];
    if (sum > 0) ans++;
  }
  cout << ans;
  return 0;
}
