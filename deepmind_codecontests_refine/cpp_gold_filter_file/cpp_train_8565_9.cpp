#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
long long x, y, z, a, b, c, sum, ans, total, t, cnt, n, m, k, p, kase;
string s1, s2;
map<long long, long long> mp;
set<long long> s;
map<long long, long long>::iterator itr1, ptr1;
set<long long>::iterator itr, ptr;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> a(n), b(n);
    vector<pair<long long, long long>> v;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (long long i = 0; i < n; i++) {
      cin >> b[i];
      v.push_back({a[i], b[i]});
    }
    sort(v.rbegin(), v.rend());
    ans = INT_MIN;
    x = 0;
    for (long long i = 0; i < n; i++) {
      if (v[i].first <= v[i].second + x) {
        ans = max(ans, v[i].first);
      } else {
        x += v[i].second;
        ans = max(ans, x);
      }
    }
    cout << ans << endl;
  }
  return 0;
}
