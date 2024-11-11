#include <bits/stdc++.h>
using namespace std;
inline int get() {
  char c;
  while (!isdigit(c = getchar()))
    ;
  int v = c - 48;
  while (isdigit(c = getchar())) v = v * 10 + c - 48;
  return v;
}
const int mod = 51123987;
int n, nxt[155][3], f[155][52][52][52];
char str[155];
void ad(int& x, int y) {
  if ((x += y) >= mod) x -= mod;
}
int main() {
  scanf("%d", &n);
  scanf("%s", str + 1);
  f[0][0][0][0] = 1;
  for (int i = n; i >= 0; --i) {
    nxt[i][0] = nxt[i + 1][0];
    nxt[i][1] = nxt[i + 1][1];
    nxt[i][2] = nxt[i + 1][2];
    if (i) nxt[i][str[i] - 'a'] = i;
  }
  int m = n / 3 + 1, ans = 0;
  for (int i = 0; i <= n; ++i)
    for (int a = 0; a <= m; ++a)
      for (int b = 0; b <= m; ++b) {
        for (int c = 0; a + b + c < n && c <= m; ++c)
          if (f[i][a][b][c]) {
            if (nxt[i][0]) ad(f[nxt[i][0]][a + 1][b][c], f[i][a][b][c]);
            if (nxt[i][1]) ad(f[nxt[i][1]][a][b + 1][c], f[i][a][b][c]);
            if (nxt[i][2]) ad(f[nxt[i][2]][a][b][c + 1], f[i][a][b][c]);
          }
        int c = n - a - b;
        if (c >= 0 && abs(a - b) <= 1 && abs(a - c) <= 1 && abs(b - c) <= 1)
          ad(ans, f[i][a][b][c]);
      }
  cout << ans << endl;
  return 0;
}
