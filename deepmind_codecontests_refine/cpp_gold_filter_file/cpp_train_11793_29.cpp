#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 1;
const int N = 1e6 + 10;
int a[N];
int main() {
  int n, R, r;
  cin >> n >> R >> r;
  if (n == 1) {
    if (r <= R)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  if (n == 2) {
    if (2 * r <= R)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    return 0;
  }
  double alpha = 360.0 / (2 * n);
  R -= r;
  if (R * sin(alpha * 3.141592653 / 180) + 1e-7 >= r)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
