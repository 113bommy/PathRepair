#include <bits/stdc++.h>
using namespace std;
int r, c, d1[1000005], d2[1000005];
char m[1005][1005];
bool v1[1005][1005], v2[1005][1005];
queue<int> q11;
queue<int> q12;
queue<int> q21;
queue<int> q22;
int f(int i, int j) { return (i - 1 * c) + j; }
int main() {
  int xx = -1, xy = -1;
  memset(v1, false, sizeof v1);
  memset(v2, false, sizeof v2);
  scanf("%d %d", &r, &c);
  for (int i = 1; i <= r * c; i++) d1[i] = d2[i] = 100000000;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      scanf(" %c", &m[i][j]);
      if (m[i][j] == 'S') {
        q11.push(i);
        q12.push(j);
        v1[i][j] = true;
        d1[f(i, j)] = 0;
      } else if (m[i][j] == 'E') {
        q21.push(i);
        q22.push(j);
        xx = i;
        xy = j;
        v2[i][j] = true;
        d2[f(i, j)] = 0;
      } else if (m[i][j] == 'T') {
        v1[i][j] = v2[i][j] = true;
      }
    }
  }
  while (!q11.empty()) {
    int x = q11.front();
    int y = q12.front();
    q11.pop();
    q12.pop();
    if (x - 1 >= 1 && !v1[x - 1][y]) {
      q11.push(x - 1);
      q12.push(y);
      v1[x - 1][y] = true;
      d1[f(x - 1, y)] = d1[f(x, y)] + 1;
    }
    if (x + 1 <= r && !v1[x + 1][y]) {
      q11.push(x + 1);
      q12.push(y);
      v1[x + 1][y] = true;
      d1[f(x + 1, y)] = d1[f(x, y)] + 1;
    }
    if (y - 1 >= 1 && !v1[x][y - 1]) {
      q11.push(x);
      q12.push(y - 1);
      v1[x][y - 1] = true;
      d1[f(x, y - 1)] = d1[f(x, y)] + 1;
    }
    if (y + 1 <= c && !v1[x][y + 1]) {
      q11.push(x);
      q12.push(y + 1);
      v1[x][y + 1] = true;
      d1[f(x, y + 1)] = d1[f(x, y)] + 1;
    }
  }
  while (!q21.empty()) {
    int x = q21.front();
    int y = q22.front();
    q21.pop();
    q22.pop();
    if (x - 1 >= 1 && !v2[x - 1][y]) {
      q21.push(x - 1);
      q22.push(y);
      v2[x - 1][y] = true;
      d2[f(x - 1, y)] = d2[f(x, y)] + 1;
    }
    if (x + 1 <= r && !v2[x + 1][y]) {
      q21.push(x + 1);
      q22.push(y);
      v2[x + 1][y] = true;
      d2[f(x + 1, y)] = d2[f(x, y)] + 1;
    }
    if (y - 1 >= 1 && !v2[x][y - 1]) {
      q21.push(x);
      q22.push(y - 1);
      v2[x][y - 1] = true;
      d2[f(x, y - 1)] = d2[f(x, y)] + 1;
    }
    if (y + 1 <= c && !v2[x][y + 1]) {
      q21.push(x);
      q22.push(y + 1);
      v2[x][y + 1] = true;
      d2[f(x, y + 1)] = d2[f(x, y)] + 1;
    }
  }
  int cmpp = d1[f(xx, xy)];
  int resp = 0;
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (m[i][j] >= '0' && m[i][j] <= '9' && d2[f(i, j)] <= cmpp) {
        resp += (m[i][j] - '0');
      }
    }
  }
  printf("%d\n", resp);
  return 0;
}
