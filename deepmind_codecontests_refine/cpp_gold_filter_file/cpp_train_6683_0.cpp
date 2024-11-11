#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  vector<long long> a(n), b(n - 1);
  set<long long> s, s2;
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for (long long i = 0; i < n - 1; ++i) {
    if (i < n - 1) {
      b[i] = a[i + 1] - a[i];
    }
  }
  long long ans = a[n - 1] - a[0];
  long long l = 0, r = n - 2, d = 1;
  while (l < r) {
    long long p = min(k, (b[l] + b[r]) * d);
    ans -= (p / d);
    k -= p;
    d += 1;
    l += 1;
    r -= 1;
  }
  if (l == r) {
    long long p = min(k, b[l] * d);
    ans -= (p / d);
    k -= p;
  }
  cout << ans;
  return 0;
}
