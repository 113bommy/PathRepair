#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
bool ask(int x1, int y1, int x2, int y2) {
  cout << "? " << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1
       << endl;
  int ans;
  cin >> ans;
  if (ans == -1) {
    exit(0);
  }
  return ans;
}
bool ans[55][55];
bool simVer(bool flip, int x, int y) {
  if (ans[x][y] != (flip ^ ans[x + 2][y + 1])) return false;
  if (ans[x + 1][y] == (flip ^ ans[x + 2][y])) return true;
  if (ans[x + 1][y + 1] == (flip ^ ans[x][y + 1])) return true;
  if (ans[x + 1][y] == (flip ^ ans[x + 1][y + 1])) return true;
  return false;
}
bool simHor(bool flip, int x, int y) {
  if (ans[x][y] != (flip ^ ans[x + 1][y + 2])) return false;
  if (ans[x][y + 1] == (flip ^ ans[x][y + 2])) return true;
  if (ans[x + 1][y + 1] == (flip ^ ans[x + 1][y])) return true;
  if (ans[x][y + 1] == (flip ^ (ans[x + 1][y + 1]))) return true;
  return false;
}
int n;
void fl() {
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (((i + j) % 2) == 1) ans[i][j] ^= true;
    }
}
void done() {
  cout << "!\n";
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) cout << ans[i][j];
    cout << endl;
  }
  exit(0);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  ans[0][0] = true;
  ans[0][1] = true;
  for (int i = 0; i < n / 2; i++) {
    bool res = ask(2 * i, 0, 2 * i + 2, 0);
    ans[2 * i + 2][0] = ans[2 * i][0] ^ (!res);
  }
  for (int i = 0; i < (n + 1) / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      bool res = ask(2 * i, 2 * j, 2 * i, 2 * j + 2);
      ans[2 * i][2 * j + 2] = ans[2 * i][2 * j] ^ (!res);
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      bool res = ask(2 * i, 2 * j, 2 * i + 1, 2 * j + 1);
      ans[2 * i + 1][2 * j + 1] = ans[2 * i][2 * j] ^ (!res);
    }
  }
  for (int i = 0; i < n / 2; i++) {
    bool res = ask(2 * i, 1, 2 * i + 2, 1);
    ans[2 * i + 2][1] = ans[2 * i][1] ^ (!res);
  }
  for (int i = 0; i < (n + 1) / 2; i++) {
    for (int j = 0; j < n / 2 - 1; j++) {
      bool res = ask(2 * i, 2 * j + 1, 2 * i, 2 * j + 3);
      ans[2 * i][2 * j + 3] = ans[2 * i][2 * j + 1] ^ (!res);
    }
  }
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n / 2; j++) {
      bool res = ask(2 * i, 2 * j + 1, 2 * i + 1, 2 * j + 2);
      ans[2 * i + 1][2 * j + 2] = ans[2 * i][2 * j + 1] ^ (!res);
    }
  }
  for (int i = 0; i < n / 2; i++) {
    bool res = ask(2 * i + 1, 0, 2 * i + 1, 2);
    ans[2 * i + 1][0] = ans[2 * i + 1][2] ^ (!res);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      if (i + 2 < n && j + 1 < n) {
        bool no = simVer(false, i, j);
        bool yes = simVer(true, i, j);
        if (no != yes) {
          bool ans = ask(i, j, i + 2, j + 1);
          if (ans == yes) fl();
          done();
        }
      }
      if (i + 1 < n && j + 2 < n) {
        bool no = simHor(false, i, j);
        bool yes = simHor(true, i, j);
        if (no != yes) {
          bool ans = ask(i, j, i + 1, j + 2);
          if (ans == yes) fl();
          done();
        }
      }
    }
  return 37;
}
