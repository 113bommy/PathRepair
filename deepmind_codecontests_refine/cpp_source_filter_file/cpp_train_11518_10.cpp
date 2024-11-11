#include <bits/stdc++.h>
using namespace std;
int gr[7][15] = {{},
                 {0, 1, 2, 4, 3, 22, 21, 18, 17, 6, 5, 14, 13},
                 {0, 5, 6, 8, 7, 3, 4, 17, 19, 10, 9, 16, 14},
                 {0, 9, 10, 12, 11, 7, 8, 19, 20, 23, 24, 15, 16},
                 {0, 13, 14, 16, 15, 1, 3, 5, 7, 9, 11, 24, 22},
                 {0, 17, 18, 20, 19, 4, 2, 21, 23, 12, 10, 8, 6},
                 {0, 21, 22, 24, 23, 2, 1, 13, 15, 11, 12, 20, 18}};
int col[30];
int buf[30];
int check_solve() {
  int a = 0;
  for (int i = 4; i <= 24; i += 4) {
    if (buf[i] == buf[i - 1] && buf[i - 1] == buf[i - 2] &&
        buf[i - 2] == buf[i - 3] && buf[i - 3] == buf[i])
      a++;
  }
  return (a == 6);
}
void turn_r(int id) {
  int cl = buf[gr[id][1]];
  for (int i = 2; i <= 4; ++i) {
    int a = cl;
    cl = buf[gr[id][i]];
    buf[gr[id][i]] = a;
  }
  buf[gr[id][1]] = cl;
  int a1 = buf[gr[id][5]];
  int b1 = buf[gr[id][6]];
  for (int i = 8; i <= 12; i += 2) {
    int a2 = buf[gr[id][i - 1]];
    int b2 = buf[gr[id][i]];
    buf[gr[id][i - 1]] = a1;
    buf[gr[id][i]] = b1;
    a1 = a2;
    b1 = b2;
  }
  buf[gr[id][5]] = a1;
  buf[gr[id][6]] = b1;
}
void turn_l(int id) {
  int cl = buf[gr[id][1]];
  for (int i = 4; i <= 2; --i) {
    int a = cl;
    cl = buf[gr[id][i]];
    buf[gr[id][i]] = a;
  }
  buf[gr[id][1]] = cl;
  int a1 = buf[gr[id][5]];
  int b1 = buf[gr[id][6]];
  for (int i = 12; i <= 8; i -= 2) {
    int a2 = buf[gr[id][i - 1]];
    int b2 = buf[gr[id][i]];
    buf[gr[id][i - 1]] = a1;
    buf[gr[id][i]] = b1;
    a1 = a2;
    b1 = b2;
  }
  buf[gr[id][5]] = a1;
  buf[gr[id][6]] = b1;
}
void solve() {
  for (int i = 1; i <= 24; ++i) {
    cin >> col[i];
  }
  for (int i = 1; i <= 6; ++i) {
    for (int i = 1; i <= 24; ++i) {
      buf[i] = col[i];
    }
    turn_r(i);
    if (check_solve()) {
      cout << "YES\n";
      return;
    }
    for (int i = 1; i <= 24; ++i) {
      buf[i] = col[i];
    }
    turn_l(i);
    if (check_solve()) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO" << endl;
}
int main() {
  int ts = 1;
  for (int i = 0; i < ts; ++i) solve();
  return 0;
}
