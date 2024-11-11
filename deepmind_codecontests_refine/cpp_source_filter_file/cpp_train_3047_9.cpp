#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, r1, r2, r3, d;
  cin >> n >> r1 >> r2 >> r3 >> d;
  long long a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long adv[n + 1], ret[n + 1];
  adv[0] = ret[n] = 0;
  ret[n - 1] = min(
      {a[n - 1] * r1 + r3, a[n - 1] * r1 + 2 * r1 + 2 * d, r2 + r1 + 2 * d});
  for (int i = 1; i <= n; i++) {
    adv[i] = adv[i - 1] + a[i - 1] * r1 + r3 + d;
    if (i - 1 >= 0)
      adv[i] = min(adv[i], adv[i - 2] + min(a[i - 2] * r1 + r1, r2) +
                               min(a[i - 1] * r1 + r1, r2) + 2 * r1 + 4 * d);
  }
  adv[n] -= d;
  for (int i = n - 2; i >= 0; i--) {
    ret[i] = ret[i + 1] + min(a[i] * r1 + 2 * r1, r2 + r1) + 2 * d;
  }
  long long sol = LLONG_MAX;
  for (int i = 0; i <= n; i++) sol = min(sol, adv[i] + ret[i]);
  cout << sol << "\n";
  return 0;
}
