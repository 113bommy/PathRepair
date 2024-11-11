#include <bits/stdc++.h>
using namespace std;
const long long INF = 1E16;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int SIZE = 10000000;
long double _abs(long double a) {
  if (a < 0) return -a;
  return a;
}
long long _abss(long long a) {
  if (a < 0) return -a;
  return a;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
void solve() {
  long long k;
  cin >> k;
  vector<long long> a(k), x(k), y(k);
  for (long long i = 0; i < long long(k); ++i) {
    cin >> a[i];
    if (a[i] == 1) {
      cin >> x[i];
    } else {
      cin >> x[i] >> y[i];
    }
  }
  vector<long long> ans, p(SIZE, 0);
  for (long long i = 0; i < long long(SIZE); ++i) {
    p[i] = i;
  }
  for (long long i = long long(k) - 1; i >= 0; --i) {
    if (a[i] == 1) {
      ans.push_back(p[x[i]]);
    } else {
      p[x[i]] = p[y[i]];
    }
  }
  reverse((ans).begin(), (ans).end());
  for (auto i : ans) {
    cout << i << ' ';
  }
  cout << endl;
  return;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
