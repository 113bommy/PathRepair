#include <bits/stdc++.h>
using namespace std;
const long long M = 1000000007;
const long long C = 2e5 + 10;
long long D[2 * C + 100];
long long D2[2 * C + 100];
long long a, b, k, t;
void refresh() {
  long long sum = 0;
  for (long long i = -C; i <= C; i++) {
    sum += D[C + i];
    sum %= M;
    if (C + i >= 2 * k + 1) {
      sum += M;
      sum -= D[C + i - 2 * k - 1];
    }
    sum %= M;
    if (C + i - k >= 0) {
      D2[C + i - k] = sum;
    }
  }
  for (long long i = -C; i <= C; i++) {
    D[C + i] = D2[C + i];
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> a >> b >> k >> t;
  t *= 2;
  D[C + a - b] = 1;
  while (t--) {
    refresh();
  }
  long long ans = 0;
  for (long long i = 1; i <= C; i++) {
    ans += D[C + i];
    ans %= M;
  }
  cout << ans;
}
