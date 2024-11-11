#include <bits/stdc++.h>
using namespace std;
bitset<63> t1[3610], t2[3610];
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, h;
  cin >> n >> h;
  vector<pair<long long, long long> > v(n);
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.begin(), v.end());
  for (long long i = 0; i < n; i++) a[i] = v[i].first;
  long long ans = a[n - 1] + a[n - 2] - a[0] - a[1];
  long long ind = 0;
  if (n == 2) {
    cout << 0 << "\n";
    cout << "0 0";
    return 0;
  }
  for (long long i = 1; i <= n - 1; i++) {
    long long mx = max(a[n - 1] + a[n - 2], a[n - 1] + a[i] + h);
    if (i == n - 1) mx = max(a[n - 1] + a[n - 2], a[0] + a[n - 1] + h);
    long long mn;
    if (i == n - 1)
      mn = min(a[1] + a[0] + h, a[1] + a[2]);
    else
      mn = min(a[0] + a[i + 1], a[0] + a[1] + h);
    if (i != 1 && i != n - 1) mn = min(mn, a[1] + a[2]);
    if (ans > mx - mn) {
      ans = mx - mn;
      ind = i;
    }
  }
  vector<long long> o(n, 1);
  cout << ans << "\n";
  for (long long i = 1; i <= ind; i++) o[v[i].second] = 2;
  for (long long i = 0; i < n; i++) {
    cout << o[i] << " ";
  }
  return 0;
}
