#include <bits/stdc++.h>
using namespace std;
void Emsawy() {}
int dx[]{1, -1, 0, 0, 1, -1, 1, -1};
int dy[]{0, 0, 1, -1, 1, -1, -1, 1};
long long suf(long long x) { return (x * (x + 1)) / 2; }
vector<vector<pair<int, int> > > adj;
const long long mod = 1e9 + 7, oo = 1e9;
int n, m;
char g[6][6];
bool go() {
  bool ok = 0;
  for (int i = 0; i < 4; i++) {
    int x = 0, o = 0;
    for (int j = 0; j < 4; j++) {
      x += (g[i][j] == 'x');
      if (x == 3) {
        ok = 1;
        break;
      }
      if (g[i][j] != 'x') x = 0;
    }
  }
  for (int i = 0; i < 4; i++) {
    int x = 0, o = 0;
    for (int j = 0; j < 4; j++) {
      x += (g[i][3 - j] == 'x');
      if (x == 3) {
        ok = 1;
        break;
      }
      if (g[i][3 - j] != 'x') x = 0;
    }
  }
  for (int i = 0; i < 4; i++) {
    int x = 0, o = 0;
    for (int j = 0; j < 4; j++) {
      x += (g[j][i] == 'x');
      if (x == 3) {
        ok = 1;
        break;
      }
      if (g[j][i] != 'x') x = 0;
    }
  }
  for (int i = 0; i < 4; i++) {
    int x = 0, o = 0;
    for (int j = 0; j < 4; j++) {
      x += (g[3 - j][i] == 'x');
      if (x == 3) {
        ok = 1;
        break;
      }
      if (g[3 - j][i] != 'x') x = 0;
    }
  }
  int x = 0, o = 0;
  for (int i = 0; i < 4; i++) {
    x += (g[i][i] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[i][i] != 'x') x = 0;
  }
  x = 0, o = 0;
  for (int i = 0; i < 4; i++) {
    x += (g[3 - i][3 - i] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[3 - i][3 - i] != 'x') x = 0;
  }
  x = 0, o = 0;
  for (int i = 0; i < 4; i++) {
    x += (g[i][3 - i] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[i][3 - i] != 'x') x = 0;
  }
  x = 0, o = 0;
  for (int i = 0; i < 4; i++) {
    x += (g[3 - i][i] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[3 - i][i] != 'x') x = 0;
  }
  x = 0;
  int i2 = 1, j2 = 1;
  while (i2 < 4 && j2 < 4) {
    x += (g[i2][j2] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[i2][j2] != 'x') x = 0;
    i2++, j2++;
  }
  x = 0;
  i2 = 1, j2 = 0;
  while (i2 < 4 && j2 < 4) {
    x += (g[i2][j2] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[i2][j2] != 'x') x = 0;
    i2++, j2++;
  }
  x = 0;
  i2 = 0, j2 = 2;
  while (i2 < 4 && j2 >= 0) {
    x += (g[i2][j2] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[i2][j2] != 'x') x = 0;
    i2++, j2--;
  }
  x = 0;
  i2 = 1, j2 = 3;
  while (i2 < 4 && j2 >= 0) {
    x += (g[i2][j2] == 'x');
    if (x == 3) {
      ok = 1;
      break;
    }
    if (g[i2][j2] != 'x') x = 0;
    i2++, j2--;
  }
  return ok;
}
int main() {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cin >> g[i][j];
    }
  }
  bool ok = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (g[i][j] == '.') {
        g[i][j] = 'x';
        ok |= go();
        g[i][j] = '.';
      }
    }
  }
  if (ok)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
