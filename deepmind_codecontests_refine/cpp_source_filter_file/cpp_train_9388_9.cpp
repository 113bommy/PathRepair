#include <bits/stdc++.h>
using namespace std;
long long cei(long long a, long long b) {
  if (a % b == 0) {
    return a / b;
  }
  return a / b + 1;
}
bool isit(vector<pair<long long, long long> > &v, long long n, long long x) {
  for (long long i = 0; i < n; i++) {
    if (v[i].first > v[i].second) {
      return false;
    }
    if (v[i].first >= x) {
      false;
    }
  }
  return 1;
}
void solve() {
  long long n, x;
  cin >> n >> x;
  vector<pair<long long, long long> > v(n);
  for (auto &i : v) {
    cin >> i.first >> i.second;
  }
  if (isit(v, n, x)) {
    cout << -1 << "\n";
    return;
  }
  long long maxv = 0, maxd = 0;
  for (long long i = 0; i < n; i++) {
    maxv = max(maxv, v[i].first);
    maxd = max(maxd, v[i].first - v[i].second);
  }
  if (maxv >= x) {
    cout << 1 << "\n";
    return;
  } else {
    long long ans = cei((x - maxv), maxd);
    if (x - ans * maxd <= 0) {
      cout << ans;
    } else {
      cout << ans + 1;
    }
  }
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long q;
  cin >> q;
  while (q--) {
    solve();
  }
}
