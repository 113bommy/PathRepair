#include <bits/stdc++.h>
using namespace std;
const int Inf = (int)1e10;
int main() {
  ios_base::sync_with_stdio(false);
  int a, b, n;
  cin >> a >> b >> n;
  if (b == 0) {
    cout << 0;
    return 0;
  }
  string nosol = "No solution";
  if (a == 0) {
    cout << nosol;
    return 0;
  }
  if (a * b < 0 && n % 2 == 0) {
    cout << nosol;
    return 0;
  }
  if (b % a) {
    cout << nosol;
    return 0;
  }
  b /= a;
  int x = 1;
  if (b < 0) {
    b = -b;
    x = -x;
  }
  for (int i = 2; i <= b; i++)
    if (b % i == 0) {
      x *= i;
      for (int j = 0; j < n; j++)
        if (b % i) {
          cout << nosol;
          return 0;
        } else
          b /= i, i--;
    }
  cout << x;
}
