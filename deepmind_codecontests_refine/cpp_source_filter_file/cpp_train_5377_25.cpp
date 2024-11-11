#include <bits/stdc++.h>
using namespace std;
template <typename T>
T gcd(T a, T b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
template <typename T>
T pow(T a, T b) {
  if (b == 0)
    return 1;
  else {
    int c = pow(a, b / 2);
    if (b % 2 == 0)
      return c * c;
    else
      return a * c * c;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, c = 1, t;
  cin >> n;
  for (int i = 2; i < sqrt(n); i++) {
    if (n % i == 0) {
      c += 2;
    }
  }
  t = sqrt(n);
  if (n % t == 0) {
    c++;
  }
  if (n == 2) {
    c = 1;
  }
  cout << c << "\n";
  return 0;
}
