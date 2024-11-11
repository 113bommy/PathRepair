#include <bits/stdc++.h>
using namespace std;
int n, m, d, i, j, a[1008], b[1008], s;
int main() {
  cin >> n >> m >> d;
  for (i = 0; i < m; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s + (m + 1) * (d - 1) < n) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  i = 0;
  while (i < n) {
    i += min(n - i - s, d - 1);
    s -= a[j];
    while (a[j]) {
      b[++i] = j + 1;
      a[j]--;
    }
    j++;
  }
  for (i = 1; i <= n; i++) cout << b[i] << " ";
  return 0;
}
