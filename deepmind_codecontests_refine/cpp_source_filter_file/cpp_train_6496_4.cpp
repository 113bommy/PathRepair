#include <bits/stdc++.h>
using namespace std;
template <class T>
T expo(T x, T n) {
  T result = 1;
  while (n > 0) {
    if (n % 2 == 1) result = (result * x) % 1000000007ll;
    x = (x * x) % 1000000007ll;
    n = n / 2;
  }
  return result;
}
int main() {
  int n, m, i, j, k, x, y, z = 0;
  cin >> n >> m;
  x = 0;
  while (m--) {
    cin >> y;
    y--;
    if (x < y) {
      z += abs(y - x);
    } else if (x > y) {
      z += (n - abs(x - y));
    }
    x = y;
  }
  cout << z;
}
