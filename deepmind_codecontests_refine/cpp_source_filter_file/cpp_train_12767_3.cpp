#include <bits/stdc++.h>
using namespace std;
const int MAX_LEN = 50;
char s[20];
int tot = 0;
struct data {
  int x;
  bool judge;
  string s;
} g[600];
string f[300][2];
void Update(int x, bool judge, string s) {
  if (judge) Update(x, 0, s);
  int len = s.length(), len2 = f[x][judge].length();
  if (len2 == 0 || len < len2) {
    f[x][judge] = s;
    return;
  }
  if (len > len2) return;
  if (s < f[x][judge]) f[x][judge] = s;
}
void make(data x, data y) {
  Update(x.x | y.x, 0, x.s + "|" + y.s);
  Update(x.x | y.x, 0, y.s + "|" + x.s);
  if (x.judge == 0) x.s = "(" + x.s + ")";
  if (y.judge == 0) y.s = "(" + y.s + ")";
  Update(x.x & y.x, 1, x.s + "&" + y.s);
  Update(x.x & y.x, 1, y.s + "&" + x.s);
}
void prework() {
  for (int i = 0; i < 256; i++) f[i][0] = f[i][1] = "";
  f[240][1] = f[240][0] = "x";
  f[204][1] = f[204][0] = "y";
  f[170][1] = f[170][0] = "z";
  for (int i = 1; i <= MAX_LEN; i++)
    for (int j = 0; j < 256; j++)
      for (int jx = 0; jx <= 1; jx++)
        if (f[j][jx].length() == i) {
          g[++tot].x = j;
          g[tot].judge = jx;
          g[tot].s = f[j][jx];
          string nows = g[tot].s;
          if (nows.length() == 1)
            nows = "!" + nows;
          else
            nows = "(" + nows + ")";
          Update(255 ^ j, 1, nows);
          for (int kx = 1; kx < tot; kx++) make(g[tot], g[kx]);
        }
}
int main() {
  prework();
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int x = 0;
    for (int i = 0; i < 8; i++)
      if (s[i] == '1') x += (1 << i);
    cout << f[x][0] << endl;
  }
  return 0;
}
