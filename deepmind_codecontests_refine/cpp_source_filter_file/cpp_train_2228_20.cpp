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
  int min = INT_MAX;
  if (m == n)
    cout << (a[m - 1] - a[0]);
  else {
    for (int i = 0; i < m - n; i++) {
      int diff = a[n - 1 + i] - a[i];
      if (min > diff) min = diff;
    }
    cout << min;
  }
}
