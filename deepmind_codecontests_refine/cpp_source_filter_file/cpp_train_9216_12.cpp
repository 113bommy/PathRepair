#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b, c, d, i, a13, a33, a31;
  int ans = 0;
  long long maax;
  cin >> n >> a >> b >> c >> d;
  for (i = 1; i <= n; i++) {
    a13 = b - c + i;
    a33 = b - c + a - d + i;
    a31 = a - d + i;
    if ((a13 > 0) && (a33 > 0) && (a31 > 0) && (a13 <= n) && (a33 <= n) &&
        (a31 <= n))
      ans++;
  }
  maax = ans * n;
  cout << maax << endl;
}
