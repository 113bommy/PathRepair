#include <bits/stdc++.h>
using namespace std;
template <typename T>
T my_pow(T a, int n) {
  if (n == 0) return 1;
  if (n % 2 == 0) {
    T k = my_pow(a, n / 2);
    return k * k;
  } else {
    T k = my_pow(a, n - 1);
    return k * a;
  }
}
template <typename T>
T gcd(T a, T b) {
  while (a != (T)0 && b != (T)0) {
    if (a > b)
      a %= b;
    else
      b %= a;
  }
  return max(a, b);
}
int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  int d;
  char c;
  cin >> c >> d;
  if (c != 'a' && c != 'h' && d != 1 && d != 8)
    cout << 8;
  else if ((c == 'a' && d == 1) || (c == 'a' && d == 8) ||
           (c == 'h' && d == 1) || (c == 'h' && d == 8))
    cout << 3;
  else
    cout << 5;
}
