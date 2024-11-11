#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
int tmp[33][33];
int source[33][33];
int target[33][33];
pair<int, int> prv[33][33];
bool block[33][33];
vector<pair<int, int> > R;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void save() {
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) tmp[i][j] = source[i][j];
}
void load() {
  R.clear();
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) source[i][j] = tmp[i][j];
}
void check() {
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j)
      if (source[i][j] != target[i][j]) return;
  printf("%d\n", (int)R.size() - 1);
  for (pair<int, int> r : R) printf("%d%d\n", r.first + 1, r.second + 1);
  exit(0);
}
void make(int first, int second) {
  swap(source[R.back().first][R.back().second], source[first][second]);
  R.push_back(pair<int, int>(first, second));
  a = first;
  b = second;
}
bool in(int first, int second) {
  return 0 <= first && first < n && 0 <= second && second < m &&
         !block[first][second];
}
void path(int first, int second) {
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) prv[i][j] = pair<int, int>(-1, -1);
  queue<pair<int, int> > Q;
  Q.push(pair<int, int>(a, b));
  pair<int, int> c = pair<int, int>(first, second);
  while (!Q.empty()) {
    first = Q.front().first;
    second = Q.front().second;
    Q.pop();
    for (int d = (0); d < (8); ++d) {
      int nx = first + dx[d];
      int ny = second + dy[d];
      if (in(nx, ny) && prv[nx][ny] == pair<int, int>(-1, -1)) {
        prv[nx][ny] = pair<int, int>(first, second);
        Q.push(pair<int, int>(nx, ny));
      }
    }
  }
  stack<pair<int, int> > S;
  while (c != pair<int, int>(a, b)) {
    S.push(c);
    c = prv[c.first][c.second];
  }
  while (!S.empty()) {
    make(S.top().first, S.top().second);
    S.pop();
  }
}
void setp(int i, int j) {
  path(i, j);
  pair<int, int> s = pair<int, int>(i, j);
  block[i][j] = 1;
  for (int p = (0); p < (n); ++p)
    for (int q = (0); q < (m); ++q)
      if (!block[p][q] && source[p][q] == target[i][j])
        s = pair<int, int>(p, q);
  block[i][j] = 0;
  if (s == pair<int, int>(i, j)) {
    printf("-1\n");
    exit(0);
  }
  for (;;) {
    path(s.first, s.second);
    s = R[R.size() - 2];
    if (pair<int, int>(i, j) == s) break;
    block[s.first][s.second] = 1;
    path(i, j);
    block[s.first][s.second] = 0;
  }
  block[i][j] = 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) scanf("%d", &source[i][j]);
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j) scanf("%d", &target[i][j]);
  save();
  if (n == 1 || m == 1) {
    for (int s = (0); s < (max(n, m)); ++s) {
      for (int d = -1; d <= 1; d += 2) {
        load();
        R.push_back(pair<int, int>(n == 1 ? 0 : s, n == 1 ? s : 0));
        for (int i = s + d; - 1 < i && i < max(n, m); i += d) {
          make(n == 1 ? 0 : i, n == 1 ? i : 0);
          check();
        }
      }
    }
    printf("-1\n");
    return 0;
  }
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (m); ++j)
      if (source[i][j] == target[n - 1][m - 1]) a = i, b = j;
  R.push_back(pair<int, int>(a, b));
  for (int i = (0); i < (n - 2); ++i)
    for (int j = (0); j < (m); ++j) setp(i, j);
  for (int j = (0); j < (m - 1); ++j) {
    setp(n - 2, j);
    setp(n - 1, j);
  }
  check();
  if (a == n - 1)
    make(a - 1, b);
  else
    make(a + 1, b);
  check();
  printf("-1\n");
  return 0;
}
