#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
const int mod = 1e9 + 7;
int n, m, i, j, a, b, c, d, f[2][55][105], e[55][55];
vector<int> g[55][55];
vector<int> trs[2][2][55][55];
void init() {
  int i, j, k;
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) {
      if (e[i][j] && !g[i][j].empty() && g[i][j].back() == i) {
        int cnt = 1, lst = i;
        queue<int> qx;
        for (k = ((int)g[i][j].size()) - 2; k >= 0; k--) {
          qx.push(g[i][j][k]);
        }
        while (!qx.empty()) {
          int x = qx.front();
          qx.pop();
          cnt++;
          if (!e[x][lst] || cnt > n + n) {
            cnt = -1;
            break;
          }
          for (k = ((int)g[x][lst].size()) - 1; k >= 0; k--) {
            qx.push(g[x][lst][k]);
          }
          lst = x;
        }
        if (cnt != -1) trs[0][0][lst][j].push_back(cnt);
      }
    }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) {
      if (e[i][j] && !g[i][j].empty() && g[i][j][0] == j) {
        int cnt = 1, lst = j;
        queue<int> qx;
        for (k = 1; k < g[i][j].size(); k++) {
          qx.push(g[i][j][k]);
        }
        while (!qx.empty()) {
          int x = qx.front();
          qx.pop();
          cnt++;
          if (!e[lst][x] || cnt > n + n) {
            cnt = -1;
            break;
          }
          for (((k)) = (0); ((k)) <= (((int)(g[lst][x].size())) - 1); ((k))++) {
            qx.push(g[lst][x][k]);
          }
          lst = x;
        }
        if (cnt != -1) trs[1][1][i][lst].push_back(cnt);
      }
    }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) {
      if (e[i][j] && !g[i][j].empty()) {
        trs[1][0][i][j].push_back(1);
      }
    }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++)
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) {
      if (e[i][j]) {
        int p;
        for (p = 0; p + 1 < g[i][j].size(); p++) {
          if (g[i][j][p] == i && g[i][j][p + 1] == j) break;
        }
        if (p + 1 >= g[i][j].size()) continue;
        int cnt = 2, lst = i;
        queue<int> qx;
        for (k = p - 1; k >= 0; k--) {
          qx.push(g[i][j][k]);
        }
        while (!qx.empty()) {
          int x = qx.front();
          qx.pop();
          cnt++;
          if (!e[x][lst] || cnt > n + n) {
            cnt = -1;
            break;
          }
          for (k = ((int)g[x][lst].size()) - 1; k >= 0; k--) {
            qx.push(g[x][lst][k]);
          }
          lst = x;
        }
        if (cnt == -1) continue;
        int mem = lst;
        lst = j;
        for (k = p + 2; k < g[i][j].size(); k++) {
          qx.push(g[i][j][k]);
        }
        while (!qx.empty()) {
          int x = qx.front();
          qx.pop();
          cnt++;
          if (!e[lst][x] || cnt > n + n) {
            cnt = -1;
            break;
          }
          for (((k)) = (0); ((k)) <= (((int)(g[lst][x].size())) - 1); ((k))++) {
            qx.push(g[lst][x][k]);
          }
          lst = x;
        }
        if (cnt != -1) trs[0][1][mem][lst].push_back(cnt);
      }
    }
}
int main() {
  read(n);
  read(m);
  for (((i)) = (1); ((i)) <= ((m)); ((i))++) {
    int x, y, z;
    read(x);
    read(y);
    read(z);
    e[x][y] = 1;
    while (z--) {
      int t;
      read(t);
      g[x][y].push_back(t);
    }
  }
  init();
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) f[0][i][0] = 1;
  for (((i)) = (0); ((i)) <= (((int)(n + n)) - 1); ((i))++) {
    for (((a)) = (0); ((a)) <= (((int)(2)) - 1); ((a))++)
      for (((b)) = (1); ((b)) <= ((n)); ((b))++)
        if (f[a][b][i]) {
          for (((c)) = (0); ((c)) <= (((int)(2)) - 1); ((c))++)
            for (((d)) = (1); ((d)) <= ((n)); ((d))++)
              for (__typeof((trs[a][c][b][d]).begin()) it =
                       (trs[a][c][b][d]).begin();
                   it != (trs[a][c][b][d]).end(); it++) {
                if (i + *it <= n + n)
                  f[c][d][i + *it] = (f[c][d][i + *it] + f[a][b][i]) % mod;
              }
        }
  }
  for (((i)) = (1); ((i)) <= ((n + n)); ((i))++) {
    int sum = 0;
    for (((j)) = (1); ((j)) <= ((n)); ((j))++) (sum += f[1][j][i]) %= mod;
    cout << sum << endl;
  }
  return 0;
}
