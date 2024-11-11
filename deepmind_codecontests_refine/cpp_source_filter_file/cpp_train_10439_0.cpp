#include <bits/stdc++.h>
using namespace std;
template <class T>
bool uin(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
bool uax(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
const int N = 200010;
long long a[N], f[N][3][2];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);
  cout << fixed;
  int n;
  cin >> n;
  for (int i = 1; i <= (int)(n); ++i) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << a[1] << '\n';
    return 0;
  }
  memset(f, -0x3f, sizeof(f));
  f[0][0][1] = 0;
  for (int i = 1; i <= (int)(n); ++i) {
    for (int j = 0; j < (int)(3); ++j) {
      if (!(i & 1)) {
        f[i][(j + 1) % 3][1] = max(f[i][(j + 1) % 3][1], f[i - 1][j][1] - a[i]);
        f[i][(j + 1) % 3][0] = max(f[i][(j + 1) % 3][0], f[i - 1][j][0] - a[i]);
      } else {
        f[i][(j + 1) % 3][0] =
            max(f[i][(j + 1) % 3][0],
                max(f[i - 1][j][0] - a[i], f[i - 1][j][1] - a[i]));
      }
      if (i & 1) {
        f[i][j][1] = max(f[i][j][1], f[i - 1][j][1] + a[i]);
        f[i][j][0] = max(f[i][j][0], f[i - 1][j][0] + a[i]);
      } else {
        f[i][j][0] =
            max(f[i][j][0], max(f[i - 1][j][0] - a[i], f[i - 1][j][1] + a[i]));
      }
    }
  }
  cout << f[n][((1 - (n % 3)) + 3) % 3][0] << '\n';
  return 0;
}
