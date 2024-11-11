#include <bits/stdc++.h>
using namespace std;
inline int toInt(string s) {
  int v;
  istringstream sin(s);
  sin >> v;
  return v;
}
template <class T>
inline string toString(T x) {
  ostringstream sout;
  sout << x;
  return sout.str();
}
const double EPS = 1e-10;
const double PI = acos(-1.0);
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> X(n), Y(n);
  for (int i = (0); i < (n); ++i) cin >> X[i] >> Y[i];
  int preX = X[0], preY = Y[0];
  int ret = 0;
  for (int i = (1); i < (n); ++i) {
    int dirX1, dirX2, dirY1, dirY2;
    dirX1 = X[i] - preX;
    dirX2 = X[i + 1] - X[i];
    dirY1 = Y[i] - preY;
    dirY2 = Y[i + 1] - Y[i];
    preX = X[i];
    preY = Y[i];
    string dir1, dir2;
    if (dirX1 == 0) {
      if (dirY1 < 0)
        dir1 = "S";
      else
        dir1 = "N";
    } else {
      if (dirX1 < 0)
        dir1 = "W";
      else
        dir1 = "E";
    }
    if (dirX2 == 0) {
      if (dirY2 < 0)
        dir2 = "S";
      else
        dir2 = "N";
    } else {
      if (dirX2 < 0)
        dir2 = "W";
      else
        dir2 = "E";
    }
    if (dir1 == "N" && dir2 == "W") ret++;
    if (dir1 == "E" && dir2 == "N") ret++;
    if (dir1 == "S" && dir2 == "E") ret++;
    if (dir1 == "W" && dir2 == "S") ret++;
  }
  cout << ret << endl;
  return 0;
}
