#include <bits/stdc++.h>
const int MAXINT = 2147483640;
const long long MAXLL = 9223372036854775800LL;
const long long MAXN = 1000000;
const double eps = 1e-9;
const long long mod = 1e9 + 7;
using namespace std;
long long binpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans *= a;
    a *= a;
    n >>= 1;
  }
  return ans;
}
int main() {
  srand(time(0));
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n;
  cin >> n;
  vector<pair<long long, long long> > v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first;
    v[i].second = i;
  }
  if (n == 1) {
    cout << -1 << "\n";
    return 0;
  }
  if (n == 2) {
    if (v[0].first == v[1].first) return cout << -1, 0;
  }
  sort(v.begin(), v.end());
  cout << v.size() - 1 << "\n";
  for (int i = 1; i < v.size(); ++i) {
    cout << v[i].second << " ";
  }
  return 0;
}
