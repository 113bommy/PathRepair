#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
void get_val(int &a) {
  int value = 0, s = 1;
  char c;
  while ((c = getchar()) == ' ' || c == '\n')
    ;
  if (c == '-')
    s = -s;
  else
    value = c - 48;
  while ((c = getchar()) >= '0' && c <= '9') value = value * 10 + c - 48;
  a = s * value;
}
int mat[350][350] = {0};
int numbre[350];
int vis[350] = {0};
void dfs(int now, int n) {
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && mat[now][i]) {
      vis[i] = 1;
      dfs(i, n);
      for (int j = 1; j <= n; j++)
        mat[now][j] = mat[i][j] = (mat[now][j] | mat[i][j]);
    }
  }
}
int w[1000], order[1500], ans_o[1500];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> w[i];
  for (int i = 1; i <= m; i++) cin >> order[i];
  int ans = 0, len = 1;
  for (int i = 1; i <= m; i++) {
    if (order[i] == order[i - 1] && i != 1) continue;
    int j, tmp = 0;
    for (j = 1; j < len; j++) {
      if (ans_o[j] == order[i]) break;
      tmp += ans_o[j];
    }
    ans += tmp;
    ans_o[0] = order[i];
    if (j >= len) len++;
    for (int i = j; i >= 1; i--) ans_o[i] = ans_o[i - 1];
  }
  cout << ans << endl;
  return 0;
}
