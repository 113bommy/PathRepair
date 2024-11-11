#include <bits/stdc++.h>
using namespace std;
bool us[100][100];
int cx, cy;
int f_dist(int x, int y) { return abs(x - cx) + abs(y - cy); }
int main() {
  int n, k;
  cin >> n >> k;
  cx = (k + 1) / 2;
  cy = (k + 1) / 2;
  while (n--) {
    int m;
    cin >> m;
    int x = -1, y = -1, max_dist = INT_MAX;
    for (int i = 1; i <= k; i++) {
      int dist = 0;
      int been = 0;
      for (int j = 1; j <= k; j++) {
        if (j > m) {
          dist -= f_dist(j - m, i);
          been -= us[i][j - m];
        }
        dist += f_dist(j, i);
        been += us[i][j];
        if (dist < max_dist && !been && j >= m) {
          max_dist = dist;
          x = j;
          y = i;
        }
      }
    }
    if (max_dist == INT_MAX) {
      cout << "-1\n";
      continue;
    }
    for (int i = x; i >= x - m + 1; i--) us[y][i] = true;
    cout << y << ' ' << x - m + 1 << ' ' << x << '\n';
  }
}
