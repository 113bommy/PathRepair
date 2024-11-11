#include <bits/stdc++.h>
using namespace std;
long long modpow(long long base, long long exp, long long modulus) {
  base %= modulus;
  long long result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
int main() {
  long long t;
  cin >> t;
  vector<pair<long long, long long> > v, vv, vvv;
  long long a, b;
  for (long long i = 0; i < t; i++) cin >> a >> b, v.push_back(make_pair(a, b));
  for (long long i = 0; i < t; i++)
    cin >> a >> b, vv.push_back(make_pair(a, b));
  sort(v.begin(), v.end());
  sort(vv.begin(), vv.end());
  cout << v[0].first + vv[t - 1].first << " " << v[0].second + v[t - 1].second;
  return 0;
}
