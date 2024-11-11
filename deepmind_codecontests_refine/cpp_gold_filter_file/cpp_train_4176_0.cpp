#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
template <class T>
inline void chkmin(T &a, T b) {
  if (a > b) a = b;
}
template <class T>
inline void chkmax(T &a, T b) {
  if (a < b) a = b;
}
long long GCD(long long a, long long b) {
  if (a < b) swap(a, b);
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if ((2 * n * m) % k) {
    cout << "NO\n";
    return 0;
  }
  long long second = 2 * n * m / k;
  long long x = GCD(second, n);
  long long y = second / x;
  if (y > m) {
    y /= 2;
    x *= 2;
  }
  cout << "YES\n";
  cout << "0 0\n" << x << " 0\n0 " << y << '\n';
}
