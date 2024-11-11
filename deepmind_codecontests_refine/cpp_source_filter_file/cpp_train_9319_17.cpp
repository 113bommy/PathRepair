#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, j, sum1 = 0, sum2 = 0, max = 0;
  cin >> n;
  long long int a[n], b[n];
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < n; ++i) cin >> b[i];
  for (i = 0; i < n; ++i) {
    sum1 = a[i];
    sum2 = b[i];
    if (max < sum1 + sum2) max = sum1 + sum2;
    for (j = i + 1; j < n - 1; ++j) {
      sum1 = sum1 | a[j];
      sum2 = sum2 | b[j];
      if (max < sum1 + sum2) max = sum1 + sum2;
    }
  }
  cout << max;
  return 0;
}
