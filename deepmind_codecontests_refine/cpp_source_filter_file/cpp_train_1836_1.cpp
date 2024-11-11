#include <bits/stdc++.h>
using namespace std;
int main() {
  string X, Y, Z;
  int x = 0, y = 0, z = 0, xy = 0, yz = 0, xz = 0;
  string n[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "B", "H"};
  cin >> X >> Y >> Z;
  for (int i = 0; i < 12; i++) {
    if (n[i] == X) {
      x = i;
    } else if (n[i] == Y) {
      y = i;
    } else if (n[i] == Z) {
      z = i;
    }
  }
  xy = y - x;
  yz = z - y;
  if (xy < 0) {
    xy += 12;
  }
  if (yz < 0) {
    yz += 12;
  }
  if (xy == 4 && yz == 3) {
    cout << "major";
  } else if (xy == 3 && yz == 4) {
    cout << "minor";
  } else {
    xz = z - x;
    yz = y - z;
    if (xz < 0) {
      xz += 12;
    }
    if (yz < 0) {
      yz += 12;
    }
    if (xz == 4 && yz == 3) {
      cout << "major";
    } else if (xz == 3 && yz == 4) {
      cout << "minor";
    } else {
      xz = x - z;
      xy = y - x;
      if (xy < 0) {
        xy += 12;
      }
      if (xz < 0) {
        xz += 12;
      }
      if (xz == 4 && xy == 3) {
        cout << "major";
      } else if (xz == 3 && xy == 4) {
        cout << "minor";
      } else {
        yz = y - z;
        xy = x - y;
        if (yz < 0) {
          yz += 12;
        }
        if (yz < 0) {
          yz += 12;
        }
        if (yz == 4 && xy == 3) {
          cout << "major";
        } else if (yz == 3 && xy == 4) {
          cout << "minor";
        } else {
          yz = z - y;
          xz = x - z;
          if (xz < 0) {
            xz += 12;
          }
          if (yz < 0) {
            yz += 12;
          }
          if (yz == 4 && xz == 3) {
            cout << "major";
          } else if (yz == 3 && xz == 4) {
            cout << "minor";
          } else {
            xy = x - y;
            xz = z - x;
            if (xz < 0) {
              xz += 12;
            }
            if (xy < 0) {
              xy += 12;
            }
            if (xy == 4 && xz == 3) {
              cout << "major";
            } else if (xy == 3 && xz == 4) {
              cout << "minor";
            } else {
              cout << "strange";
            }
          }
        }
      }
    }
  }
  return 0;
}
