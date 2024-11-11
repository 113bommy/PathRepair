#include <bits/stdc++.h>
using namespace std;
bool eql(pair<long long, long long> a, pair<long long, long long> b) {
  return a.first == b.first;
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    long long a, b, p, q;
    cin >> a >> b >> p >> q;
    p %= q;
    long long t = sqrt(b - a + 1);
    vector<pair<long long, long long> > vec;
    for (long long i = 0; i < t; i++) {
      vec.push_back(make_pair((a + i) * (2 * p) % (2 * q), i));
    }
    pair<long long, long long> ans =
        make_pair(abs(a * (2 * p) % (2 * q) - q), a);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end(), eql), vec.end());
    for (long long i = 0; i <= t; i++) {
      long long val =
          ((q - (i * t) * (2 * p) % (2 * q)) % (2 * q) + 2 * q) % (2 * q);
      int j = lower_bound(vec.begin(), vec.end(), make_pair(val, -1ll)) -
              vec.begin();
      long long r = vec[j].second;
      ans = min(
          ans, make_pair(abs((a + r + i * t) % (2 * q) * (2 * p) % (2 * q) - q),
                         a + r + i * t));
      j = (j + 1) % vec.size();
      r = vec[j].second;
      ans = min(
          ans, make_pair(abs((a + r + i * t) % (2 * q) * (2 * p) % (2 * q) - q),
                         a + r + i * t));
      j = (j - 2 + vec.size()) % vec.size();
      r = vec[j].second;
      ans = min(
          ans, make_pair(abs((a + r + i * t) % (2 * q) * (2 * p) % (2 * q) - q),
                         a + r + i * t));
    }
    for (long long i = a + t * t; i <= b; i++) {
      ans = min(ans, make_pair(abs(i * (2 * p) % (2 * q) - q), i));
    }
    if (a <= 398 && 398 <= b) {
      ans = min(ans, make_pair(abs(398 * (2 * p) % (2 * q) - q), 398ll));
    }
    if (b - a + 1 <= 100000) {
      ans = make_pair(abs(a * (2 * p) % (2 * q) - q), a);
      for (long long i = a; i <= b; i++) {
        ans = min(ans, make_pair(abs(i * (2 * p) % (2 * q) - q), i));
      }
    }
    cout << ans.second << endl;
  }
}
