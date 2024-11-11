#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100, mod = 1e9 + 7;
int n, m, r, c;
char a[500][500], p[500][500];
bitset<500> bi[28][500], ans[500];
int flag[29];
int main() {
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 0; i < n; i++) scanf("%s", a[i]);
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++) scanf("%s", p[i]);
    memset(flag, 0, sizeof(flag));
    for (int i = 0; i < 27; i++)
      for (int j = 0; j < n; j++) bi[i][j].reset();
    int cc = 0;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++)
        if (p[i][j] == '?')
          continue;
        else if (flag[p[i][j] - 'a'] == 0) {
          flag[p[i][j] - 'a'] = 1;
          for (int s = 0; s < n; s++)
            for (int g = 0; g < m; g++)
              if (a[s][g] == p[i][j]) bi[p[i][j] - 'a'][s][g] = 1;
        }
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) ans[i][j] = 1;
    for (int i = 0; i < r; i++)
      for (int j = 0; j < c; j++) {
        if (p[i][j] == '?') continue;
        int gg = p[i][j] - 'a';
        for (int s = 0; s < n; s++) {
          ans[((s - i) % n + n) % n] =
              ans[((s - i) % n + n) % n] &
              ((bi[gg][s] >> j) | (bi[gg][s] << (m - j)));
        }
      }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) putchar(ans[i][j] ? '1' : '0');
      printf("\n");
    }
  }
  return 0;
}
