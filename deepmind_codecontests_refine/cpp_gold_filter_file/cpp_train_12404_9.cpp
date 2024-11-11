#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m, r, x = 0, sum, i;
  cin >> n >> m >> r;
  long int a[n], b[m];
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < m; i++) {
    cin >> b[i];
  }
  sort(a, a + n);
  sort(b, b + m);
  if (b[m - 1] > a[0]) {
    sum = ((r / a[0]) * b[m - 1] + r % a[0]);
  } else
    sum = r;
  cout << sum;
}
