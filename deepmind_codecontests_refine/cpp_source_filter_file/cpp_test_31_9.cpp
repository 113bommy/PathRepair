#include <bits/stdc++.h>
using namespace std;
int32_t mod = 1e9 + 7;
void solveCase() {
  long long n = 0;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  if (n % 2 == 0) {
    for (long long i = 0; i < n - 1; i++)
      cout << -1 * a[i + 1] << " " << a[i] << " ";
  } else {
    for (long long i = 0; i < n - 4; i++)
      cout << -1 * a[i + 1] << " " << a[i] << " ";
    if ((a[n - 3] + a[n - 2]) != 0)
      cout << -a[n - 1] << " " << -a[n - 1] << " " << (a[n - 3] + a[n - 2]);
    else if ((a[n - 1] + a[n - 2]) != 0)
      cout << (a[n - 1] + a[n - 2]) << " " << -a[n - 3] << " " << -a[n - 3];
    else if ((a[n - 1] + a[n - 3]) != 0)
      cout << -a[n - 2] << " " << (a[n - 1] + a[n - 3]) << " " << -a[n - 2];
  }
  cout << "\n";
}
int32_t main() {
  long long t = 0;
  cin >> t;
  while (t--) solveCase();
}
