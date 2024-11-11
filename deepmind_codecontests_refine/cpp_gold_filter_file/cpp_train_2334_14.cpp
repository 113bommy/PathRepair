#include <bits/stdc++.h>
using namespace std;
long long Mod(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
class Triplet {
 public:
  long long x;
  long long y;
  long long gcd;
};
Triplet extendedEuclid(long long a, long long b) {
  if (b == 0) {
    Triplet ans;
    ans.gcd = a;
    ans.x = 1;
    ans.y = 0;
    return ans;
  }
  Triplet smallAns = extendedEuclid(b, a % b);
  Triplet ans;
  ans.gcd = smallAns.gcd;
  ans.x = smallAns.y;
  ans.y = smallAns.x - (a / b) * smallAns.y;
  return ans;
}
long long mmInverse(long long a, long long m) {
  Triplet ans = extendedEuclid(a, m);
  return ans.x;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long k;
  cin >> k;
  map<long long, long long> m;
  for (long long i = 0; i < 4; i++) {
    string str;
    cin >> str;
    for (long long j = 0; j < (long long)str.length(); j++)
      if (str[j] != '.') m[str[j] - '0']++;
  }
  for (auto it : m) {
    if (it.second > 2 * k) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
