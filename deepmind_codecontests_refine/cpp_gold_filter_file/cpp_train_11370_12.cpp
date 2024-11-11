#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
const int MOD = 1000000007;
const long long INF = 1e18;
const int MX = 61;
const long double PI = 4 * atan((long double)1);
template <class T>
void ckmin(T &a, T b) {
  a = min(a, b);
}
template <class T>
void ckmax(T &a, T b) {
  a = max(a, b);
}
char grid[MX][MX];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int r, c;
    cin >> r >> c;
    bool contains = false;
    bool hasP = false;
    for (int i = 0; i < (r); i++) {
      for (int j = 0; j < (c); j++) {
        cin >> grid[i][j];
        if (grid[i][j] == 'A') contains = true;
        if (grid[i][j] == 'P') hasP = true;
      }
    }
    int ans = 4;
    if (!hasP) ans = min(ans, 0);
    if (grid[0][c - 1] == 'A' || grid[r - 1][0] == 'A' || grid[0][0] == 'A' ||
        grid[r - 1][c - 1] == 'A') {
      ans = min(ans, 2);
    }
    for (int i = 0; i < (r); i++) {
      bool works = true;
      bool hasOne = false;
      for (int j = 0; j < (c); j++) {
        if (grid[i][j] == 'P') {
          works = false;
        }
        if (grid[i][j] == 'A') {
          hasOne = true;
        }
      }
      if (works) {
        if (i == 0 || i == r - 1) {
          ans = min(ans, 1);
        } else {
          ans = min(ans, 2);
        }
      }
      if (hasOne) {
        if (i == 0 || i == r - 1) {
          ans = min(ans, 3);
        }
      }
    }
    for (int i = 0; i < (c); i++) {
      bool works = true;
      bool hasOne = false;
      for (int j = 0; j < (r); j++) {
        if (grid[j][i] == 'P') {
          works = false;
        }
        if (grid[j][i] == 'A') {
          hasOne = true;
        }
      }
      if (works) {
        if (i == 0 || i == c - 1) {
          ans = min(ans, 1);
        } else {
          ans = min(ans, 2);
        }
      }
      if (hasOne) {
        if (i == 0 || i == c - 1) {
          ans = min(ans, 3);
        }
      }
    }
    cout << (contains ? to_string(ans) : "MORTAL") << "\n";
  }
}
