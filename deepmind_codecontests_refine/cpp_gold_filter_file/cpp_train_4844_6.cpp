#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
template <class T>
inline T tmin(T a, T b) {
  return (a < b) ? a : b;
}
template <class T>
inline T tmax(T a, T b) {
  return (a > b) ? a : b;
}
template <class T>
inline void amax(T &a, T b) {
  if (b > a) a = b;
}
template <class T>
inline void amin(T &a, T b) {
  if (b < a) a = b;
}
template <class T>
inline T tabs(T a) {
  return (a > 0) ? a : -a;
}
template <class T>
T gcd(T a, T b) {
  while (b != 0) {
    T c = a;
    a = b;
    b = c % b;
  }
  return a;
}
const int N = 200005;
int n, a[N], b[N];
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = (0); i < (n); ++i) cin >> a[i];
  for (int i = (0); i < (n); ++i) cin >> b[i];
  int sa = max_element(a, a + n) - a;
  int sb = max_element(b, b + n) - b;
  for (int i = (0); i < (n - 1); ++i) {
    if (a[sa] == 0) sa = (sa + 1) % n;
    if (b[sb] == 0) sb = (sb + 1) % n;
    if (a[sa] != b[sb]) {
      puts("NO");
      return 0;
    }
    sa = (sa + 1) % n;
    sb = (sb + 1) % n;
  }
  puts("YES");
  return 0;
}
