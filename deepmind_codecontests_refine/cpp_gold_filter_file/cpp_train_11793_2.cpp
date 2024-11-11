#include <bits/stdc++.h>
using namespace std;
double pi = 3.141592653589793238462;
string numkey = "0123456789";
string uni = "abcdefghijklmnopqrstuvwxyz";
long long int dx[4] = {0, 0, 1, -1};
long long int dy[4] = {1, -1, 0, 0};
long long int power(long long int x, long long int y) {
  if (y == 0) return 1;
  long long int res = power(x, y / 2);
  if (y % 2 == 0) return res * res;
  return res * res * x;
}
signed main() {
  long double n, R, r;
  cin >> n >> R >> r;
  if (r > R) {
    cout << "NO\n";
    return 0;
  }
  if (r > R / 2) {
    if (n == 1)
      cout << "YES\n";
    else
      cout << "NO\n";
    return 0;
  }
  double pi = 3.1415927;
  if (n * asin(r / (R - r)) <= pi) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
