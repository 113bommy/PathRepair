#include <bits/stdc++.h>
using namespace std;
void impossible_move() {
  cout << "NO";
  exit(0);
}
void mainloop(const vector<int>& m, int last, int next, int& lx, int& ly) {
  last = m[0];
  int mod;
  for (int i = 1; i < m.size(); i++) {
    next = m[i];
    mod = abs(next - last);
    if (mod == 0) impossible_move();
    if (mod == 1) {
      if (ly > 1) {
        if (next > last && !(last % lx)) impossible_move();
        if (last > next && !(next % lx)) impossible_move();
      }
      if (ly == 1 && next > lx) lx++;
    }
    if (mod > 1) {
      if (ly == 1) {
        lx = mod;
        ly = 100000000;
      }
      if (ly > 1 && (next % lx != last % lx)) impossible_move();
    }
    last = next;
  }
}
int main() {
  int n;
  cin >> n;
  int last, next;
  int lx, ly = 1;
  vector<int> m(n);
  for (int i = 0; i < n; i++) cin >> m[i];
  lx = m[0];
  for (int i = 0; i < 2; i++) mainloop(m, last, next, lx, ly);
  cout << "YES\n" << ly << ' ' << lx;
  return 0;
}
