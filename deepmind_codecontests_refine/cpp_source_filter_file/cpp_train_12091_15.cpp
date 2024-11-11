#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i, k, m, p;
  cin >> n >> m >> k;
  long long int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  if (a[n - 2] == a[n - 1])
    cout << a[n - 1] * m << endl;
  else {
    p = (m / k) - 1;
    cout << p * a[n - 2] + (m - p) * a[n - 1];
  }
  return 0;
}
