#include <bits/stdc++.h>
using namespace std;
int hboys[101];
int hgirls[101];
int b, g, n, m;
bool check() {
  int k = max(n, m), i;
  int x, y;
  for (i = 0; i <= (4 * k); i++) {
    x = i % n;
    y = i % m;
    if (hboys[x] == 1) {
      hgirls[y] = 1;
    } else if (hgirls[y] == 1) {
      hboys[x] = 1;
    }
  }
  for (i = 0; i < n; i++) {
    if (hboys[i] == 0) {
      return false;
    }
  }
  for (i = 0; i < m; i++) {
    if (hgirls[i] == 0) {
      return false;
    }
  }
  return true;
}
int main(int argc, char const *argv[]) {
  int i, k;
  cin >> n >> m;
  for (i = 0; i <= 100; i++) {
    hboys[i] = 0, hgirls[i] = 0;
  }
  cin >> b;
  for (i = 0; i < b; i++) {
    cin >> k;
    hboys[k] = 1;
  }
  cin >> g;
  for (i = 0; i < g; i++) {
    cin >> k;
    hgirls[k] = 1;
  }
  if (check())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
