#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n], b[m];
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(a, a + n);
  sort(b, b + m);
  int x1 = 0, x2 = 0;
  while (x1 < n && x2 < m) {
    if (b[x2] >= a[x1]) {
      x1++;
      x2++;
    } else
      x2++;
  }
  if (x1 == n)
    cout << "NO";
  else
    cout << "YES";
}
