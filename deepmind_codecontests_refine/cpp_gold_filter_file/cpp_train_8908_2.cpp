#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897932384626433;
const int mod = 1e9 + 7;
const long long inf = 3e18;
long long n;
vector<pair<long long, long long> > p;
bool god(long double k) {
  long double st = (p[0].first - p[0].second * k);
  long double en = p[0].first + p[0].second * k;
  for (long long i = 1; i < n; i++) {
    st = max(st, p[i].first - p[i].second * k);
    en = min(en, p[i].first + p[i].second * k);
  }
  if (st <= en)
    return true;
  else
    return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  vector<long long> a(n), b(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (long long i = 0; i < n; i++) {
    p.push_back({a[i], b[i]});
  }
  sort(p.begin(), p.end());
  long double lo = 0;
  long double hi = 1e18;
  long double ans;
  while (lo <= hi) {
    long double mid = (lo + hi) / 2.0;
    if (god(mid)) {
      ans = mid;
      hi = mid - 0.0000001;
    } else {
      lo = mid + 0.0000001;
    }
  }
  cout << fixed << setprecision(12) << ans;
}
