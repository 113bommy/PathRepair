#include <bits/stdc++.h>
using namespace std;
int read();
const int N = 2005;
int n;
char s[N][N], ops[128];
void output() {
  cout << endl;
  for (int i = (n); i >= (1); --i) {
    for (int j = (1); j <= (n); ++j)
      if (i + j & 1)
        cout << s[i][j];
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
  for (int i = (n); i >= (1); --i) {
    for (int j = (1); j <= (n); ++j)
      if (~(i + j) & 1)
        cout << s[i][j];
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
}
void upd1() {
  for (int x = (2); x <= (n); ++x)
    for (int y = (1); y <= (n - 1); ++y)
      if ((~(x + y) & 1) && s[x][y] == '.' && s[x - 1][y + 1] != '.')
        s[x][y] = ops[s[x - 1][y + 1]];
}
void upd2() {
  for (int x = (n - 1); x >= (1); --x)
    for (int y = (n); y >= (2); --y)
      if ((~(x + y) & 1) && s[x][y] == '.' && s[x + 1][y - 1] != '.')
        s[x][y] = ops[s[x + 1][y - 1]];
}
void upd3() {
  for (int x = (2); x <= (n); ++x)
    for (int y = (2); y <= (n); ++y)
      if ((x + y & 1) && s[x][y] == '.' && s[x - 1][y - 1] != '.')
        s[x][y] = ops[s[x - 1][y - 1]];
}
void upd4() {
  for (int x = (n - 1); x >= (1); --x)
    for (int y = (n - 1); y >= (1); --y)
      if ((x + y & 1) && s[x][y] == '.' && s[x + 1][y + 1] != '.')
        s[x][y] = ops[s[x + 1][y + 1]];
}
int upd5() {
  for (int i = 1; i <= n; i += 2)
    if (s[1][i] != s[1][i + 1]) {
      if (s[1][i] == '.')
        s[1][i] = s[1][i + 1];
      else if (s[1][i + 1] == '.')
        s[1][i + 1] = s[1][i];
      else
        return 0;
    }
  for (int i = 1; i <= n; i += 2)
    if (s[i][n] != s[i + 1][n]) {
      if (s[i][n] == '.')
        s[i][n] = s[i + 1][n];
      else if (s[i + 1][n] == '.')
        s[i + 1][n] = s[i][n];
      else
        return 0;
    }
  for (int i = 1; i <= n; i += 2)
    if (s[n][i] != s[n][i + 1]) {
      if (s[n][i] == '.')
        s[n][i] = s[n][i + 1];
      else if (s[n][i + 1] == '.')
        s[n][i + 1] = s[n][i];
      else
        return 0;
    }
  for (int i = 1; i <= n; i += 2)
    if (s[i][1] != s[i + 1][1]) {
      if (s[i][1] == '.')
        s[i][1] = s[i + 1][1];
      else if (s[i + 1][1] == '.')
        s[i + 1][1] = s[i][1];
      else
        return 0;
    }
  return 1;
}
int work(int job) {
  if (!upd5()) return 0;
  if (job) upd1();
  if (!upd5()) return 0;
  if (job) upd3();
  if (!upd5()) return 0;
  if (job) upd2();
  if (!upd5()) return 0;
  if (job) upd4();
  if (!upd5()) return 0;
  return 1;
}
const int gox[] = {0, 1, 0, -1}, goy[] = {1, 0, -1, 0};
int solve() {
  upd1();
  upd2();
  upd3();
  upd4();
  if (!work(1)) return 0;
  if (!work(1)) return 0;
  if (!work(1)) return 0;
  if (!work(1)) return 0;
  for (int x = (2); x <= (n); ++x)
    for (int y = (1); y <= (n - 1); ++y)
      if ((~(x + y) & 1) && s[x][y] != '.' && s[x - 1][y + 1] == s[x][y])
        return 0;
  for (int x = (2); x <= (n); ++x)
    for (int y = (2); y <= (n); ++y)
      if ((x + y & 1) && s[x][y] != '.' && s[x - 1][y - 1] == s[x][y]) return 0;
  if (!work(0)) return 0;
  for (int x = (1); x <= (n); ++x)
    for (int y = (1); y <= (n); ++y)
      if (s[x][y] == '.') return 2;
  for (int x = (1); x <= (n); ++x)
    for (int y = (1); y <= (n); ++y) {
      int cnt = 0;
      for (int i = (0); i < (4); ++i)
        if (s[x][y] == s[x + gox[i]][y + goy[i]]) ++cnt;
      if (cnt != 2) {
        cout << x << ' ' << y << ' ' << s[x][y] << ' ';
        for (int i = (0); i < (4); ++i)
          cout << x + gox[i] << ' ' << y + goy[i] << ' '
               << s[x + gox[i]][y + goy[i]] << ' ';
        cout << endl;
        exit(0);
      }
    }
  return 1;
}
int main() {
  ops['S'] = 'G';
  ops['G'] = 'S';
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> &s[i][1];
  if (n & 1) return cout << "NONE" << endl, 0;
  int ans = solve();
  if (ans == 1) {
    cout << "UNIQUE" << endl;
    for (int i = (1); i <= (n); ++i) cout << &s[i][1] << endl;
  } else
    cout << (ans ? "MULTIPLE" : "NONE") << endl;
  return 0;
}
const int S = 1 << 21;
char p0[S], *p1, *p2;
inline int read() {
  static int x, c, f;
  x = 0;
  f = 1;
  do
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++),
    c == '-' && (f = -1);
  while (!isdigit(c));
  do
    x = x * 10 + (c & 15),
    c = (p2 == p1 && (p2 = (p1 = p0) + fread(p0, 1, S, stdin)) == p1 ? EOF
                                                                     : *p1++);
  while (isdigit(c));
  return x * f;
}
