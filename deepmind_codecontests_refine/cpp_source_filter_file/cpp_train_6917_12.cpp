#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, i, j, a, b, c[101] = {}, y = 0;
  cin >> n >> m;
  for (i = 0; i < m; i++) {
    cin >> a >> b;
    for (j = a; j <= b; j++) {
      c[j]++;
    }
  }
  for (i = 1; i < n; i++) {
    if (c[i] != 1) {
      cout << i << " " << c[i];
      y = 1;
      break;
    }
  }
  if (y == 0) cout << "OK";
}
