#include <bits/stdc++.h>
using namespace std;
pair<long long, pair<long long, long long> > extendedEuclid(long long a,
                                                            long long b) {
  if (a == 0) return make_pair(b, make_pair(0, 1));
  pair<long long, pair<long long, long long> > p;
  p = extendedEuclid(b % a, a);
  return make_pair(
      p.first,
      make_pair(p.second.second - p.second.first * (b / a), p.second.first));
}
long long modInverse(long long a, long long m) {
  return (extendedEuclid(a, m).second.first + m) % m;
}
int main() {
  unsigned long long m = 1000000007;
  vector<unsigned long long> fact(2000001);
  fact[0] = 1;
  for (int i = int(1); i < int(2000001); i++) fact[i] = (fact[i - 1] * (i)) % m;
  int n;
  cin >> n;
  ++n;
  unsigned long long a = fact[2 * n], b = fact[n];
  unsigned long long c = ((b % m) * (b % m)) % m;
  unsigned long long res = (a * modInverse(c, m)) % m;
  cout << res - 2;
  return 0;
}
