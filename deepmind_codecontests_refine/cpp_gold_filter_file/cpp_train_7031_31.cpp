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
static int MOD = 1073741824;
int p = 1000, a, b;
int main() {
  for (int i = (0); i < (4); i++) {
    int t;
    scanf("%d", &t);
    ;
    smin(p, t);
  }
  cin >> a >> b;
  smin(p, b + 1);
  cout << max(0, p - a);
}
