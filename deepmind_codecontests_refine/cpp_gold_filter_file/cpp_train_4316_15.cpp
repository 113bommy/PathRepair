#include <bits/stdc++.h>
template <typename T, typename U>
inline void swap(T &a, U &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
inline void swap(int &a, int &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
inline void swap(long long &a, long long &b) {
  a = a ^ b;
  b = a ^ b;
  a = a ^ b;
}
template <typename T, typename U>
inline void smax(T &a, U b) {
  if (b > a) a = b;
}
template <typename T, typename U>
inline void smin(T &a, U b) {
  if (b < a) a = b;
}
inline int gcd(int a, int b) {
  if (a < b) swap(a, b);
  while (b > 0) {
    a %= b;
    swap(a, b);
  }
  return a;
}
long long nchose(int a, int b) {
  long long ans = 1;
  smax(a, b - a);
  int p = 2;
  for (int i = (b - a + 1); i <= (b); i++) {
    ans *= (long long)i;
    while (p <= a && ans % p == 0) ans /= p++;
  }
  return ans;
}
using namespace std;
static long long MOD = 1000000009;
long long t, i, j, x, y, z, m, kk;
long long n, k, d[2];
bool flag;
int main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k >> d[0] >> d[1];
    flag = 0;
    for (i = -1; i < 2; i += 2) {
      for (j = -1; j < 2; j += 2) {
        m = 0;
        x = 0, kk = 0;
        y = i * d[0];
        smin(m, y);
        z = j * d[1] + y;
        smin(m, z);
        x -= m;
        y -= m;
        z -= m;
        kk = k - (x + y + z);
        if (kk < 0 || kk % 3 != 0) continue;
        if (y > z) swap(y, z);
        if (x > y) swap(y, x);
        if (y > z) swap(y, z);
        kk = n - k;
        kk -= z - x;
        kk -= z - y;
        if (kk >= 0 && kk % 3 == 0) {
          flag = 1;
          goto en;
        }
      }
    }
  en:
    if (flag)
      cout << "yes" << endl;
    else
      cout << "no" << endl;
  }
}
