#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b,
                    long long int m = 1000000007) {
  long long int ans = 1;
  a = a % m;
  while (b > 0) {
    if (b & 1) ans = (1LL * a * ans) % m;
    b >>= 1;
    a = (1LL * a * a) % m;
  }
  return ans;
}
long long int ncr(long long int n, long long int r) {
  long long int res = 1;
  if (r > n - r) r = n - r;
  for (long long int i = 0; i < r; i++) {
    res *= n - i;
    res /= i + 1;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
clock_t time_p = clock();
void rtime() {
  time_p = clock() - time_p;
  cerr << "******************\nTime taken : "
       << (long double)(time_p) / CLOCKS_PER_SEC << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int tt = 1;
  while (tt--) {
    long long int n;
    cin >> n;
    map<long long int, long long int> make_pair;
    for (long long int i = 0; i < n; i++) {
      long long int x;
      cin >> x;
      make_pair[x]++;
    }
    long long int ans = 1;
    long long int d = 1;
    for (auto x : make_pair) {
      long long int p = x.second;
      long long int f = x.first;
      long long int df = power(f, ((p + 1) * p) / 2);
      ans = power(ans, p + 1) * power(df, d) % 1000000007;
      d = d * (p + 1) % 1000000007;
    }
    cout << ans;
  }
  rtime();
  return 0;
}
