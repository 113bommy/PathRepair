#include <bits/stdc++.h>
using namespace std;
long long a[1000000 + 10];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, k, x;
  cin >> n >> x >> k;
  for (int i = (0); i < (n); i++) cin >> a[i];
  sort(a, a + n);
  long long ans = 0;
  for (int i = (0); i < (n); i++) {
    long long t = (a[i] - 1) / x;
    long long l = k == 0 ? a[i] : (t + k) * x, r = (t + k + 1) * x;
    int pos = upper_bound(a, a + n, r) - a;
    int pos1 = lower_bound(a, a + n, l) - a;
    ans += max(0, pos - pos1);
  }
  cout << ans << "\n";
  return 0;
}
