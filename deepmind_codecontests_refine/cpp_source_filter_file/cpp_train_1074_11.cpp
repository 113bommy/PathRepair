#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, c = 1, maximum = 0;
  long double sum = 0.0;
  cin >> n;
  vector<int> a(n);
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  for (i = n - 1; i >= 0; i--) {
    if (c % 2 == 1)
      sum = sum + 1.0 * a[i] * a[i];
    else
      sum = sum - 1.0 * a[i] * a[i];
  }
  sum = sum * 3.1415926536;
  cout << sum;
  return 0;
}
