#include <bits/stdc++.h>
using namespace std;
int a[5];
int b[5][5];
int c[1009];
map<string, int> mapa;
map<int, string> mapa2;
void init() {
  b[0][0] = 0;
  b[0][1] = 1;
  b[0][2] = 2;
  b[0][3] = 3;
  b[0][4] = 4;
  b[1][0] = 1;
  b[1][1] = 2;
  b[1][2] = 0;
  b[1][3] = 3;
  b[1][4] = 4;
  b[2][0] = 2;
  b[2][1] = 3;
  b[2][2] = 1;
  b[2][3] = 4;
  b[2][4] = 0;
  b[3][0] = 3;
  b[3][1] = 4;
  b[3][2] = 2;
  b[3][3] = 1;
  b[3][4] = 0;
  b[4][0] = 4;
  b[4][1] = 3;
  b[4][2] = 2;
  b[4][3] = 1;
  b[4][4] = 0;
  mapa["S"] = 0;
  mapa["M"] = 1;
  mapa["L"] = 2;
  mapa["XL"] = 3;
  mapa["XXL"] = 4;
  mapa2[0] = "S";
  mapa2[1] = "M";
  mapa2[2] = "L";
  mapa2[3] = "X";
  mapa2[4] = "XXL";
}
int main() {
  int k;
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }
  string linea;
  cin >> k;
  init();
  int p;
  for (int i = 0; i < k; i++) {
    cin >> linea;
    p = mapa[linea];
    c[i] = p;
  }
  int id, v;
  for (int i = 0; i < k; i++) {
    id = c[i];
    for (int j = 0; j < 5; j++) {
      v = b[id][j];
      if (a[v] > 0) {
        a[v]--;
        printf("%s\n", mapa2[v].c_str());
        break;
      }
    }
  }
}
