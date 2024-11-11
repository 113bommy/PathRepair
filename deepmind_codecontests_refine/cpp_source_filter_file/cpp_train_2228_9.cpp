#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  sort(a, a + m);
  int x = a[n - 1] - a[0];
  int y;
  for (int i = 1; i < m - n; i++) {
    y = a[i + n - 1] - a[i];
    x = min(y, x);
  }
  cout << x;
  return 0;
}
