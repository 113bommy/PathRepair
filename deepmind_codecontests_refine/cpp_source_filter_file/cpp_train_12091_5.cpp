#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  long long a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  if (k + 1 > m)
    cout << m * a[n];
  else {
    if (m % (k + 1) == 0)
      cout << a[n] * (m / (k + 1)) * k + a[n - 1] * (m / (k + 1));
    else
      cout << a[n] * (m / (k + 1)) * k + a[n - 1] * (m / (k + 1)) +
                  (m - (m / (k - 1))) * a[n];
  }
  return 0;
}
