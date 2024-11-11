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
  return __builtin_popcounll(s);
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
int n;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  if (n == 1 || n == 2) {
    cout << 1 << endl << 1;
    return 0;
  } else if (n == 3) {
    cout << 2 << endl << "1 3";
    return 0;
  } else if (n == 4) {
    cout << 4 << endl << "2 4 1 3";
    return 0;
  } else {
    cout << n << endl;
    for (int i = 1; i <= n; i += 2) cout << i << " ";
    for (int i = 2; i <= n; i += 2) cout << i << " ";
  }
  return 0;
}
