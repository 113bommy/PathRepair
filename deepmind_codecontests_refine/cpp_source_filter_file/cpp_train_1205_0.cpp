#include <bits/stdc++.h>
using namespace std;
char m1[50][50];
char m2[50][50];
vector<pair<int, int> > ans1, ans2;
void solve1(int x, int y, bool b) {
  if (b == 0) {
    if (m1[x][y] == 'U') {
      return;
    }
    if (m1[x][y] == m1[x + 1][y]) {
      ans1.push_back({x, y});
      m1[x][y] = 'U';
      m1[x + 1][y] = 'D';
      m1[x][y + 1] = 'U';
      m1[x + 1][y + 1] = 'D';
    } else {
      solve1(x + 1, y, 1);
      ans1.push_back({x, y});
      m1[x][y] = 'U';
      m1[x + 1][y] = 'D';
      m1[x][y + 1] = 'U';
      m1[x + 1][y + 1] = 'D';
    }
  } else {
    if (m1[x][y] == 'L') {
      return;
    }
    if (m1[x][y] == m1[x][y + 1]) {
      ans1.push_back({x, y});
      m1[x][y] = 'L';
      m1[x + 1][y] = 'L';
      m1[x][y + 1] = 'R';
      m1[x + 1][y + 1] = 'R';
    } else {
      solve1(x, y + 1, 0);
      ans1.push_back({x, y});
      m1[x][y] = 'L';
      m1[x + 1][y] = 'L';
      m1[x][y + 1] = 'R';
      m1[x + 1][y + 1] = 'R';
    }
  }
}
void solve2(int x, int y, bool b) {
  if (b == 0) {
    if (m2[x][y] == 'U') {
      return;
    }
    if (m2[x][y] == m2[x + 1][y]) {
      ans2.push_back({x, y});
      m2[x][y] = 'U';
      m2[x + 1][y] = 'D';
      m2[x][y + 1] = 'U';
      m2[x + 1][y + 1] = 'D';
    } else {
      solve2(x + 1, y, 1);
      ans2.push_back({x, y});
      m2[x][y] = 'U';
      m2[x + 1][y] = 'D';
      m2[x][y + 1] = 'U';
      m2[x + 1][y + 1] = 'D';
    }
  } else {
    if (m2[x][y] == 'L') {
      return;
    }
    if (m2[x][y] == m1[x][y + 1]) {
      ans1.push_back({x, y});
      m2[x][y] = 'L';
      m2[x + 1][y] = 'L';
      m2[x][y + 1] = 'R';
      m2[x + 1][y + 1] = 'R';
    } else {
      solve2(x, y + 1, 0);
      ans2.push_back({x, y});
      m2[x][y] = 'L';
      m2[x + 1][y] = 'L';
      m2[x][y + 1] = 'R';
      m2[x + 1][y + 1] = 'R';
    }
  }
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> m1[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> m2[i][j];
    }
  }
  if (n % 2 == 0) {
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        solve1(i, j, 0);
      }
    }
    for (int i = 0; i < n; i += 2) {
      for (int j = 0; j < m; j++) {
        solve2(i, j, 0);
      }
    }
  } else {
    for (int j = 0; j < m; j += 2) {
      for (int i = 0; i < n; i++) {
        solve1(i, j, 1);
      }
    }
    for (int j = 0; j < m; j += 2) {
      for (int i = 0; i < n; i++) {
        solve2(i, j, 1);
      }
    }
  }
  reverse(ans2.begin(), ans2.end());
  cout << ans1.size() + ans2.size() << "\n";
  for (auto z : ans1) {
    cout << z.first + 1 << " " << z.second + 1 << "\n";
  }
  for (auto z : ans2) {
    cout << z.first + 1 << " " << z.second + 1 << "\n";
  }
  return 0;
}
