#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
long long mod = 1e9 + 7;
long long u = 0, n, k;
vector<vector<long long> > mul(vector<vector<long long> > a,
                               vector<vector<long long> > b) {
  vector<vector<long long> > ans(n, vector<long long>(n));
  for (long long c = 0; c < n; c++) {
    for (long long i = 0; i < n; i++) {
      for (long long j = 0; j < n; j++) {
        if (u) break;
        if ((a[c][j] != 0 && inf / a[c][j] < b[j][i]) ||
            ans[c][i] + a[c][j] * b[j][i] > inf) {
          u = 1;
          break;
        }
        ans[c][i] += a[c][j] * b[j][i];
      }
    }
  }
  return ans;
}
vector<vector<long long> > mpow(vector<vector<long long> > a, long long m) {
  if (m == 1) return a;
  if (m & 1) {
    return mul(mpow(a, m - 1), a);
  } else {
    vector<vector<long long> > ddop = mpow(a, m / 2);
    return mul(ddop, ddop);
  }
}
bool check(vector<vector<long long> > a, vector<vector<long long> > b,
           long long step) {
  u = 0;
  auto ww = mpow(b, step);
  auto dd = mul(a, ww);
  if (u) return true;
  if (dd[0][n - 1] >= k) return true;
  return false;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  vector<long long> v(n);
  for (long long c = 0; c < n; c++) cin >> v[c];
  reverse(v.begin(), v.end());
  while (!v.empty() && v.back() == 0) v.pop_back();
  reverse(v.begin(), v.end());
  n = v.size();
  if (v[n - 1] >= k) {
    cout << 0;
    return 0;
  }
  if (n >= 10) {
    for (long long c = 1; c < 32; c++) {
      for (long long i = 1; i < n; i++) {
        v[i] += v[i - 1];
        if (v[i] >= k) {
          cout << c;
          return 0;
        }
      }
    }
  } else {
    vector<vector<long long> > dop(n, vector<long long>(n));
    for (long long c = 0; c < n; c++) {
      for (long long i = c; i < n; i++) {
        dop[c][i] = 1;
      }
    }
    vector<vector<long long> > vv(n, vector<long long>(n));
    for (long long c = 0; c < n; c++) vv[0][c] = v[c];
    long long l = 0, r = inf;
    while (l + 1 < r) {
      long long mid = (l + r) / 2;
      if (check(vv, dop, mid)) {
        r = mid;
      } else
        l = mid;
    }
    cout << r;
  }
  return 0;
}
