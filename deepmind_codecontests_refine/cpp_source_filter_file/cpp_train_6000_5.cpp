#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc, ca = 0;
  int x1, y1;
  int x2, y2;
  cin >> x1 >> y1;
  cin >> x2 >> y2;
  int rd = 0;
  int cd = 0;
  if (x1 == x2) {
    rd = 2;
    cd = abs(y1 - y2) + 1;
  } else if (y1 == y2) {
    rd = abs(x1 - x2);
    cd = 2;
  } else {
    rd = abs(x1 - x2) + 1;
    cd = abs(y1 - y2) + 1;
  }
  cout << (rd + rd + cd + cd) << '\n';
  return 0;
}
