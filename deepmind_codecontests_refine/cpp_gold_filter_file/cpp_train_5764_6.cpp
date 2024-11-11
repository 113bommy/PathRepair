#include <bits/stdc++.h>
using namespace std;
const double PI = 3.14159265358979;
const double PI2 = 6.28318530717958;
const double PId2 = 1.570796326794895;
template <typename T>
T sqr(T x) {
  return x * x;
}
template <typename T>
T gcd(T a, T b) {
  return (b ? gcd(b, a % b) : a);
}
long long pw(long long a, long long p, int mod) {
  long long res = 1;
  long long c = a;
  while (p) {
    if (p % 2 == 0) {
      p /= 2;
      c = (c * c) % mod;
    } else {
      p--;
      res = (res * c) % mod;
    }
  }
  return res;
}
inline vector<int> ReadVI(int count) {
  vector<int> arrayname(count);
  for (int i = 0; i < count; i++) cin >> arrayname[i];
  return arrayname;
}
inline vector<long long> ReadVlong(int count) {
  vector<long long> arrayname(count);
  for (int i = 0; i < count; i++) cin >> arrayname[i];
  return arrayname;
}
const int MOD = 1000000007;
const int MAXVALUE = 10000001;
int main() {
  int n, mod;
  cin >> n >> mod;
  cout << (mod + pw(3, n, mod) - 1) % mod;
  return 0;
}
