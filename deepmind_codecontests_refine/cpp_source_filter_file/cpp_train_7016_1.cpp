#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9 + 7;
const int mod = (int)1e9 + 9;
const int MAX = (int)1e6 + 5;
const int NMAX = (int)1e2 + 5;
const double PI = 2 * acos(0.0);
long long sq(long long n) { return n * n; }
int main(void) {
  ios_base::sync_with_stdio(false);
  int x[8], y[8];
  set<int> xs, ys;
  for (int i = 0; i < 8; i++) {
    cin >> x[i] >> y[i];
    xs.insert(x[i]);
    ys.insert(y[i]);
  }
  if (xs.size() != 3 || ys.size() != 3) {
    cout << "ugly\n";
    return 0;
  }
  for (auto i = xs.begin(); i != xs.end(); i++) {
    for (auto j = xs.begin(); j != ys.end(); j++) {
      if (i == ++xs.begin() && j == ++ys.begin()) continue;
      int xx = *i;
      int yy = *j;
      int f = 0;
      for (int k = 0; k < 8; k++) {
        if (x[k] == xx && y[k] == yy) {
          f = 1;
          break;
        }
      }
      if (!f) {
        cout << "ugly\n";
        return 0;
      }
    }
  }
  cout << "respectable\n";
  return 0;
}
