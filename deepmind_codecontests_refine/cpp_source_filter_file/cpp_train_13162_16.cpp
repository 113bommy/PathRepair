#include <bits/stdc++.h>
using namespace std;
int a[1003];
char s[1003];
int main() {
  int i, j, k, ans, n, m;
  cin >> n >> m;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  k = j = 0;
  for (i = 0; i < n - 1; i++) {
    if (j + a[i] < m) {
      j += a[i];
    } else
      k = 1;
  }
  if (k == 0)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}
