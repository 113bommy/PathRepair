#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, sum = 0, sum1 = 0, x = 0;
  cin >> n;
  long long a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int i = 0;
  int j = n - 1;
  while (i <= j) {
    if (sum <= sum1) {
      sum += a[i];
      ++i;
    } else {
      sum1 = sum1 + a[j];
      --j;
    }
    if (sum == sum1) {
      x = max(x, sum);
    }
  }
  cout << x;
  return 0;
}
