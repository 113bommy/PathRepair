#include <bits/stdc++.h>
using namespace std;
char a[1000][1000], b[1000][1000];
int main() {
  int w, h;
  cin >> w >> h;
  for (int _n(h), i(0); i < _n; i++) cin >> a[i];
  for (int _n(w), i(0); i < _n; i++)
    for (int _n(h), j(0); j < _n; j++) b[i][j] = a[j][i];
  swap(h, w);
  for (int _n(h), i(0); i < _n; i++)
    for (int _n(w), j(0); j < _n; j++) swap(b[i][j], b[h - i - 1][w]);
  for (int _n(h), i(0); i < _n; i++) {
    for (int _n(w), j(0); j < _n; j++) cout << b[i][j] << b[i][j];
    cout << endl;
    for (int _n(w), j(0); j < _n; j++) cout << b[i][j] << b[i][j];
    cout << endl;
  }
  return 0;
}
