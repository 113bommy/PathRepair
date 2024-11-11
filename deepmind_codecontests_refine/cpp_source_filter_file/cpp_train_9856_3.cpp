#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long n, k;
  cin >> n >> k;
  long long p[n], c[n];
  vector<tuple<long long, long long, long long>> tp(n);
  for (long long i = 0; i < n; ++i) cin >> p[i];
  for (long long i = 0; i < n; ++i) cin >> c[i];
  for (long long i = 0; i < n; ++i) {
    get<0>(tp[i]) = p[i];
    get<1>(tp[i]) = c[i];
    get<2>(tp[i]) = i;
  }
  sort(tp.begin(), tp.end());
  long long sum = 0;
  long long ans[n];
  set<long long> s;
  for (long long i = 0; i < n; ++i) {
    if (i <= k) {
      sum += get<1>(tp[i]);
      s.insert(get<1>(tp[i]));
      ans[get<2>(tp[i])] = sum;
    } else {
      sum = sum + get<1>(tp[i]) - *s.begin();
      s.erase(s.begin());
      s.insert(get<1>(tp[i]));
      ans[get<2>(tp[i])] = sum;
    }
  }
  for (long long i = 0; i < n; ++i) cout << ans[i] << " ";
}
