#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int inf = 1e18;
const long long int N = 3e5 + 5;
long long int mask[N];
long long int sum[N];
void HyperBeast() {
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) {
    long long int x;
    cin >> x;
    mask[i] = __builtin_popcountll(x);
    sum[i] = sum[i - 1] + mask[i];
    sum[i] %= 2;
  }
  long long int odd = 0, even = 1;
  long long int ans = 0;
  for (long long int i = 1; i <= n; i++) {
    if (sum[i] % 2 == 0) {
      ans += even;
      even++;
    } else {
      ans += odd;
      odd++;
    }
  }
  for (long long int i = 1; i <= n; i++) {
    long long int g = 0, mx = 0;
    for (long long int j = i; j <= min(n, i + 70); j++) {
      g += mask[i];
      mx = max(mx, mask[i]);
      if (g % 2 == 0 and 2 * mx > g) {
        ans--;
      }
    }
  }
  cout << ans;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  while (T--) {
    HyperBeast();
    cout << '\n';
  }
}
