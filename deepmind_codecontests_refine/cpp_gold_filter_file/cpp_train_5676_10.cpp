#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, A, cf, cm, m;
  cin >> n >> A >> cf >> cm >> m;
  vector<pair<long long, long long> > v(n);
  for (long long i = (long long)(0); i <= (long long)(n - 1); i++) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(v.rbegin(), v.rend());
  vector<pair<long long, long long> > sum(n + 1, {0, 0});
  for (long long i = (long long)(n - 1); i >= (long long)(0); i--) {
    sum[i].second = sum[i + 1].second + v[i].first;
    sum[i].first = v[i].first;
  }
  long long ans = 0, left = m, fill = -1, minVal = -1;
  for (long long i = (long long)(0); i <= (long long)(n); i++) {
    long long start = 0, end = A;
    while (start <= end) {
      long long mid = (start + end) / 2;
      long long x = i, y = n - 1;
      while (x <= y) {
        long long m = (x + y) / 2;
        if (v[m].first > mid - 1)
          x = m + 1;
        else
          y = m - 1;
      };
      ;
      ;
      ;
      if ((n - x) * mid - sum[x].second > left)
        end = mid - 1;
      else
        start = mid + 1;
    };
    ;
    ;
    ;
    ;
    ;
    if (ans < i * cf + end * cm) {
      fill = i - 1;
      minVal = end;
      ans = i * cf + end * cm;
    }
    if (i < n) left -= A - v[i].first;
    if (left < 0) break;
  }
  vector<long long> f(n);
  for (long long i = (long long)(0); i <= (long long)(n - 1); i++) {
    if (fill >= i)
      f[v[i].second] = A;
    else
      f[v[i].second] = max(minVal, v[i].first);
  }
  cout << ans << '\n';
  for (long long x : f) cout << x << ' ';
}
