#include <bits/stdc++.h>
using namespace std;
template <typename OutputIterator>
void input(OutputIterator first, OutputIterator last) {
  while (first != last) cin >> *(first++);
}
template <typename InputIterator>
void output(InputIterator first, InputIterator last, string fs = " ",
            bool newline = 0) {
  while (first != last) cout << *(first++) << fs;
  if (newline) cout << endl;
}
static inline int Rint() {
  struct X {
    int dig[256];
    X() {
      for (int i = '0'; i <= '9'; ++i) dig[i] = 1;
      dig['-'] = 1;
    }
  };
  static X fuck;
  int s = 1, v = 0, c;
  for (; !fuck.dig[c = getchar()];)
    ;
  if (c == '-')
    s = 0;
  else if (fuck.dig[c])
    v = c ^ 48;
  for (; fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48))
    ;
  return s ? v : -v;
}
int n, m;
char str[2020][2020];
int flag[2020][2020];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
bool check(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m && str[x][y] == '.');
}
queue<pair<int, int> > qqq;
void fuck(int i, int j) {
  for (int k = 0; k < (4); ++k) {
    int x = dx[k] + i;
    int y = dy[k] + j;
    if (!check(x, y)) continue;
    --flag[x][y];
    if (flag[x][y] == 1) qqq.push(make_pair(x, y));
  }
}
int main() {
  cin >> n >> m;
  input(str, str + n);
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j)
      if (str[i][j] == '*')
        flag[i][j] = -1;
      else {
        flag[i][j] = 0;
        for (int k = 0; k < (4); ++k) {
          int x = dx[k] + i;
          int y = dy[k] + j;
          flag[i][j] += check(x, y);
        }
      }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j)
      if (flag[i][j] == 1) qqq.push(make_pair(i, j));
  char ans0[] = {'<', '>', '^', 'v'};
  char ans1[] = {'>', '<', 'v', '^'};
  while (!qqq.empty()) {
    pair<int, int> u = qqq.front();
    qqq.pop();
    if (flag[u.first][u.second] != 1) continue;
    flag[u.first][u.second] = -1;
    for (int k = 0; k < (4); ++k) {
      int x = u.first + dx[k];
      int y = u.second + dy[k];
      if (!check(x, y)) continue;
      flag[x][y] = -1;
      str[u.first][u.second] = ans0[k];
      str[x][y] = ans1[k];
      fuck(x, y);
      break;
    }
  }
  for (int i = 0; i < (n); ++i)
    for (int j = 0; j < (m); ++j)
      if (flag[i][j] != -1) {
        puts("Not unique");
        return 0;
      }
  output(str, str + n, "\n");
  return 0;
}
