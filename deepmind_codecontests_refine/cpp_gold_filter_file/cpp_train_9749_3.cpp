#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a > b) swap(a, b);
  if (b % a == 0) return a;
  return gcd(b % a, a);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j, n, t = 1, k = 0, cnt = 0, mini = LLONG_MAX, maxi = LLONG_MIN,
                     ans = 0;
  long long m;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  vector<long long> v;
  for (i = 0; i < n - 1; i++) v.push_back(a[i + 1] - a[i]);
  sort(v.begin(), v.end());
  k = v[0];
  for (i = 1; i < v.size(); i++) {
    k = gcd(k, v[i]);
  }
  for (i = 0; i < v.size(); i++) {
    ans += v[i] / k - 1;
  }
  cout << ans;
  return 0;
}
