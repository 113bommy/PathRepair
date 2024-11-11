#include <bits/stdc++.h>
using namespace std;
struct com {
  int a, d;
  com(int aa, int bb) {
    d = aa;
    a = bb;
  }
};
int comare(com a, com b) {
  if (a.a > b.a && a.d > b.d) return 1;
  if (a.a < b.a && a.d < b.d) return -1;
  return 0;
}
int main() {
  int T[5][4];
  while (1) {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 2; j++) {
        cin >> T[i][j];
      }
    }
    com ft1 = com(T[0][0], T[1][1]);
    com ft2 = com(T[1][0], T[0][1]);
    com st1 = com(T[2][0], T[3][1]);
    com st2 = com(T[3][0], T[2][1]);
    int fbat = comare(ft1, st1);
    int sbat = comare(ft1, st2);
    int tbat = comare(ft2, st1);
    int fobat = comare(ft2, st2);
    if ((fbat > 0 && sbat > 0) || (tbat > 0 && fobat > 0)) {
      cout << "Team 1" << endl;
      return 0;
    }
    if ((fbat < 0 || sbat < 0) && (tbat < 0 || fobat < 0)) {
      cout << "Team 2" << endl;
      return 0;
    }
    cout << "Draw" << endl;
    return 0;
  }
}
