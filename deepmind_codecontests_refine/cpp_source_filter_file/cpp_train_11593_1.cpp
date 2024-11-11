#include <bits/stdc++.h>
using namespace std;
bool good(string s[], int g[][4], int x);
bool f(string s[], int g[][4], int x, int m);
int main() {
  string s1[3], s[4];
  int cnt = 0;
  bool p[4][4] = {};
  int g[4][4] = {};
  for (int i = 0; i < 5; i++) {
    cin >> s1[0] >> s1[1] >> s1[2];
    int t1 = cnt;
    for (int j = 0; j < cnt; j++)
      if (s1[0] == s[j]) t1 = j;
    if (t1 == cnt) s[cnt++] = s1[0];
    int t2 = cnt;
    for (int j = 0; j < cnt; j++)
      if (s1[1] == s[j]) t2 = j;
    if (t2 == cnt) s[cnt++] = s1[1];
    p[t1][t2] = p[t2][t1] = true;
    g[t1][t2] = s1[2][0] - '0';
    g[t2][t1] = s1[2][2] - '0';
  }
  int x = 0;
  for (int i = 0; i < 4; i++)
    if (s[i] == "BERLAND") x = i;
  int y = 0;
  for (int i = 0; i < 4; i++)
    if (i != x && !p[x][i]) y = i;
  for (int i = 1; i <= 9; i++)
    for (int j = i; j <= 9; j++) {
      g[x][y] = j;
      g[y][x] = j - i;
      if (good(s, g, x)) {
        cout << j << ':' << j - i << '\n';
        return 0;
      }
    }
  cout << "IMPOSSIBLE\n";
  return 0;
}
bool good(string s[], int g[][4], int x) {
  int t = 0;
  for (int i = 0; i < 4; i++)
    if (x != i)
      if (f(s, g, x, i)) t++;
  return t >= 2;
}
bool f(string s[], int g[][4], int x, int m) {
  int t1 = 0, t2 = 0;
  for (int i = 0; i < 4; i++)
    if (i != x) {
      if (g[x][i] > g[i][x]) t1 += 3;
      if (g[x][i] == g[i][x]) t1++;
    }
  for (int i = 0; i < 4; i++)
    if (i != m) {
      if (g[m][i] > g[i][m]) t2 += 3;
      if (g[m][i] == g[i][m]) t2++;
    }
  if (t1 > t2) return true;
  if (t2 > t1) return false;
  int g1 = g[x][0] + g[x][1] + g[x][2] + g[x][3];
  int m1 = g[0][x] + g[1][x] + g[2][x] + g[3][x];
  int g2 = g[m][0] + g[m][1] + g[m][2] + g[m][3];
  int m2 = g[0][m] + g[1][m] + g[2][m] + g[3][m];
  if (g1 - m1 > g2 - m2) return true;
  if (g1 - m1 < g2 - m2) return false;
  if (g1 > g2) return true;
  if (g2 > g1) return false;
  return s[x] < s[m];
}
