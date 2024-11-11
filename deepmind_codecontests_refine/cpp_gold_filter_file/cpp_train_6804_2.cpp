#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> v(n);
  for (long long &i : v) cin >> i;
  sort(v.begin(), v.end(), [](long long a, long long b) { return a > b; });
  vector<long long> sm(n);
  sm[0] = v[0];
  for (long long i = 1; i < n; ++i) {
    sm[i] = sm[i - 1] + v[i];
  }
  long long num, cnt = 0;
  for (long long i = 0; i < n; ++i) {
    long long l = i, r = n;
    while (r - l > 1) {
      long long m = (l + r) / 2;
      if ((m - i) * v[i] - (sm[m] - sm[i]) <= k)
        l = m;
      else
        r = m;
    }
    if (l - i + 1 >= cnt) {
      cnt = l - i + 1;
      num = v[i];
    }
  }
  cout << cnt << " " << num;
  return 0;
}
