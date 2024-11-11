#include <bits/stdc++.h>
using namespace std;
int n, i;
long double a, b, ans;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    b = 4 * b;
    if (a <= b)
      ans = 0.5 + a / b / 4;
    else
      ans = 0.5 + b / a / 4 + (a - b) / b / 2;
    if (b == 0)
      cout << "1.00000000" << endl;
    else
      printf("%.8lf\n", (double)ans);
  }
  return 0;
}
