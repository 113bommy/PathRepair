#include <bits/stdc++.h>
using namespace std;
void Weapons19() {
  cout << fixed << setprecision(16);
  cin.sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
long double dist(pair<pair<long long int, long long int>, long long int> a,
                 pair<pair<long long int, long long int>, long long int> b) {
  long long int k = a.first.first - b.first.first;
  long long int l = a.first.second - b.first.second;
  long long int m = a.second - b.second;
  long double p = sqrt(k * k + l * l + m * m);
  return p;
}
int32_t main() {
  Weapons19();
  long long int n;
  cin >> n;
  vector<pair<pair<long long int, long long int>, long long int>> v;
  for (long long int i = 0; i < n; i++) {
    long long int a, b, c;
    cin >> a >> b >> c;
    v.push_back({{a, b}, c});
  }
  long double ans = 9999999.9;
  for (long long int i = 1; i <= n; i++) {
    for (long long int j = i + 1; j <= n; j++) {
      long double p = dist(v[i], v[j]) + dist(v[i], v[0]) + dist(v[j], v[0]);
      p /= 2.0;
      ans = min(ans, p);
    }
  }
  cout << ans;
}
