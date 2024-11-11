#include <bits/stdc++.h>
using namespace std;
long long int n, c;
vector<pair<long long int, long long int> > v;
bool check(long long int mid) {
  long long int ans = mid, res = 0;
  for (long long int i = 0; i < n; i++) {
    res += 1 + (v[i].first * mid) / v[i].second;
  }
  return (res == c);
}
void sober() {
  cin >> n >> c;
  long long int a, b;
  for (long long int i = 0; i < n; i++) {
    cin >> a >> b;
    v.push_back({a, b});
  }
  long long int ans = 0;
  for (long long int i = 1; i < 1000001; i++) {
    if (check(i)) {
      ans++;
    }
  }
  cout << ans << '\n';
  return;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    sober();
  }
}
