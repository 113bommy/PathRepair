#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T, n, s, i, j;
  long long int required = 1e6;
  cin >> n >> s;
  long long int x[n + 1], y[n + 1], k[n + 1];
  long double r[n + 1], total[n + 1], d;
  long double lower, upper, mid, ans;
  long long int L, R, m;
  multiset<pair<long double, long long int> > ms;
  pair<long double, long long int> curr;
  for (i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> k[i];
    r[i] = sqrt(x[i] * x[i] + y[i] * y[i]);
    ms.insert(make_pair(r[i], k[i]));
  }
  total[0] = 0.0;
  for (i = 1; i <= n; i++) {
    curr = *ms.begin();
    ms.erase(ms.begin());
    r[i] = curr.first;
    k[i] = curr.second;
    total[i] = total[i - 1] + k[i];
  }
  bool found = 0;
  lower = 0.0;
  upper = r[n];
  ans = r[n];
  while (abs(upper - lower) > 1e-12) {
    mid = (lower + upper) / 2.0;
    L = 1;
    R = n;
    j = 0;
    while (L <= R) {
      m = (L + R) >> 1;
      if (r[m] <= mid) {
        j = max(j, m);
        L = m + 1;
      } else
        R = m - 1;
    }
    if (s + total[j] >= required) {
      ans = min(ans, mid);
      upper = mid;
      found = 1;
    } else
      lower = mid;
  }
  if (!found) {
    cout << "-1" << endl;
    return 0;
  }
  cout << fixed << setprecision(16);
  cout << ans << endl;
  return 0;
}
