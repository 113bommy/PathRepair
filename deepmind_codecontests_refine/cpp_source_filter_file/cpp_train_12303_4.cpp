#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 987654321;
const int MOD = 1e9 + 7;
const int WHITE = 0;
const int BLACK = 1;
int dr[] = {2, -2, 0, 0, 1};
int dc[] = {0, 0, 2, -2, 1};
int matrix[100][100], copy1[100][100], copy2[100][100];
int n;
bool check(int r, int c) { return (1 <= r && r <= n && 1 <= c && c <= n); }
int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  memset(matrix, -1, sizeof(matrix));
  memset(copy1, -1, sizeof(copy1));
  memset(copy2, -1, sizeof(copy2));
  cin >> n;
  matrix[1][1] = 1;
  matrix[n][n] = 0;
  using tt = tuple<int, int, int>;
  queue<tt> q;
  q.push({1, 1, 1});
  while (!q.empty()) {
    auto [color, r, c] = q.front();
    q.pop();
    for (int i = 0; i < 5; i++) {
      int R = r + dr[i], C = c + dc[i];
      if (check(R, C) && matrix[R][C] == -1) {
        int x;
        cout << "? " << min(r, R) << " " << min(c, C) << " " << max(r, R) << " "
             << max(c, C) << endl;
        cin >> x;
        if (x == 1) {
          matrix[R][C] = color;
          q.push({color, R, C});
        } else {
          matrix[R][C] = !color;
          q.push({!color, R, C});
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      copy1[i][j] = matrix[i][j];
      copy2[i][j] = matrix[i][j];
    }
  }
  int x;
  cout << "? 1 2 2 3" << endl;
  cin >> x;
  if (x == 1) {
    copy1[1][2] = copy1[2][3] = 1;
    copy2[1][2] = copy2[2][3] = 0;
  } else {
    copy1[1][2] = 1, copy1[2][3] = 0;
    copy2[1][2] = 0, copy2[2][3] = 1;
  }
  q.push({copy2[1][2], 1, 2});
  q.push({copy2[2][3], 2, 3});
  while (!q.empty()) {
    auto [color, r, c] = q.front();
    q.pop();
    for (int i = 0; i < 5; i++) {
      int R = r + dr[i], C = c + dc[i];
      if (check(min(r, R), min(c, C)) && check(max(r, R), max(c, C)) &&
          copy2[R][C] == -1) {
        int x;
        cout << "? " << min(r, R) << " " << min(c, C) << " " << max(r, R) << " "
             << max(c, C) << endl;
        cin >> x;
        if (x == 1) {
          copy2[R][C] = color;
          copy1[R][C] = !color;
          q.push({color, R, C});
        } else {
          copy2[R][C] = !color;
          copy1[R][C] = color;
          q.push({!color, R, C});
        }
      }
    }
  }
  bool c1, c2;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      c1 = (copy1[i][j] == copy1[i][j + 1] && copy1[i][j] == copy1[i][j + 2] &&
            copy1[i][j] == copy1[i + 1][j + 2]);
      c2 = (copy1[i][j] == copy1[i + 1][j] &&
            copy1[i][j] == copy1[i + 1][j + 1] &&
            copy1[i][j] == copy1[i + 1][j + 2]);
      if (c1 || c2) {
        int x;
        cout << "? " << i << " " << j << " " << i + 1 << " " << j + 2 << endl;
        cin >> x;
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            cout << (x == 1 ? copy1 : copy2)[i][j];
          }
          cout << endl;
        }
        return 0;
      }
      c1 = (copy1[i][j] == copy1[i][j + 1] &&
            copy1[i][j] == copy1[i + 1][j + 1] &&
            copy1[i][j] == copy1[i + 2][j + 1]);
      c2 = (copy1[i][j] == copy1[i + 1][j] && copy1[i][j] == copy1[i + 2][j] &&
            copy1[i][j] == copy1[i + 2][j + 1]);
      if (c1 || c2) {
        int x;
        cout << "? " << i << " " << j << " " << i + 2 << " " << j + 1 << endl;
        cin >> x;
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            cout << (x == 1 ? copy1 : copy2)[i][j];
          }
          cout << endl;
        }
        return 0;
      }
      c1 = (copy2[i][j] == copy2[i][j + 1] && copy2[i][j] == copy2[i][j + 2] &&
            copy2[i][j] == copy2[i + 1][j + 2]);
      c2 = (copy2[i][j] == copy2[i + 1][j] &&
            copy2[i][j] == copy2[i + 1][j + 1] &&
            copy2[i][j] == copy2[i + 1][j + 2]);
      if (c1 || c2) {
        int x;
        cout << "? " << i << " " << j << " " << i + 1 << " " << j + 2 << endl;
        cin >> x;
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            cout << (x == 1 ? copy2 : copy1)[i][j];
          }
          cout << endl;
        }
        return 0;
      }
      c1 = (copy2[i][j] == copy2[i][j + 1] &&
            copy2[i][j] == copy2[i + 1][j + 1] &&
            copy2[i][j] == copy2[i + 2][j + 1]);
      c2 = (copy2[i][j] == copy2[i + 1][j] && copy2[i][j] == copy2[i + 2][j] &&
            copy2[i][j] == copy2[i + 2][j + 1]);
      if (c1 || c2) {
        int x;
        cout << "? " << i << " " << j << " " << i + 2 << " " << j + 1 << endl;
        cin >> x;
        cout << "!" << endl;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
            cout << (x == 1 ? copy2 : copy1)[i][j];
          }
          cout << endl;
        }
        return 0;
      }
    }
  }
  cout << "!" << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << copy1[i][j];
    }
    cout << endl;
  }
}
