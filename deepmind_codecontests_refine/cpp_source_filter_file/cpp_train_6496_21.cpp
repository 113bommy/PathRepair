#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int a[m];
  int start = 1, c = 0;
  for (int i = 0; i < m; i++) cin >> a[i];
  for (int i = 0; i < m; i++) {
    if (a[i] != start) {
      if (start < a[i]) {
        c += a[i] - start;
        start = a[i];
      } else
        c += (n - start + a[i]);
      start = a[i];
    } else
      continue;
  }
  cout << c << endl;
  return 0;
}
