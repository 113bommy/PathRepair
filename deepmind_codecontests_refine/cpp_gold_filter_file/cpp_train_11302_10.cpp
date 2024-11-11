#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535898;
const char spc = ' ';
int inf_int = 2e9;
long long inf_ll = 2e18;
const double EPS = 1e-8;
const long long MOD = 1e9 + 7;
int t;
void solve() {
  int n;
  int x0, y0;
  cin >> n;
  cin >> x0 >> y0;
  swap(x0, y0);
  y0 = -y0;
  long long ver = x0;
  long long hor = y0;
  long long d1 = x0 + y0;
  long long d2 = abs(x0 - y0);
  long long top = inf_ll;
  char toptype = 'X';
  long long tr = inf_ll;
  char trtype = 'X';
  long long right = inf_ll;
  char righttype = 'X';
  long long br = inf_ll;
  char brtype = 'X';
  long long bottom = inf_ll;
  char bottomtype = 'X';
  long long bl = inf_ll;
  char bltype = 'X';
  long long left = inf_ll;
  char lefttype = 'X';
  long long tl = inf_ll;
  char tltype = 'X';
  for (int i = 0; i < n; i++) {
    char type;
    long long x, y;
    cin >> type >> x >> y;
    swap(x, y);
    y = -y;
    long long dist;
    if (x == ver) {
      dist = abs(y - y0);
      if (y > y0) {
        if (dist < top) {
          top = dist;
          toptype = type;
        }
      } else {
        if (dist < bottom) {
          bottom = dist;
          bottomtype = type;
        }
      }
    } else if (y == hor) {
      dist = abs(x - x0);
      if (x > x0) {
        if (dist < right) {
          right = dist;
          righttype = type;
        }
      } else {
        if (dist < left) {
          left = dist;
          lefttype = type;
        }
      }
    } else if (x + y == d1) {
      dist = abs(x - x0);
      if (x > x0) {
        if (dist < br) {
          br = dist;
          brtype = type;
        }
      } else {
        if (dist < tl) {
          tl = dist;
          tltype = type;
        }
      }
    } else if (abs(x - y) == d2) {
      dist = abs(x - x0);
      if (x > x0) {
        if (dist < tr) {
          tr = dist;
          trtype = type;
        }
      } else {
        if (dist < bl) {
          bl = dist;
          bltype = type;
        }
      }
    }
  }
  string ans = "NO";
  if (toptype == 'R' || toptype == 'Q') {
    ans = "YES";
  }
  if (righttype == 'R' || righttype == 'Q') {
    ans = "YES";
  }
  if (lefttype == 'R' || lefttype == 'Q') {
    ans = "YES";
  }
  if (bottomtype == 'R' || bottomtype == 'Q') {
    ans = "YES";
  }
  if (trtype == 'B' || trtype == 'Q') {
    ans = "YES";
  }
  if (tltype == 'B' || tltype == 'Q') {
    ans = "YES";
  }
  if (brtype == 'B' || brtype == 'Q') {
    ans = "YES";
  }
  if (bltype == 'B' || bltype == 'Q') {
    ans = "YES";
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
