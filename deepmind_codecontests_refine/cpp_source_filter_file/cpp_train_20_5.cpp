#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 5;
pair<long long, long long> p[N], a[N];
long long n;
long long fwt[N], cntf[N];
long long len;
void add(long long *b, long long x, long long v) {
  while (x <= len) {
    b[x] += v;
    x += x & -x;
  }
}
long long get(long long *b, long long x) {
  long long res = 0;
  while (x) {
    res += b[x];
    x -= x & -x;
  }
  return res;
}
signed main() {
  ios::sync_with_stdio(false);
  cin >> n;
  vector<long long> velo_neg, velo_pos;
  for (long long i = 0; i < n; i++) {
    cin >> p[i].first;
  }
  for (long long i = 0; i < n; i++) {
    cin >> p[i].second;
  }
  sort(p, p + n);
  vector<long long> velo;
  for (long long i = 0; i < n; i++) {
    velo.push_back(p[i].second);
  }
  sort(velo.begin(), velo.end());
  velo.erase(unique(velo.begin(), velo.end()), velo.end());
  len = velo.size();
  long long ans = 0;
  long long sumx = 0;
  for (long long i = 0; i < n; i++) {
    a[i] = p[i];
    a[i].second =
        lower_bound(velo.begin(), velo.end(), p[i].second) - velo.begin() + 1;
    ans += i * p[i].first - sumx;
    sumx += p[i].first;
  }
  for (long long i = 0; i < n; i++) {
    if (p[i].second < 0) {
      ans -= (get(cntf, len) - get(cntf, a[i].second)) * p[i].first -
             (get(fwt, len) - get(fwt, a[i].second));
    }
    add(fwt, a[i].second, p[i].first);
    add(cntf, a[i].second, 1);
  }
  memset(cntf, 0, sizeof cntf);
  memset(fwt, 0, sizeof fwt);
  for (long long i = n - 1; i >= 0; i--) {
    if (p[i].second > 0) {
      ans -=
          get(fwt, a[i].second - 1) - get(cntf, a[i].second - 1) * p[i].first;
    }
    if (p[i].second > 0) {
      add(fwt, a[i].second, p[i].first);
      add(cntf, a[i].second, 1);
    }
  }
  cout << ans << endl;
  return 0;
}
