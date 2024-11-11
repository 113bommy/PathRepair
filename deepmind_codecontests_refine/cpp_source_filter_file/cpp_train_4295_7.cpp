#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265358979311599796346854;
long long mod = 998244353;
long long fast_exp(long long a, long long b) {
  if (b <= 0)
    return 1;
  else {
    long long res = 1;
    res = fast_exp(a, b / 2);
    res = (res * res) % mod;
    if (b % 2 == 1) res = (res * a) % mod;
    return res;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long double h, c, t;
    cin >> h >> c >> t;
    t -= c, h -= c, c -= c;
    long double avg = h / 2;
    map<long double, long long> first;
    if (t <= (avg)) {
      cout << 2 << '\n';
    } else {
      long double minim = 1e15;
      long double term = t / (2 * t - h);
      vector<pair<long long, long double>> vec;
      for (long long i = term - 20; i <= term + 20; i++) {
        if (i >= 1) {
          long double value = ((long double)i * h) / ((long double)(2 * i) - 1);
          if (abs(value - t) <= minim) {
            minim = abs(value - t);
            vec.push_back({i, abs(value - t)});
          }
        }
      }
      set<long long> cand;
      for (auto e : vec) {
        if (abs(minim - e.second) <= 1e-8) cand.insert(e.first);
      }
      long long num = *cand.begin();
      cout << 2 * num - 1 << '\n';
    }
  }
  return 0;
}
