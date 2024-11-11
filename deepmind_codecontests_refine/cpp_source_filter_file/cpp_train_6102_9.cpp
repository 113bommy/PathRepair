#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n % 2 == 0 && a[0] % 2 == 1 && a[n - 1] % 2 == 1)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
