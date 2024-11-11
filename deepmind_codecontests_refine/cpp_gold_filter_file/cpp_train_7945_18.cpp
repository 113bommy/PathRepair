#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int x, y;
  vector<int> vx, vy;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    vx.push_back(x);
    vy.push_back(y);
  }
  int c = 0;
  for (int i = 0; i < n; i++) {
    bool r = 0, l = 0, u = 0, d = 0;
    for (int j = 0; j < n; j++) {
      if (vx[j] > vx[i] && vy[j] == vy[i]) r = 1;
      if (vx[j] < vx[i] && vy[j] == vy[i]) l = 1;
      if (vx[j] == vx[i] && vy[j] > vy[i]) u = 1;
      if (vx[j] == vx[i] && vy[j] < vy[i]) d = 1;
    }
    if (r && l && u && d) c++;
  }
  cout << c;
}
