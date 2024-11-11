#include <bits/stdc++.h>
using namespace std;
const long long N = 1e9 + 7;
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = ((res) * (x));
    res %= N;
    y = y >> 1;
    x = ((x) * (x));
  }
  return res;
}
long long powmod(long long a, long long b, long long n) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % n;
    }
    y = (y * y) % n;
    b /= 2;
  }
  return x % n;
}
bool sortbyval(pair<long long, long long>& p1, pair<long long, long long>& p2) {
  return p1.second < p2.second;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t = 1;
  while (t--) {
    long long n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> v(m);
    for (long long i = 0; i < m; i++) cin >> v[i].first >> v[i].second;
    long long x = v[0].first, cnt = 0, maxm = INT_MIN;
    map<long long, long long> g;
    for (long long i = 0; i < m; i++) {
      if (v[i].first == x || v[i].second == x)
        cnt++;
      else {
        g[v[i].first]++;
        g[v[i].second]++;
      }
    }
    for (auto i : g) maxm = max(maxm, i.second);
    if (maxm == INT_MIN) maxm = 0;
    if (cnt + maxm == m)
      cout << "YES";
    else {
      g.clear();
      maxm = INT_MIN;
      cnt = 0;
      x = v[0].second;
      for (long long i = 0; i < m; i++) {
        if (v[i].first == x || v[i].second == x)
          cnt++;
        else {
          g[v[i].first]++;
          g[v[i].second]++;
        }
      }
      for (auto i : g) maxm = max(maxm, i.second);
      if (maxm = INT_MIN) maxm = 0;
      if (cnt + maxm == m)
        cout << "YES";
      else
        cout << "NO";
    }
  }
  return 0;
}
