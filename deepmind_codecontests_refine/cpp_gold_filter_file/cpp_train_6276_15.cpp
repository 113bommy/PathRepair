#include <bits/stdc++.h>
using namespace std;
int xa, xb, ya, yb, n;
int arr[1000][3];
double d(int x1, int x2, int y1, int y2);
void test(int a, int b, int lim, int olim, int& sol);
int solve() {
  cin >> xa >> ya >> xb >> yb;
  int t1 = xa;
  int t2 = xb;
  xa = min(t1, t2);
  xb = max(t1, t2);
  t1 = ya;
  t2 = yb;
  ya = min(t1, t2);
  yb = max(t1, t2);
  cin >> n;
  int sol = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }
  test(xa, ya, xb, ya, sol);
  test(xa, yb, xb, yb, sol);
  test(xa, ya + 1, xa, yb - 1, sol);
  test(xb, ya + 1, xb, yb - 1, sol);
  return sol;
}
void test(int a, int b, int lim, int olim, int& sol) {
  for (int i = a; i <= lim; i++) {
    for (int k = b; k <= olim; k++) {
      bool blanket = true;
      for (int j = 0; j < n; j++) {
        if (d(i, arr[j][0], k, arr[j][1]) <= arr[j][2]) {
          blanket = false;
          break;
        }
      }
      if (blanket) {
        sol++;
      }
    }
  }
}
double d(int x1, int x2, int y1, int y2) {
  return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << solve() << endl;
}
