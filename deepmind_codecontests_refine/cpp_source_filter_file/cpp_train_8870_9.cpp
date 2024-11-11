#include <bits/stdc++.h>
const int MOD = 1e9 + 7;
const int MAX = 1e9 + 7;
const int MIN = -1e9 + 7;
using namespace std;
const int mxN = 355;
const int inf = 2e9;
const double Pi = acos(-1);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, a, b, k;
  cin >> n >> a >> b >> k;
  long long x;
  long long kmod[n + 5];
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x > a + b) {
      if (x % (a + b) == 0)
        x = a + b;
      else
        x = x % (a + b);
    }
    if (x <= a) {
      kmod[i] = 0;
    } else if (a + b >= x) {
      x -= a;
      kmod[i] = x / a + ((x > (x / a) * a) ? 1 : 0);
    }
  }
  sort(kmod, kmod + n);
  int i = 0;
  long long ans = 0;
  while (k >= kmod[i]) {
    ans++;
    k -= kmod[i];
    i++;
  }
  cout << ans << "\n";
  return 0;
}
