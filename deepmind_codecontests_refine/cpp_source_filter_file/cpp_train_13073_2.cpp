#include <bits/stdc++.h>
using namespace std;
char a[1001];
int x[1001], y[1001], g[1001];
int main() {
  int n, b, c, c1, cnt = 0, z = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    x[i] = a[i] - 48;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    y[i] = a[i] - 48;
  }
  sort(y + 1, y + 1 + n);
  for (int i = 1; i <= n; i++) {
    g[i] = y[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (x[i] <= y[j]) {
        b++;
        y[j] = -1;
        break;
      }
    }
  }
  cout << n - b << endl;
  b = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (x[i] < g[j]) {
        b++;
        g[j] = -1;
        break;
      }
    }
  }
  cout << b;
  return 0;
}
