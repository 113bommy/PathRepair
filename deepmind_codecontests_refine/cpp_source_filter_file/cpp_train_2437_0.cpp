#include <bits/stdc++.h>
using namespace std;
int n, a[111], i, u1, u2 = 0, u3 = 0, kol = 0;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  reverse(a + 1, a + n + 1);
  u1 = 1;
  for (i = 1; i <= n; i++) {
    if (a[i] < 0 && u2 == 0) u2 = i;
  }
  cout << a[u1] << " ";
  for (i = u2; i > 1; i--) cout << a[i] << " ";
  cout << a[n];
  return 0;
}
