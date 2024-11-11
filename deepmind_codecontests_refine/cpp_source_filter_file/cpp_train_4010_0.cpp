#include <bits/stdc++.h>
using namespace std;
const double PI = acos(0) * 2;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
const int MAXN = 1e5 + 5;
const int oo = 1e9;
const double foo = 1e30;
template <class T>
int getbit(T s, int i) {
  return (s >> i) & 1;
}
template <class T>
T onbit(T s, int i) {
  return s | (T(1) << i);
}
template <class T>
T offbit(T s, int i) {
  return s & (~(T(1) << i));
}
template <class T>
int cntbit(T s) {
  return __builtin_popcounll(s);
}
int n, k;
int G(int x) {
  if (k == 2) {
    if (x > 2) {
      return (x % 2 == 0 ? 1 : 0);
    } else {
      if (x == 0) return 0;
      if (x == 1) return 1;
      if (x == 2) return 2;
    }
  } else {
    if (x > 6) {
      if (x % 2) return 0;
      if ((x / 2) % 2 == 1) return 1;
      if (G(x / 2) == 1) return 2;
      return 1;
    } else {
      if (x == 0) return 0;
      if (x == 1) return 1;
      if (x == 2) return 0;
      if (x == 3) return 1;
      if (x == 4) return 2;
      if (x == 5) return 0;
      if (x == 6) return 2;
    }
  }
}
int main() {
  cin >> n >> k;
  int ret = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    ret ^= G(x);
  }
  cout << (ret == 0 ? "Nicky" : "Kevin");
}
