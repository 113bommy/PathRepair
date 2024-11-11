#include <bits/stdc++.h>
using namespace std;
int color[25];
int box[7];
int main() {
  for (int i = 1; i <= 24; i++) cin >> color[i];
  int co = 0;
  for (int i = 1; i <= 24; i = i + 4) {
    if ((color[i] == color[i + 1]) && (color[i + 2] == color[i + 3]) &&
        (color[i] == color[i + 2]))
      box[(i / 4) + 1] = 1, co++;
  }
  if (co != 2) {
    cout << "no" << endl;
    return 0;
  }
  if ((box[1] != box[3]) || (box[2] != box[6]) || box[4] != box[5]) {
    cout << "no" << endl;
    return 0;
  }
  if ((box[4] == box[5]) && (box[4] == 1)) {
    if ((color[1] == color[3]) && (color[2] == color[4]) &&
        (color[5] == color[7]) && (color[6] == color[8]) &&
        (color[9] == color[11]) && (color[10] == color[12]) &&
        (color[21] == color[23]) && (color[22] == color[24])) {
    } else {
      cout << "no" << endl;
      return 0;
    }
    if ((color[1] == color[6]) && (color[5] == color[10]) &&
        (color[9] == color[21]) && (color[2] == color[22])) {
      cout << "yes" << endl;
      return 0;
    } else if ((color[2] == color[5]) && (color[6] == color[9]) &&
               (color[22] == color[10]) && (color[21] == color[1])) {
      cout << "yes" << endl;
      return 0;
    } else {
      cout << "no" << endl;
      return 0;
    }
  }
  if ((box[1] == box[3]) && (box[1] == 1)) {
    if ((color[13] == color[14]) && (color[15] == color[16]) &&
        (color[5] == color[6]) && (color[7] == color[8]) &&
        (color[17] == color[18]) && (color[19] == color[20]) &&
        (color[21] == color[22]) && (color[23] == color[24])) {
    } else {
      cout << "no" << endl;
      return 0;
    }
    if ((color[13] == color[7]) && (color[5] == color[19]) &&
        (color[17] == color[23]) && (color[21] == color[15])) {
      cout << "yes" << endl;
      return 0;
    } else if ((color[5] == color[15]) && (color[17] == color[7]) &&
               (color[21] == color[19]) && (color[13] == color[23])) {
      cout << "yes" << endl;
      return 0;
    } else {
      cout << "no" << endl;
      return 0;
    }
  }
  if ((box[2] == box[6]) && (box[2] == 1)) {
    if ((color[13] == color[15]) && (color[14] == color[16]) &&
        (color[4] == color[3]) && (color[1] == color[2]) &&
        (color[17] == color[19]) && (color[20] == color[18]) &&
        (color[9] == color[10]) && (color[11] == color[12])) {
    } else {
      cout << "no" << endl;
      return 0;
    }
    if ((color[1] == color[14]) && (color[3] == color[18]) &&
        (color[17] == color[11]) && (color[9] == color[13])) {
      cout << "yes" << endl;
      return 0;
    } else if ((color[13] == color[3]) && (color[1] == color[17]) &&
               (color[18] == color[9]) && (color[14] == color[11])) {
      cout << "yes" << endl;
      return 0;
    } else {
      cout << "no" << endl;
      return 0;
    }
  }
}
