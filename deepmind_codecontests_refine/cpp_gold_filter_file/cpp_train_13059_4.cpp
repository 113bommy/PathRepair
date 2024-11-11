#include <bits/stdc++.h>
using namespace std;
int r, c;
string word[1005];
int vis[1005][1005];
int pin[1005][1005];
int my[8] = {-1, 0, 1, 2, 3, 0, 1, 2};
int mx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
bool in(int i, int j) { return (i >= 0 && i < r && j >= 0 && j < c); }
void pintar(int i, int j, int v) {
  int nro[4] = {0};
  if (v) {
    for (int k = 0; k < 8; ++k) {
      int ni = i + my[k];
      int nj = j + mx[k];
      if (in(ni, nj) && pin[ni][nj] != -1) nro[pin[ni][nj]]++;
    }
    int t = 0;
    for (int k = 0; k < 4; ++k)
      if (!nro[k]) {
        t = k;
        break;
      }
    pin[i][j] = t;
    pin[i + 1][j] = t;
    pin[i + 2][j] = t;
  } else {
    for (int k = 0; k < 8; ++k) {
      int ni = i + mx[k];
      int nj = j + my[k];
      if (in(ni, nj) && pin[ni][nj] != -1) nro[pin[ni][nj]]++;
    }
    int t = 0;
    for (int k = 0; k < 4; ++k)
      if (!nro[k]) {
        t = k;
        break;
      }
    pin[i][j] = t;
    pin[i][j + 1] = t;
    pin[i][j + 2] = t;
  }
}
int main() {
  cin >> r >> c;
  for (int i = 0; i < r; ++i) {
    cin >> word[i];
  }
  memset(vis, 0, sizeof(vis));
  memset(pin, -1, sizeof(pin));
  bool bo = true;
  int cnt = 1;
  for (int i = 0; i < r && bo; i++) {
    for (int j = 0; j < c && bo; j++)
      if (!vis[i][j]) {
        if (word[i][j] == 'w') {
          vis[i][j] = cnt;
          if (in(i, j + 1) && in(i, j + 2) && !vis[i][j + 1] &&
              !vis[i][j + 2] && word[i][j + 1] == 'b' &&
              word[i][j + 2] == 'w') {
            vis[i][j + 1] = cnt;
            vis[i][j + 2] = cnt++;
            pintar(i, j, 0);
          } else if (in(i + 1, j) && in(i + 2, j) && !vis[i + 1][j] &&
                     !vis[i + 2][j] && word[i + 1][j] == 'b' &&
                     word[i + 2][j] == 'w') {
            vis[i + 1][j] = cnt;
            vis[i + 2][j] = cnt++;
            pintar(i, j, 1);
          } else
            bo = false;
        } else if (word[i][j] == 'b' && !vis[i][j]) {
          bo = false;
        }
      }
  }
  if (!bo)
    cout << "NO\n";
  else {
    cout << "YES\n";
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j)
        if (word[i][j] == '.')
          cout << ".";
        else
          cout << char('a' + pin[i][j]);
      cout << endl;
    }
  }
  return 0;
}
