#include <bits/stdc++.h>
using namespace std;
int main() {
  long double flag = 0, i = 0, j = 0, k = 0, l = 0, n, R, r;
  cin >> n >> R >> r;
  if (n == 1 && R >= r)
    cout << "YES" << endl;
  else if (n == 1 && R < r)
    cout << "NO" << endl;
  else {
    long double theta = n * asin((r) / (R - r));
    if (theta - 1e-9 <= acos(-1.0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
