#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, sum1, sum2, x, y;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (i == 0)
      sum1 = x;
    else
      sum1 = (sum1 | x);
  }
  for (j = 0; j < n; j++) {
    cin >> y;
    if (i == 0)
      sum2 = y;
    else
      sum2 = (sum2 | y);
  }
  cout << sum1 + sum2;
  return 0;
}
