#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, n, k, a, b;
  cin >> y >> k >> n;
  b = y / k;
  a = k * (b + 1);
  if (y >= n || a > n)
    cout << -1;
  else {
    while (a <= n) {
      cout << a - y << ' ';
      a += k;
    }
  }
}
