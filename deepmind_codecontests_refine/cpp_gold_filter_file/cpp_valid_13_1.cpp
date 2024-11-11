#include <bits/stdc++.h>
using namespace std;
int idx[] = {-1, 1, 0, 0}, idy[] = {0, 0, -1, 1};
void print(int n, int m, int k) {
  cout << "YES"
       << "\n";
  vector<vector<int>> g(n, vector<int>(m, -1));
  auto isvalid = [&](int i, int j) -> bool {
    if (i >= 0 && j >= 0 && i < n && j < m) {
      return true;
    }
    return false;
  };
  auto findMatch = [&](int i, int j, int ni, int nj) -> int {
    for (int num = 0; num < 26; num++) {
      bool flag = false;
      for (int dir = 0; dir < 4; dir++) {
        int nx = i + idx[dir], ny = j + idy[dir];
        int nxx = ni + idx[dir], nyy = nj + idy[dir];
        if (isvalid(nx, ny) && g[nx][ny] == num) flag = true;
        if (isvalid(nxx, nyy) && g[nxx][nyy] == num) flag = true;
      }
      if (flag) continue;
      return num;
    }
    assert(false);
    return -1;
  };
  if (n % 2) {
    for (int i = 0; i < m; i += 2) {
      int c = findMatch(n - 1, i, n - 1, i + 1);
      g[n - 1][i] = g[n - 1][i + 1] = c;
      k--;
    }
  } else if (m % 2) {
    for (int i = 0; i < n; i += 2) {
      int c = findMatch(i, m - 1, i + 1, m - 1);
      g[i][m - 1] = g[i + 1][m - 1] = c;
    }
  }
  int v = 0, h = n - (1 + (n % 2));
  while (k--) {
    if (h < 0) h = n - (1 + (n % 2)), v += 2;
    auto c = findMatch(h, v, h, v + 1);
    g[h][v] = g[h][v + 1] = c;
    h--;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (g[i][j] != -1) continue;
      auto c = findMatch(i, j, i + 1, j);
      g[i][j] = g[i + 1][j] = c;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      assert(g[i][j] != -1);
      cout << char(g[i][j] + 'a');
    }
    cout << "\n";
  }
}
void runCase(int tc) {
  int n, m, k;
  cin >> n >> m >> k;
  int hor = k, ver = (n * m / 2) - k;
  if (n % 2 != 0) {
    int need = m / 2;
    if (hor < need) {
      cout << "NO"
           << "\n";
      return;
    }
    hor -= need;
    if (hor % 2 != 0) {
      cout << "NO"
           << "\n";
    } else {
      print(n, m, k);
    }
  } else if (m % 2 != 0) {
    int need = n / 2;
    if (ver < need) {
      cout << "NO"
           << "\n";
      return;
    }
    ver -= need;
    if (ver % 2 != 0) {
      cout << "NO"
           << "\n";
    } else
      print(n, m, k);
  } else {
    if (k % 2 != 0) {
      cout << "NO"
           << "\n";
    } else
      print(n, m, k);
  }
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0);
  int t = 1;
  cin >> t;
  for (int tc = 1; tc <= t; tc++) runCase(tc);
  return 0;
}
