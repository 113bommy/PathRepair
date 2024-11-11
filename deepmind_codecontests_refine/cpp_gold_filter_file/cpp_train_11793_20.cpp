#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, R, r;
  double a;
  cin >> n >> R >> r;
  if (r > R) {
    cout << "NO";
    return 0;
  }
  if (n < 2) {
    cout << "YES";
    return 0;
  }
  a = (R - r) * sin(M_PI / n);
  if (r > a + 0.00000001)
    cout << "NO";
  else
    cout << "YES";
}
