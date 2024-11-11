#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const double PI = acos(-1.0);
template <class T>
inline T _abs(T n) {
  return ((n) < 0 ? -(n) : (n));
}
template <class T>
inline T _max(T a, T b) {
  return (!((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _min(T a, T b) {
  return (((a) < (b)) ? (a) : (b));
}
template <class T>
inline T _swap(T& a, T& b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
template <class T>
inline T gcd(T a, T b) {
  return (b) == 0 ? (a) : gcd((b), ((a) % (b)));
}
template <class T>
inline T lcm(T a, T b) {
  return ((a) / gcd((a), (b)) * (b));
}
struct debugger {
  template <typename T>
  debugger& operator,(const T& v) {
    cerr << v << " ";
    return *this;
  }
} dbg;
int bitOn(int N, int pos) { return N = N | (1 << pos); }
int bitOff(int N, int pos) { return N = N & ~(1 << pos); }
bool bitCheck(int N, int pos) { return (bool)(N & (1 << pos)); }
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int e = a | b;
  int f = c ^ d;
  int g = c & b;
  int h = a ^ d;
  int x = e & f;
  int y = g ^ h;
  int z = x ^ y;
  cout << 0 << endl;
}
