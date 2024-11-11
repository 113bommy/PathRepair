#include <bits/stdc++.h>
using namespace std;
const int N = 666666;
int ch[N][26], n, zun, ans[N], z[26];
void nw(int &i) {
  for (int j = 0; j < 26; j++) {
    ch[zun][j] = ch[i][j];
  }
  i = zun++;
}
void mokou(int &i, int j, int dep) {
  if (!i || !j) {
    i = i + j;
    return;
  }
  nw(i);
  ans[dep]++;
  for (int k = 0; k < 26; k++) {
    mokou(ch[i][k], ch[j][k], dep);
  }
}
void dfs(int u, int dep) {
  zun = n + 1;
  ans[dep - 1]++;
  for (int j = 0; j < 26; j++) {
    int z = 0;
    for (int i = 0; i < 26; i++)
      if (ch[ch[u][i]][j]) {
        mokou(z, ch[ch[u][i]][j], dep);
      }
  }
  for (int i = 0; i < 26; i++)
    if (ch[u][i]) {
      dfs(ch[u][i], dep + 1);
    }
}
int main() {
  scanf("%d", &n);
  memset(ch, 0, sizeof(ch));
  for (int i = 1; i < n; i++) {
    int u, v;
    char c[2];
    scanf("%d%d%s", &u, &v, c);
    ch[u][c[0] - 'a'] = v;
  }
  memset(ans, 0, sizeof(ans));
  dfs(1, 1);
  int ansx = 0;
  for (int i = 0; i < n; i++) {
    if (ans[i] > ans[ansx]) ansx = i;
  }
  printf("%d\n%d\n", n - ans[ansx], ansx);
  return 0;
}
