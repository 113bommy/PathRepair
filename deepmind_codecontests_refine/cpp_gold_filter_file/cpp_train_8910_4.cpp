#include <bits/stdc++.h>
using namespace std;
const int K = 2;
const double PI = acos(-1);
template <class T>
inline T bigmod(T a, T b, T M) {
  long long ret = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) ret = (ret * a) % M;
    a = (a * a) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a = a % b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T lcm(T a, T b) {
  return (a / gcd(a, b)) * b;
}
template <class T>
inline T poww(T a, T b) {
  long long ret = 1;
  for (; b > 0; b >>= 1) {
    if (b & 1) ret = ret * a;
    a = a * a;
  }
  return (T)ret;
}
pair<int, int> exEuclid(int a, int b) {
  if (b == 0)
    return pair<int, int>(1, 0);
  else {
    pair<int, int> r = exEuclid(b, a % b);
    return pair<int, int>(r.second, r.first - r.second * (a / b));
  }
}
int modInv(int a, int m) {
  pair<int, int> ret = exEuclid(a, m);
  return ((ret.first % m) + m) % m;
}
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos) { return N = N & ~(1 << pos); }
bool check(int N, int pos) { return (bool)(N & (1 << pos)); }
int n, k, ans;
int main() {
  cin >> n >> k;
  for (int i = (2); i <= (n); i++) {
    if ((i - 2) % k == 0 || (i - 2) % k == 1) ans++;
  }
  cout << ans << endl;
  for (int i = (2); i <= (n); i++) {
    cout << max(1, i - k) << " " << i << endl;
  }
  return 0;
}
