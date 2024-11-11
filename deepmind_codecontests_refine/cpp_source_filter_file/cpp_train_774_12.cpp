#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n;
  int b[n];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cin >> m;
  int g[n];
  for (int i = 0; i < m; i++) {
    cin >> g[i];
  }
  sort(b, b + n);
  sort(g, g + m);
  int p = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] == 10000) {
      continue;
    }
    for (int j = 0; j < m; j++) {
      if (g[j] == 10000) continue;
      if (abs(b[i] - g[j]) < 2) {
        p++;
        g[j] = 10000;
        b[i] = 10000;
      }
    }
  }
  cout << p;
  return 0;
}
