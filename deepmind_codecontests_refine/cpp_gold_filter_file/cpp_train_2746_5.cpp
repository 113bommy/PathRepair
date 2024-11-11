#include <bits/stdc++.h>
using namespace std;
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
template <typename T>
inline T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
template <typename T>
inline T lcm(T a, T b) {
  return (a * b) / gcd(a, b);
}
template <typename T>
string toStr(T x) {
  stringstream st;
  st << x;
  string s;
  st >> s;
  return s;
}
template <class T>
void splitStr(const string &s, vector<T> &out) {
  istringstream in(s);
  out.clear();
  copy(istream_iterator<T>(in), istream_iterator<T>(), back_inserter(out));
}
inline int two(int n) { return 1 << n; }
inline int isOnBit(int n, int b) { return (n >> b) & 1; }
inline void onBit(int &n, int b) { n |= two(b); }
inline void offBit(int &n, int b) { n &= ~two(b); }
inline int lastBit(int n) { return n & (-n); }
inline int cntBit(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
const int dx4[] = {-1, 0, 1, 0};
const int dy4[] = {0, 1, 0, -1};
const int dx8[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int dy8[] = {0, 1, 0, -1, -1, 1, -1, 1};
int n;
const int res[] = {1, 3, 15, 133, 2025, 37851, 1030367, 36362925};
int getMod(int m) {
  long long tmp = 1;
  for (int i = (1), _b = (m); i <= _b; i++) tmp *= i, tmp %= 1000000007;
  return tmp % 1000000007;
}
int solve() {
  if (n == 1) return 1;
  if (n % 2 == 0) return 0;
  if (n == 3) return 18;
  return (1ll * res[n / 2] * getMod(n)) % 1000000007;
}
int main() {
  scanf("%d", &n);
  printf("%d\n", solve());
  return 0;
}
