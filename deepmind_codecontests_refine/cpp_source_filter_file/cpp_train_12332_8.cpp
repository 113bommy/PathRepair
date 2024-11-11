#include <bits/stdc++.h>
using namespace std;
int main() {
  map<string, int> talla;
  talla["S"] = 0;
  talla["M"] = 1;
  talla["L"] = 2;
  talla["XL"] = 3;
  talla["XXL"] = 4;
  map<int, string> ind;
  ind[0] = "S";
  ind[1] = "M";
  ind[2] = "L";
  ind[3] = "XL";
  ind[4] = "XXL";
  int of[5];
  for (int i = 0; i < 5; i++) cin >> of[i];
  int k;
  cin >> k;
  for (int i = 0; i < k; i++) {
    string s;
    cin >> s;
    int bus = talla[s];
    for (int i = 0; i < 5; i++) {
      bus += i * pow(-1, i + 1);
      if (0 <= bus && bus <= 4 && of[bus] > 0) {
        of[bus]--;
        cout << ind[bus] << endl;
        break;
      }
    }
  }
  return 0;
}
