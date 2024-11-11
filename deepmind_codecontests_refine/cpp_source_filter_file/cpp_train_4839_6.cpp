#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
char s[N][N], str[N][N];
long long ans;
bool up[N][N], down[N][N];
void solve(char s[N][N], int n, int m, bool flag) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') {
        up[i][j] = true;
        continue;
      }
      if (i == 1)
        up[i][j] = false;
      else
        up[i][j] |= up[i - 1][j];
    }
  }
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#')
        down[i][j] = true;
      else if (i == n)
        down[i][j] = false;
      else
        down[i][j] |= down[i + 1][j];
  for (int i = 2; i < n; i++) {
    bool flag = false;
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') flag = true;
    ans += !flag;
  }
  for (int i = 2; i < n; i++) {
    int cnt_up = 0, cnt_down = 0;
    for (int j = 3; j < m; j++) {
      if (s[i][j] == '#') {
        cnt_up = 0;
        cnt_down = 0;
        continue;
      }
      if (!up[i][j]) ans += cnt_up;
      if (!down[i][j]) ans += cnt_down;
      cnt_up += !up[i][j - 1];
      cnt_down += !down[i][j - 1];
    }
  }
  for (int i = 2; i < n; i++) {
    int cnt_up = 0, cnt_down = 0;
    for (int j = 2; j < m; j++) {
      if (s[i][j] == '#') {
        cnt_up = 0;
        cnt_down = 0;
        continue;
      }
      if (!up[i][j]) ans += cnt_down;
      if (!down[i][j]) ans += cnt_up;
      cnt_up += !up[i][j];
      cnt_down += !down[i][j];
    }
  }
  if (!flag) return;
  for (int i = 2; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (s[i][j] == '#') break;
      if (j > 1) ans += !up[i][j];
      if (j > 1) ans += !down[i][j];
    }
    for (int j = m; j > 1; j--) {
      if (s[i][j] == '#') break;
      if (j > 1) ans += !up[i][j];
      if (j > 1) ans += !down[i][j];
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) str[j][i] = s[i][j];
  solve(s, n, m, true);
  solve(str, m, n, false);
  cout << ans << endl;
  return 0;
}
