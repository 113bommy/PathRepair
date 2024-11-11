#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  if (!b) return a;
  return gcd(b, a % b);
}
template <class T>
T power(T a, T b) {
  T res(1);
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
template <class T>
T powerM(T a, T b, T mod) {
  T res(1);
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
const int infi = 2147483647;
const long long infl = 9223372036854775807;
int n, m, k, T;
multiset<int> s;
int main() {
  scanf("%d", &n), scanf("%d", &k);
  int res = 0;
  while (n--) {
    scanf("%d", &m), s.insert(m);
  }
  while (k-- && s.size() > 0) {
    res += *s.begin();
    s.erase(s.begin());
  }
  printf("%d", res);
  return 0;
}
