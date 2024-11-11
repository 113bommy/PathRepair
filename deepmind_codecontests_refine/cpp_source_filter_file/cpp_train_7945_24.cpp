#include <bits/stdc++.h>
using namespace std;
const int maxint = -1u >> 1;
template <class T>
bool get_max(T& a, const T& b) {
  return b > a ? a = b, 1 : 0;
}
template <class T>
bool get_min(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}
int n;
int x[205], y[205], f[205][4];
int ans = 0;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < 205; i++)
    for (int j = 0; j < 4; j++) f[i][j] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (x[j] > x[i] && y[j] == y[i]) {
        f[i][0] = 1;
      }
      if (x[j] < x[i] && y[j] == y[i]) {
        f[i][1] = 1;
      }
      if (x[j] == x[i] && y[j] < y[i]) {
        f[i][2] = 1;
      }
      if (x[j] == x[i] && y[j] > y[i]) {
        f[i][3] = 1;
      }
    }
    int b = 1;
    for (int k = 0; k < 3; k++)
      if (f[i][k] == 0) b = 0;
    ;
    if (b) ans++;
  }
  cout << ans << endl;
  return 0;
}
