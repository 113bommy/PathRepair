#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  long long maxm = -LLONG_MAX;
  long long minm = LLONG_MAX;
  for (long long &i : a) {
    cin >> i;
    maxm = max(i, maxm);
    minm = min(i, minm);
  }
  long long c1 = 0, c2 = 0;
  for (long long i : a) {
    c1 += (i == maxm);
    c2 += (i == minm);
  }
  cout << maxm - minm << ' ';
  if (maxm == n)
    cout << n * (n - 1) / 2 << '\n';
  else
    cout << c1 * c2;
  return 0;
}
