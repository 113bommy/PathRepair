#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, c = 1, i;
  cin >> n >> m;
  long long a[m];
  for (i = 0; i < m; i++) cin >> a[i];
  for (i = 0; i < m; i++) {
    if (a[i] <= a[i + 1]) {
    } else
      c++;
  }
  if (c > 1)
    cout << (n) * (c - 2) + (n - 1) + a[m - 1];
  else
    cout << a[m - 1] - 1;
}
