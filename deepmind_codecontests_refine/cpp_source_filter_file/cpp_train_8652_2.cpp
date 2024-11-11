#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, N = 1e5 + 5;
long long power(long long x, unsigned long long y) {
  long long res = 1;
  x = x % MOD;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % MOD;
    y = y >> 1;
    x = (x * x) % MOD;
  }
  return res;
}
long long count(long long k, vector<long long> &a) {
  long long c = 1;
  long long ans = 0;
  for (long long i = (long long)1; i < a.size(); i++) {
    if (a[i] == a[i - 1])
      c++;
    else {
      ans += c / k;
      c = 1;
    }
  }
  return ans + c / k;
}
long long solve() {
  long long n, k, t = 0;
  cin >> n >> k;
  vector<long long> a(n);
  for (long long i = (long long)0; i < n; i++) cin >> a[i];
  sort((a).begin(), (a).end());
  long long lo = 1, hi = n;
  while (lo <= hi) {
    long long mid = lo + (hi - lo) / 2;
    long long x = count(mid, a);
    if (x >= mid) {
      t = max(t, mid);
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  long long c = 1;
  vector<long long> v;
  for (long long i = (long long)1; i < a.size(); i++) {
    if (a[i] == a[i - 1])
      c++;
    else {
      for (long long j = (long long)0; j < c / t; j++) v.push_back(a[i - 1]);
      c = 1;
    }
  }
  for (long long j = (long long)0; j < c / t; j++) v.push_back(a[n - 1]);
  for (long long i = (long long)0; i < k; i++) cout << v[i] << " ";
  return 0;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}
