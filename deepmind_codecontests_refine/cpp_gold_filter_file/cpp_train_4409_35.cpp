#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX = 110;
int n, m, x[MAX], y[MAX];
char a[MAX][MAX];
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0, _n = (n); i < _n; ++i) cin >> a[i];
  for (int i = 0, _n = (n); i < _n; ++i) {
    for (int j = 0, _n = (m); j < _n; ++j) {
      if (a[i][j] == '*') {
        x[i]++;
        y[j]++;
      }
    }
  }
  int ansx, ansy;
  for (int i = 0, _n = (101); i < _n; ++i) {
    if (x[i] == 1) ansx = i;
    if (y[i] == 1) ansy = i;
  }
  ansx++, ansy++;
  cout << ansx << " " << ansy << endl;
  return 0;
}
