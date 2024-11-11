#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, res;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  long long min1 = 100000;
  long long max1 = 0;
  for (i = 0; i < n; i++) {
    min1 = min(min1, a[i]);
    max1 = max(max1, a[i]);
  }
  cout << max1 - min1 - 1 - (n - 2) << endl;
  return 0;
}
