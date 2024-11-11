#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)(1e5) + 123;
const long long inf = (long long)(1e18);
const int INF = (int)(1e9);
int x[5][5], y[5][5];
void can(int x1, int gwergerg, int x2, int y2, int x3, int y3) {
  if (x1 == x2 && x2 == x3 && gwergerg + y2 + y3 == x1) {
    swap(x1, gwergerg);
    swap(x2, y2);
    swap(x3, y3);
    cout << gwergerg << endl;
    for (int i = 1; i <= x1; ++i)
      for (int j = 1; j <= gwergerg; ++j)
        cout << 'A' << (j == gwergerg ? "\n" : "");
    for (int i = 1; i <= x2; ++i)
      for (int j = 1; j <= y2; ++j) cout << 'B' << (j == y2 ? "\n" : "");
    for (int i = 1; i <= x3; ++i)
      for (int j = 1; j <= y3; ++j) cout << 'C' << (j == y3 ? "\n" : "");
    exit(0);
  }
  int id;
  if (max(x1, max(x2, x3)) == x1 && x2 + x3 == x1 && y2 == y3 &&
      y2 + gwergerg == x1) {
    cout << x1 << endl;
    for (int i = 1; i <= gwergerg; ++i)
      for (int j = 1; j <= x1; ++j) cout << 'A' << (j == x1 ? "\n" : "");
    for (int i = 1; i <= y2; ++i)
      for (int j = 1; j <= x1; ++j)
        cout << (j <= x2 ? 'B' : 'C') << (j == x1 ? "\n" : "");
    exit(0);
  }
  if (max(x1, max(x2, x3)) == x2 && x1 + x3 == x2 && gwergerg == y3 &&
      y2 + gwergerg == x2) {
    cout << x2 << endl;
    for (int i = 1; i <= y2; ++i)
      for (int j = 1; j <= x2; ++j) cout << 'B' << (j == x2 ? "\n" : "");
    for (int i = 1; i <= gwergerg; ++i)
      for (int j = 1; j <= x2; ++j) {
        cout << (j <= x1 ? 'A' : 'C') << (j == x2 ? "\n" : "");
      }
    exit(0);
  }
  if (max(x1, max(x2, x3)) == x3 && x2 + x1 == x3 && y2 == gwergerg &&
      y3 + gwergerg == x3) {
    cout << x3 << endl;
    for (int i = 1; i <= y3; ++i)
      for (int j = 1; j <= x3; ++j) cout << 'C' << (j == x3 ? "\n" : "");
    for (int i = 1; i <= gwergerg; ++i)
      for (int j = 1; j <= x3; ++j)
        cout << (j <= x2 ? 'B' : 'A') << (j == x3 ? "\n" : "");
    exit(0);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  for (int i = 1; i <= 3; ++i) {
    cin >> x[i][0] >> y[i][0];
    x[i][1] = y[i][0];
    y[i][1] = x[i][0];
  }
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
        can(x[1][i], y[1][i], x[2][j], y[2][j], x[3][k], y[3][k]);
      }
    }
  }
  cout << "-1";
  return 0;
}
