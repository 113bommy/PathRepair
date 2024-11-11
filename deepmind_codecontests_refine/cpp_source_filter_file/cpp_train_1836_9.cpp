#include <bits/stdc++.h>
using namespace std;
int b[3];
string a[12];
int get(string st) {
  for (int i = 0; i < 12; i++)
    if (st == a[i]) return i;
}
void init() {
  a[0] = "C";
  a[1] = "C#";
  a[2] = "D";
  a[3] = "D#";
  a[4] = "E";
  a[5] = "F";
  a[6] = "F#";
  a[7] = "G";
  a[8] = "G#";
  a[9] = "A";
  a[10] = "B";
  a[11] = "H";
  string st;
  for (int i = 0; i < 3; i++) {
    cin >> st;
    b[i] = get(st);
  }
}
int check(int x, int y, int z) {
  int d1 = y - x, d2 = z - y;
  if (d1 < 0) d1 += 12;
  if (d2 < 0) d2 += 12;
  if (d1 == 4 && d2 == 3)
    return 0;
  else if (d1 == 3 && d2 == 4)
    return 1;
  else
    return 2;
}
void solve() {
  string ans[] = {"major", "minor"};
  if (check(b[0], b[1], b[2]) != 2)
    cout << ans[check(b[0], b[1], b[2])] << endl;
  else if (check(b[0], b[2], b[1]) != 2)
    cout << ans[check(b[0], b[2], b[1])] << endl;
  else if (check(b[1], b[0], b[2]) != 2)
    cout << ans[check(b[1], b[0], b[2])] << endl;
  else if (check(b[1], b[1], b[0]) != 2)
    cout << ans[check(b[1], b[2], b[0])] << endl;
  else if (check(b[2], b[0], b[1]) != 2)
    cout << ans[check(b[2], b[0], b[1])] << endl;
  else if (check(b[2], b[1], b[0]) != 2)
    cout << ans[check(b[2], b[1], b[0])] << endl;
  else
    cout << "strange" << endl;
}
int main() {
  init();
  solve();
}
