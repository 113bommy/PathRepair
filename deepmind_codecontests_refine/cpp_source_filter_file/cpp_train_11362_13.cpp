#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 500010;
vector<int> G[N << 2];
int n, numn, deg[N << 2];
char s[N];
int main() {
  int T = read();
  for (int kase = (1); kase <= (T); ++kase) {
    int n = read();
    numn = n;
    for (int i = (1); i <= (n - 1); ++i) {
      int u = read(), v = read();
      G[u].push_back(v), G[v].push_back(u);
    }
    scanf("%s", s + 1);
    if (n <= 2)
      puts("Draw");
    else if (n == 3) {
      int ret = 0;
      for (int i = (1); i <= (n); ++i) ret += (s[i] == 'W');
      puts(ret >= 2 ? "White" : "Draw");
    } else {
      for (int i = (1); i <= (n); ++i)
        if (s[i] == 'W') {
          numn++, G[numn].push_back(i), G[i].push_back(numn);
          G[numn].push_back(numn + 1), G[numn + 1].push_back(numn);
          G[numn].push_back(numn + 2), G[numn + 2].push_back(numn);
          numn += 2;
        }
      bool pd = 0;
      int cnt3 = 0;
      for (int i = (1); i <= (numn); ++i) {
        if (pd) break;
        if (G[i].size() >= 4) {
          puts("White"), pd = 1;
        } else {
          if (G[i].size() >= 3) cnt3++;
          int num2 = 0, num3 = 0;
          for (int j = (0); j <= (G[i].size() - 1); ++j)
            num2 += G[G[i][j]].size() >= 2, num3 += G[G[i][j]].size() >= 3;
          if (G[i].size() >= 2 && num3 >= 2 || G[i].size() >= 3 && num2 >= 2)
            puts("White"), pd = 1;
        }
      }
      if (cnt3 >= 2 && numn & 1) puts("White"), pd = 1;
      if (!pd) puts("Draw");
    }
    for (int i = (1); i <= (numn); ++i) G[i].clear();
  }
}
