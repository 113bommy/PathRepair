#include <bits/stdc++.h>
using namespace std;
int n, m, index1 = 1, index2 = 1, a[300000 + 2][9];
map<int, int> o;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) cin >> a[i][j];
  int x1 = 0, x2 = 10;
  while (x1 <= x2) {
    int v = (x1 + x2) / 2;
    while (o.size()) o.erase(o.begin());
    for (int i = 0; i < n; i++) {
      int s = 1;
      int t = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] >= v) {
          t += s;
        }
        s *= 2;
      }
      o[t] = i + 1;
    }
    int lam = 0;
    while (o.size()) {
      int y = (*o.begin()).first;
      for (int k = 0; k <= 300; k++) {
        if ((y | k) == pow(2, m) - 1 && (o.count(k))) {
          index1 = (*o.begin()).second;
          index2 = (*o.find(k)).second;
          lam = 1;
        }
      }
      o.erase(o.begin());
    }
    if (lam)
      x1 = v + 1;
    else
      x2 = v - 1;
  }
  cout << index1 << ' ' << index2;
}
