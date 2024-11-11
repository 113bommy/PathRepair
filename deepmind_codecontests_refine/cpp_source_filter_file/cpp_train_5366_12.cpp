#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
pair<int, int> p[N];
int n;
map<pair<pair<int, int>, int>, int> mp;
int gcd(int a, int b) {
  if (a == 0 || b == 0) return max(a, b);
  return gcd(b % a, a);
}
pair<int, int> calc_slope(pair<int, int> p1, pair<int, int> p2) {
  int num = p2.second - p1.second;
  int den = p2.first - p1.first;
  if (den == 0) {
    return {1, 0};
  }
  if (num == 0) {
    return {0, 1};
  }
  int gg = gcd(abs(den), abs(num));
  den /= gg;
  num /= gg;
  if (den < 0) num *= -1, den *= -1;
  return {num, den};
}
long long sq(int first) { return (long long)first * first; }
long long dist(pair<int, int> p1, pair<int, int> p2) {
  return sq(p1.first - p2.first) + sq(p1.second - p2.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < (int)(n); ++i) cin >> p[i].first >> p[i].second;
  for (int i = 0; i < (int)(n); ++i) {
    for (int j = (int)(i + 1); j <= (int)(n - 1); ++j) {
      ++mp[{calc_slope(p[i], p[j]), dist(p[i], p[j])}];
    }
  }
  long long res = 0ll;
  for (__typeof((mp).begin()) it = (mp).begin(); it != (mp).end(); it++) {
    if (it->second > 1) res += (long long)it->second * (it->second - 1) / 2;
  }
  cout << res / 2 << endl;
  return 0;
}
