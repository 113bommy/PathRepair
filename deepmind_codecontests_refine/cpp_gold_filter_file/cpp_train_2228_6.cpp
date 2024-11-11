#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, min = 999999, i, j, a[200001], s, b[200001];
  cin >> n >> m;
  for (i = 1; i <= m; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + m + 1);
  for (i = 1; i < m; i++) {
    b[i] = a[i + 1] - a[i];
  }
  for (i = 1; i <= m - n + 1; i++) {
    s = 0;
    for (j = 0; j < n - 1; j++) {
      s += b[i + j];
    }
    if (s < min) min = s;
  }
  cout << min;
  return 0;
}
