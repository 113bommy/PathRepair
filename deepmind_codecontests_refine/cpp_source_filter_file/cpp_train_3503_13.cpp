#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)(2e5) + 2;
const int MOD = (int)(1e9) + 7;
long long n, k, A, B;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k >> A >> B;
  if (k == 1) {
    cout << n - 1;
    return 0;
  }
  long long x = n;
  long long ans = 0;
  while (x > 1) {
    if (x < k) {
      ans += (x - 1) * A;
      break;
    }
    ans += (x % k) * A;
    x -= x % k;
    ans += min(B, A * (x - x / k));
    x /= k;
  }
  cout << ans;
  return 0;
}
