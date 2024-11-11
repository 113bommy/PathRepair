#include <bits/stdc++.h>
using namespace std;
const long double EPS = 1e-14;
const long long maxn = 100500;
const long long mod = 1e9 + 7;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m, k;
  cin >> n >> m >> k;
  vector<long long> a(n);
  for (auto &x : a) cin >> x;
  sort((a).begin(), (a).end());
  long long x = a.back();
  a.pop_back();
  long long y = a.back();
  cout << (m / (k + 1)) * (x * k + y) + (m % (k + 1)) * y << '\n';
  return 0;
}
