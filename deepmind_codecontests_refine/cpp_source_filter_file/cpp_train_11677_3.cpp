#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  int dif = 0;
  int col = 1;
  bool pano = true;
  int rowt = 1;
  int rowb = n;
  cout << 1 << " " << 1 << endl;
  while (rowt < rowb) {
    col = 1;
    int posa = 1;
    pano = true;
    while (posa < 2 * m) {
      if (pano)
        cout << rowb << " " << m - col + 1 << "\n";
      else {
        cout << rowt << " " << col + 1 << "\n";
        col++;
      }
      posa++;
      pano = !pano;
    }
    rowt++;
    rowb--;
    if (rowb == rowt) {
      cout << rowt << " " << 1 << endl;
    }
    if (rowb <= rowt) break;
    cout << rowt << " " << 1 << endl;
    dif++;
  }
  if (rowt == rowb) {
    int dif = 0;
    bool p = 1;
    int posa = 1;
    while (posa < m) {
      if (p)
        cout << rowt << " " << m - dif << "\n";
      else
        cout << rowt << " " << 1 + dif << "\n";
      p = !p;
      posa++;
      if (p) dif++;
    }
  }
  return 0;
}
