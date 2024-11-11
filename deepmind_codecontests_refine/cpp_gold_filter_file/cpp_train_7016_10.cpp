#include <bits/stdc++.h>
using namespace std;
int vx[100];
int vy[100];
int vxs = 0;
int vys = 0;
set<pair<int, int> > P, Q;
pair<int, int> node[10];
void judge() {
  sort(vx, vx + vxs);
  sort(vy, vy + vys);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 1 && j == 1)
        continue;
      else {
        Q.insert(make_pair(vx[i], vy[j]));
        if (P.find(make_pair(vx[i], vy[j])) == P.end()) {
          cout << "ugly" << endl;
          return;
        }
      }
    }
  }
  cout << "respectable" << endl;
}
void input() {
  for (int i = 0; i < 8; i++) {
    int x, y = 0;
    cin >> x >> y;
    node[i] = make_pair(x, y);
    P.insert(make_pair(x, y));
    bool flg = false;
    for (int i = 0; i < vxs; i++) {
      if (vx[i] == x) {
        flg = true;
        break;
      }
    }
    if (!flg) vx[vxs++] = x;
    flg = false;
    for (int i = 0; i < vys; i++) {
      if (vy[i] == y) {
        flg = true;
        break;
      }
    }
    if (!flg) {
      vy[vys++] = y;
    }
  }
  if (vxs != 3 || vys != 3) {
    cout << "ugly" << endl;
    return;
  }
  judge();
}
int main() {
  input();
  return 0;
}
