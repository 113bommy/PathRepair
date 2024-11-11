#include <bits/stdc++.h>
time_t st = clock();
using namespace std;
template <class stl>
void DBGSTL(stl a) {
  cerr << "\tDEBUG:\n\t";
  for (typeof(a.begin()) i = a.begin(); i != a.end(); i++) {
    cerr << *i << " ";
  }
  cerr << "\n";
  return;
}
template <class T>
inline T max(T a, T b, T c) {
  return max(a, max(b, c));
}
template <class T>
inline T min(T a, T b, T c) {
  return min(a, min(b, c));
}
template <class T>
T gcd(T a, T b) {
  return (b == (T)0 ? a : gcd(b, a % b));
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
template <class T>
T mathround(T x) {
  long long i64x = (long long)x;
  if (x < i64x + 0.5) return (T)i64x;
  return (T)i64x + 1;
}
template <class T>
bool isprime(T x) {
  int till = (T)sqrt(x + .0);
  if (x == 1) return 0;
  if (x == 2) return 1;
  if (x % 2 == 0) return 0;
  for (int i = 3; i <= till; i += 2)
    if (x % i == 0) return 0;
  return 1;
}
template <class T>
double geodist(T x1, T y1, T x2, T y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + .0);
}
const double Pi = 4.0 * atan(1.0);
long long n, m;
int main() {
  cin >> n >> m;
  if (m == 3 && n - m > 1) {
    cout << -1;
    return 0;
  }
  long long x = 0;
  long long y = 1;
  for (int i = m; i > 0; i--) {
    cout << i + 1000000 << " " << x << "\n";
    x += y;
    y++;
  }
  x = 0;
  y = 1;
  for (int i = n - m; i > 0; i--) {
    cout << -i << " " << x << "\n";
    x += y;
    y++;
  }
  return EXIT_SUCCESS;
}
