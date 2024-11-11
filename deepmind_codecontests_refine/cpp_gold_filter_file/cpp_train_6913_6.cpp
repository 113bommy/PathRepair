#include <bits/stdc++.h>
using namespace std;
const long double pi = 2 * acos(0.0);
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T, class TT>
bool pal(T a, TT n) {
  int k = 0;
  for (int i = 0; i <= n / 2; i++) {
    if (a[i] != a[n - i - 1]) {
      k = 1;
      break;
    }
  }
  return k ? 0 : 1;
}
int main() {
  int k, d;
  cin >> k >> d;
  if (d == 0 && k > 1) return cout << "No solution\n", 0;
  k--;
  while (k--) cout << 9;
  cout << d;
  getchar();
  getchar();
  return 0;
}
