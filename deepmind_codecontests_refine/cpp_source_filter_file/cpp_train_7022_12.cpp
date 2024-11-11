#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int d[8][2] = {-1, 0, 1, 0, 0, -1, 0, 1, -1, -1, -1, 1, 1, -1, 1, 1};
int S[1005][1005], T[1005][1005];
int num1[1005], num2[1005];
bool sp;
vector<pair<int, int>> ans;
int X, Y;
bool bo[1005][1005];
void pp() {
  printf("%d\n", ans.size() - 1);
  for (auto p : ans) {
    if (sp) swap(p.first, p.second);
    printf("%d %d\n", p.first, p.second);
  }
  exit(0);
}
bool out(int x, int y) {
  if (x < 1 || x > n || y < 1 || y > m) return 1;
  return 0;
}
void move(int dir) {
  int x = X + d[dir][0], y = Y + d[dir][1];
  swap(S[x][y], S[X][Y]);
  X = x;
  Y = y;
}
void walk(int tx, int ty) {
  int tmpx = -1, tmpy = -1;
  while (1) {
    if (X == tx && Y == ty) break;
    int x, y, mi = (1000000005), D;
    for (int(i) = 0; (i) < (int)(8); (i)++) {
      x = X + d[i][0];
      y = Y + d[i][1];
      if (out(x, y) || bo[x][y] || (x == tmpx && y == tmpy)) continue;
      if (abs(x - tx) + abs(y - ty) < mi) {
        mi = abs(x - tx) + abs(y - ty);
        D = i;
      }
    }
    tmpx = X;
    tmpy = Y;
    move(D);
    ans.push_back({X, Y});
  }
}
void cal1() {
  if (m == 1) {
    sp = 1;
    for (int(i) = 1; (i) <= (int)(n); (i)++) {
      S[1][i] = S[i][1];
      T[1][i] = T[i][1];
    }
    swap(n, m);
  }
  for (int(i) = 1; (i) <= (int)(m); (i)++)
    for (int(j) = 1; (j) <= (int)(m); (j)++)
      if (i != j) {
        X = 1;
        Y = i;
        ans.clear();
        ans.push_back({X, Y});
        walk(1, j);
        bool f = 1;
        for (int(k) = 1; (k) <= (int)(m); (k)++)
          if (S[1][k] != T[i][k]) {
            f = 0;
            break;
          }
        if (f) pp();
        walk(1, i);
      }
  puts("-1");
}
pair<int, int> find(int x) {
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(m); (j)++)
      if (S[i][j] == x) return {i, j};
  return {0, 0};
}
void Push(int &x, int &y, int dir) {
  int xx = x + d[dir][0], yy = y + d[dir][1];
  walk(xx, yy);
  move(dir ^ 1);
  ans.push_back({x, y});
  swap(bo[x][y], bo[xx][yy]);
  x = xx;
  y = yy;
}
void cal() {
  auto st = find(T[n][m]);
  X = st.first;
  Y = st.second;
  ans.push_back({X, Y});
  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= m; j++) {
      auto tmp = find(T[i][j]);
      int x = tmp.first, y = tmp.second;
      bo[x][y] = 1;
      while (y < j) Push(x, y, 3);
      while (y > j) Push(x, y, 2);
      while (x > i) Push(x, y, 0);
    }
  }
  for (int j = 1; j <= m - 2; j++) {
    for (int i = n - 1; i <= n; i++) {
      auto tmp = find(T[i][j]);
      int x = tmp.first, y = tmp.second;
      bo[x][y] = 1;
      while (x < i) Push(x, y, 1);
      while (y > j) Push(x, y, 2);
      while (x > i) Push(x, y, 0);
    }
  }
  while (1) {
    bool f = 1;
    for (int i = n - 1; i <= n; i++)
      for (int j = m - 1; j <= m; j++) {
        if (S[i][j] != T[i][j]) {
          f = 0;
          break;
        }
      }
    if (f) break;
    int dir = rand() % 8;
    int x = X + d[dir][0], y = Y + d[dir][1];
    if ((x == n - 1 || x == n) && (y == m - 1 || y == m)) {
      move(dir);
      ans.push_back({X, Y});
    }
  }
  pp();
}
int main() {
  scanf("%d%d", &n, &m);
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(m); (j)++) {
      scanf("%d", &S[i][j]);
      num1[S[i][j]]++;
    }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(m); (j)++) {
      scanf("%d", &T[i][j]);
      num2[T[i][j]]++;
    }
  for (int(i) = 1; (i) <= (int)(1005 - 1); (i)++) {
    num1[i] += num1[i - 1];
    num2[i] += num2[i - 1];
  }
  for (int(i) = 1; (i) <= (int)(n); (i)++)
    for (int(j) = 1; (j) <= (int)(m); (j)++) {
      S[i][j] = num1[S[i][j]]--;
      T[i][j] = num2[T[i][j]]--;
    }
  for (int(i) = 1; (i) <= (int)(1005 - 1); (i)++)
    if (num1[i] != num2[i]) {
      puts("-1");
      return 0;
    }
  if (m == 1 || n == 1)
    cal1();
  else
    cal();
  return 0;
}
