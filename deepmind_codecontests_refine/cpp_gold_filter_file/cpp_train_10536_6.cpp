#include <bits/stdc++.h>
using namespace std;
template <class T>
void swaper(T &a, T &b) {
  T c = a;
  a = b;
  b = c;
}
template <class T>
T GCD(T a, T b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}
template <class T>
T MulMod(T a, T b, T mod) {
  T x, y;
  x = 0;
  y = a;
  while (b > 0) {
    if (b & 1) x = (x + y) % mod;
    y = (y << 1) % mod;
    b >>= 1;
  }
  return x;
}
template <class T>
T PowMod(T a, T b, T mod) {
  T x, y;
  x = 1;
  y = a;
  while (b > 0) {
    if (b & 1) x = (x * y) % mod;
    y = (y * y) % mod;
    b >>= 1;
  }
  return x;
}
template <class T>
T Multiply(T a, T b) {
  T x, y;
  x = 0;
  y = a;
  while (b > 0) {
    if (b & 1) x = (x + y);
    y = (y << 1);
    b >>= 1;
  }
  return x;
}
template <class T>
T Power(T a, T b) {
  T x, y;
  x = 1;
  y = a;
  while (b > 0) {
    if (b & 1) x = (x * y);
    y = (y * y);
    b >>= 1;
  }
  return x;
}
const int MAX = 1e6 + 10;
const long long int MOD7 = 1e9 + 7;
const long long int MOD9 = 1e9 + 9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  string str;
  while (t--) {
    cin >> str;
    int cnt_r = count(str.begin(), str.end(), 'R');
    int cnt_l = count(str.begin(), str.end(), 'L');
    int cnt_u = count(str.begin(), str.end(), 'U');
    int cnt_d = count(str.begin(), str.end(), 'D');
    int hz = min(cnt_r, cnt_l);
    int vz = min(cnt_u, cnt_d);
    if (hz == 0) vz = min(vz, 1);
    if (vz == 0) hz = min(hz, 1);
    int cnt = 2 * hz + 2 * vz;
    cout << cnt << endl;
    if (cnt > 0)
      cout << string(hz, 'L') << string(vz, 'U') << string(hz, 'R')
           << string(vz, 'D') << endl;
  }
  return 0;
}
