#include <bits/stdc++.h>
using namespace std;
long long n, mx, cf, cm, m;
void solve() {
  cin >> n >> mx >> cf >> cm >> m;
  vector<pair<long long, long long>> v;
  vector<long long> sum(n);
  for (long long i = 0; i < n; ++i) {
    long long x;
    cin >> x;
    v.push_back({x, i});
  }
  sort(v.begin(), v.end());
  sum[0] = v[0].first;
  for (long long i = 1; i < n; ++i) sum[i] = sum[i - 1] + v[i].first;
  long long ans = 0;
  long long piv = -1;
  long long mxval = 0;
  for (long long i = 0; i < n; ++i) {
    long long mxPos = (i == n - 1) ? mx : v[i + 1].first;
    long long req = v[i].first * (i + 1) - sum[i];
    long long rem = m - req;
    if (rem < 0) break;
    long long val = v[i].first + rem / (i + 1);
    val = min(val, mxPos);
    long long cur = val * cm;
    if (ans < cur) ans = cur, piv = i, mxval = val;
  }
  long long piv2 = -1;
  long long rem = m;
  for (long long i = n - 1; i >= 0; --i) {
    rem -= (mx - v[i].first);
    if (rem < 0) break;
    if (i == 0) {
      long long cur = n * cf + mx * cm;
      if (cur > ans) ans = cur, piv2 = i;
      continue;
    }
    long long l = 0, r = i - 1;
    long long id = -1;
    while (l <= r) {
      long long mid = (l + r) / 2;
      long long req = v[mid].first * (mid + 1) - sum[mid];
      if (rem >= req) {
        id = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    if (id == -1) {
      long long cur = (n - i) * cf + v[0].first * cm;
      if (cur > ans) ans = cur, piv2 = i;
    } else {
      long long val = v[id].first;
      long long x = v[id].first * (id + 1) - sum[id];
      x = rem - x;
      val += x / (id + 1);
      val = min(val, mx);
      val = val * cm + (n - i) * cf;
      if (val > ans) ans = val, piv2 = i;
    }
  }
  long long a[n];
  for (long long i = 0; i < n; ++i) {
    if (i <= piv)
      a[v[i].second] = mxval;
    else
      a[v[i].second] = v[i].first;
  }
  if (piv2 != -1) {
    for (long long i = piv2; i < n; ++i) {
      a[v[i].second] = mx;
      m -= mx - v[i].first;
    }
    long long l = 0, r = piv2 - 1;
    long long id = -1;
    long long val = 0;
    while (l <= r) {
      long long mid = (l + r) / 2;
      long long req = v[mid].first * (mid + 1) - sum[mid];
      if (rem >= req) {
        id = mid;
        l = mid + 1;
      } else
        r = mid - 1;
    }
    if (id != -1) {
      val = v[id].first;
      long long x = v[id].first * (id + 1) - sum[id];
      x = rem - x;
      val += x / (id + 1);
      val = min(val, mx);
    }
    for (long long i = 0; i < piv2; ++i) {
      if (i <= id)
        a[v[i].second] = val;
      else
        a[v[i].second] = v[i].first;
    }
  };
  cout << ans << '\n';
  for (long long i = 0; i < n; ++i) cout << a[i] << " ";
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  while (t--) solve();
}
