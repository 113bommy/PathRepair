#include <bits/stdc++.h>
using namespace std;
int main() {
  int tx, ty;
  cin >> tx >> ty;
  string s;
  cin >> s;
  int n = s.size();
  vector<int> px(n + 1), py(n + 1);
  int dx = 0, dy = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'U')
      ++dy;
    else if (s[i] == 'D')
      --dy;
    else if (s[i] == 'L')
      --dx;
    else if (s[i] == 'R')
      ++dx;
    px[i] = dx;
    py[i] = dy;
  }
  px[n] = py[n] = 0;
  ++n;
  bool status = (tx == 0 and ty == 0);
  double k;
  for (int i = 0; i < n; ++i)
    if (px[i] == tx and py[i] == ty) status = true;
  for (int i = 0; i < n; ++i) {
    if (dx != 0)
      k = double(tx - px[i]) / dx;
    else if (dy != 0)
      k = double(ty - py[i]) / dy;
    else
      k = 0;
    if (floor(k) == k and k >= 0 and dy * k + py[i] == tx and
        dy * k + py[i] == ty)
      status = true;
  }
  if (status)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
