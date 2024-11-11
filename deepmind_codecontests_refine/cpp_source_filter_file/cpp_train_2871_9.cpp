#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m = 0, k;
  cin >> n;
  long long a[n];
  k = (n - 1) / 2;
  for (int i = 0; i < n; i++) {
    cin >> m;
    if (n % 2 == 1) {
      if (i % 2 == 0)
        a[n - i - 1] = m;
      else
        a[i] = m;
    } else if (n == 2)
      a[n - i - 1] = m;
    else {
      if (i < k && i % 2 == 0)
        a[n - i - 1] = m;
      else if (i > k && i % 2 == 1)
        a[n - i - 1] = m;
      else
        a[i] = m;
    }
  }
  for (int i = 0; i < n; i++) cout << a[i] << " ";
  return 0;
}
