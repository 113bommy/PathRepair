#include <bits/stdc++.h>
using namespace std;
const long double EPS = 5e-5;
int main() {
  int n;
  cin >> n;
  long double mina = 0, maxa = 1e7;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    mina = max(mina, (long double)x / (i + 1));
    maxa = min(maxa, ((long double)x + 1) / (i + 1));
  }
  long double xl = (n + 1) * mina - 1, xr = (n + 1) * (maxa);
  int l = ceil(xl + EPS), r = floor(xr - EPS);
  if (l == r) {
    cout << "unique\n" << l << "\n";
  } else {
    cout << "not unique\n";
  }
  return 0;
}
