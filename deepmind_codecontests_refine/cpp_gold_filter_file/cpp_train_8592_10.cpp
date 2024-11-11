#include <bits/stdc++.h>
using namespace std;
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
  return __builtin_popcount(s);
}
template <class T>
T gcd(T a, T b) {
  T r;
  while (b != 0) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
template <class T>
T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
int q;
int n, r;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> q;
  for (int iq = 0; iq < (q); ++iq) {
    cin >> n >> r;
    int res = (r - 1);
    for (int i = 0; i < (n - 1); ++i) {
      int x;
      cin >> x;
      res += (n - x);
    }
    cout << (res % n) + 1 << "\n";
  }
  return 0;
}
