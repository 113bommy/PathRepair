#include <bits/stdc++.h>
using namespace std;
const int MAXN = 255;
char s[MAXN][MAXN];
int n, m, ans, num[MAXN * 2][26], odd[MAXN * 2], p[MAXN * 2];
bool cmp(int x, int y) {
  if (odd[x] > 1 || odd[y] > 1) return 0;
  for (int c = 0; c < 26; c++)
    if (num[x][c] != num[y][c]) return 0;
  return 1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int l = 1; l <= m; l++) {
    memset(num, 0, sizeof num);
    memset(odd, 0, sizeof odd);
    for (int r = l; r <= m; r++) {
      for (int i = 1; i <= n; i++) {
        int c = s[i][r] - 'a';
        if (num[2 * i][c] & 1)
          odd[2 * i]--;
        else
          odd[2 * i]++;
        num[2 * i][c]++;
      }
      int mx = 0, id = 0;
      for (int i = 1; i <= 2 * n + 1; i++) {
        if (i < mx)
          p[i] = min(p[id * 2 - i], mx - i);
        else
          p[i] = 1;
        for (;
             i + p[i] <= 2 * n + 1 && i - p[i] > 0 && cmp(i + p[i], i - p[i]);)
          p[i]++;
        if (i + p[i] > mx) mx = i + p[i], id = i;
        if (odd[i] <= 1) ans += p[i] / 2;
      }
    }
  }
  printf("%d\n", ans);
}
