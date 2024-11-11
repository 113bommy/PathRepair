#include <bits/stdc++.h>
using namespace std;
template <class T>
void show(const vector<T> &a) {
  for (T x : a) cout << x << " ";
  cout << '\n';
}
const long long N = 1e5 + 100, oo = 1e18 + 9;
const long long mod = 1e9 + 7;
const long double eps = 1e-9, PI = 2 * acos(0.0);
long long n, m, k;
long long cnt = 0;
signed main() {
  ios::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  long long x0, y0, a, c, b, d;
  cin >> x0 >> y0 >> a >> c >> b >> d;
  long long mx = -1;
  vector<pair<long long, long long> > p;
  long long x = x0, y = y0;
  while (1) {
    if (x > 2e16 + 10 || y > 2e16 + 10) {
      break;
    }
    p.push_back({x, y});
    mx++;
    x = a * x + b;
    y = c * y + d;
  }
  long long t;
  cin >> x >> y >> t;
  long long ans = 0;
  long long prevx, prevy;
  for (long long j = 0; j < mx; j++) {
    long long dist = 0;
    cnt = 0;
    prevx = x, prevy = y;
    for (long long i = j; i >= 0; i--) {
      dist += abs(prevx - p[i].first);
      dist += abs(prevy - p[i].second);
      if (dist > t) {
        break;
      }
      cnt++;
      prevx = p[i].first;
      prevy = p[i].second;
    }
    ans = max(ans, cnt);
    ;
    dist = 0;
    cnt = 0;
    prevx = x, prevy = y;
    for (long long i = 0; i <= j; i++) {
      dist += abs(prevx - p[i].first);
      dist += abs(prevy - p[i].second);
      if (dist > t) {
        break;
      }
      cnt++;
      prevx = p[i].first;
      prevy = p[i].second;
    }
    ans = max(ans, cnt);
    ;
  }
  cout << ans;
}
