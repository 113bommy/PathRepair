#include <bits/stdc++.h>
using namespace std;
long long a[350001], pref[350001], n, i, ans;
long long mod(long long a) { return a % 1000000007; }
long long st(long long a, long long b) {
  if (b == 0) return 1LL;
  long long c = st(a, b / 2);
  if (b % 2 != 0)
    return mod(mod(a * c) * c);
  else
    return mod(c * c);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + 1 + n);
  for (i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
  for (i = 2; i <= n; i++)
    ans = mod(ans +
              mod((pref[n] - pref[n - i + 1] - pref[i - 1]) * st(2LL, i - 2)));
  cout << ans << '\n';
  return 0;
}
