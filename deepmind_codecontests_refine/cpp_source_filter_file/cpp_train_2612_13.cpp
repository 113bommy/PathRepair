#include <bits/stdc++.h>
using namespace std;
int fff[1000000 + 444];
int cnt[1000000 + 444];
int cnt2[1000000 + 444];
int **matrix;
bool **vis;
bool checked[1000000 + 444];
int xmove[] = {0, -1, 0, 1};
int ymove[] = {-1, 0, 1, 0};
int main() {
  ios::sync_with_stdio(false);
  int b = -1, a = INT_MIN, x = INT_MIN, y;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> fff[i];
    cnt[fff[i]]++;
    b = max(b, fff[i]);
  }
  bool possible = true;
  if (cnt[0] != 1) {
    possible = false;
  }
  if (t == 1 && fff[0] == 0) {
    cout << "1  1\n1 1";
    return 0;
  }
  for (int i = 1; i <= b; i++) {
    if (cnt[i] < 4 * i) {
      x = i;
      break;
    } else if (cnt[i] > 4 * i) {
      possible = false;
      break;
    }
  }
  if (x == INT_MIN) {
    possible = false;
  }
  int n, m;
  for (n = 1; n * n <= t; n++) {
    if (t % n == 0) {
      m = t / n;
      a = n + m - b - 2;
      y = a - x + 2;
      int dist_to_corner =
          max(max(max(x - 1 + y - 1, (x - 1) + (m - y)), n - x + y - 1),
              n - x + m - y);
      if (x > 0 && y > 0 && n > 0 && m > 0 && a >= 0 && b >= 0 && x <= n &&
          y <= m) {
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            cnt2[abs(i - x) + abs(j - y)]++;
          }
        }
        bool avoid = false;
        for (int i = 0; i <= b; i++) {
          if (cnt[i] != cnt2[i]) {
            avoid = true;
            break;
          }
          cnt2[i] = 0;
        }
        cnt2[0] = 0;
        for (int i = 1; i <= b; i++) {
          cnt2[i] = 0;
        }
        if (!avoid) {
          cout << "\n" << n << " " << m << "\n" << x << " " << y << "\n";
          return 0;
        }
      }
    }
  }
  cout << -1;
  return 0;
}
