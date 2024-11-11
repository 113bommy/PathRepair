#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b;
  vector<int> v(12);
  v[0] = 31;
  v[1] = 28;
  v[2] = 31;
  v[3] = 30;
  v[4] = 31;
  v[5] = 30;
  v[6] = 31;
  v[7] = 31;
  v[8] = 30;
  v[9] = 31;
  v[10] = 30;
  v[11] = 31;
  int misa = 1, cont = 0;
  ;
  int m[6][7];
  int l = b - 1;
  for (int i = 0; i < 6; ++i) {
    for (int j = l; j < 7; ++j) {
      m[i][j] = misa;
      if (misa == v[a - 1]) {
        cont++;
        goto poti;
      }
      misa++;
    }
    cont++;
    l = 0;
  }
poti:;
  cout << cont << endl;
  return 0;
}
