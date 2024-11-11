#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, m, d, a[101];
  cin >> n >> d;
  a[0] = 0;
  for (i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  for (i = 1; i <= n; i++) a[i] += a[i - 1];
  cin >> m;
  if (m <= n)
    cout << a[m];
  else
    cout << (n - m) + a[n];
  return 0;
}
