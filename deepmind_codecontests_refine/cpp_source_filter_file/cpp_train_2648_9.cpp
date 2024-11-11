#include <bits/stdc++.h>
using namespace std;
const int MX = 25;
bool win(int d1, int a1, int d2, int a2) {
  if (d1 > a2 && a1 > d2) return true;
  return false;
}
bool draw(int d, int a, int dd, int aa) {
  if (d == aa && a == dd) return true;
  return false;
}
int main(int argc, char *argv[]) {
  ios ::sync_with_stdio(false);
  cin.tie(NULL);
  int d0, d1, d2, d3, a0, a1, a2, a3;
  cin >> d0 >> a0 >> d1 >> a1 >> d2 >> a2 >> d3 >> a3;
  bool w1 = win(d0, a1, d2, a3);
  bool w2 = win(d0, a1, d3, a2);
  if (w1 && w2) {
    cout << "Team 1" << '\n';
    return 0;
  }
  bool w3 = win(d1, a0, d2, a3);
  bool w4 = win(d1, a0, d3, a2);
  if (w3 && w4) {
    cout << "Team 1" << '\n';
    return 0;
  }
  bool x1 = win(d2, a3, d0, a1);
  bool x2 = win(d2, a3, d1, a0);
  if (!x1 && !x2) {
    cout << "Draw" << '\n';
    return 0;
  }
  bool x3 = win(d3, a2, d0, a1);
  bool x4 = win(d3, a2, d1, a0);
  if (!x3 && !x4) {
    cout << "Draw" << '\n';
    return 0;
  }
  cout << "Team 2" << '\n';
  return 0;
}
