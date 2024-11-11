#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, min = 0;
  cin >> n >> m;
  int f[1000];
  for (i = 0; i < m; i++) {
    cin >> f[i];
  }
  sort(f, f + m);
  min = f[n - 1] - f[0];
  for (i = 1; i < m - n; i++) {
    if ((f[i + n - 1] - f[i]) < min) min = f[i + n - 1] - f[i];
  }
  cout << min;
  return 0;
}
