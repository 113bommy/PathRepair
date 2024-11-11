#include <bits/stdc++.h>
using namespace std;
char s[510];
int ch[1001000][26], sz[1001000], val[1001000];
int tot;
vector<int> f[1001000];
void add() {
  int u = 0;
  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    sz[u]++;
    if (!ch[u][s[i] - 'a']) {
      ch[u][s[i] - 'a'] = ++tot;
    }
    u = ch[u][s[i] - 'a'];
  }
  sz[u]++;
  val[u]++;
}
void dp(int x) {
  f[x].resize(sz[x] + 1);
  for (int i = 0; i < (int)f[x].size(); i++) f[x][i] = 0;
  int tmp = 0;
  for (int i = 0; i < 26; i++) {
    if (ch[x][i]) {
      dp(ch[x][i]);
      int y = ch[x][i];
      tmp += sz[y];
      for (int k = tmp; k >= 0; k--) {
        for (int l = 1; l <= sz[y]; l++) {
          if (k < l) break;
          f[x][k] = max(f[x][k], f[x][k - l] + f[y][l] + l * (l - 1) / 2);
        }
      }
    }
  }
}
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%s", s);
    add();
  }
  dp(0);
  printf("%d\n", f[0][k]);
  return 0;
}
