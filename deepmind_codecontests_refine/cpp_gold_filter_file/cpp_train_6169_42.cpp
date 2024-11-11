#include <bits/stdc++.h>
using namespace std;
int c = 56;
const long long int mod = 1000000007;
const unsigned long long INF = 1e18;
string itoa(int a) {
  ostringstream s;
  s << a;
  return s.str();
};
int atoi(string x) {
  int k(0);
  for (int i(0); i < x.size(); i++) k = k * 10 + (x[i] - '0');
  return k;
}
long long int powmod(long long int a, long long int b) {
  long long int res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) {
    return a;
  } else {
    return gcd(b, a % b);
  }
}
bool solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n % 4 == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 1;
}
int main() {
  solve();
  return 0;
}
