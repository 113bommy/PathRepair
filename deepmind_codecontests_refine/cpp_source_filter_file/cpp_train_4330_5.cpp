#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char a[N], b[N][N];
int c[N], f[N][N], id[N], tot[N][11], len[N];
vector<int> tmp[10];
void upd(int &a, int b) {
  if (b == -1) return;
  a = (a == -1 || b > a) ? b : a;
}
int main() {
  scanf("%s", a);
  int al = strlen(a);
  reverse(a, a + al);
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", b[i]), len[i] = strlen(b[i]);
    reverse(b[i], b[i] + len[i]);
    for (int j = len[i]; j <= al - 1; j++) b[i][j] = '0';
    len[i] = max(len[i], al);
    for (int j = len[i]; j <= 1000; j++) b[i][j] = '9' + 1;
  }
  for (int i = 0; i <= 9; i++) scanf("%d", &c[i]);
  for (int i = 1; i <= n; i++) id[i] = i;
  reverse(id + 1, id + n + 1);
  for (int i = 0; i <= 1001; i++)
    for (int j = 0; j <= n; j++) f[i][j] = -1;
  f[0][0] = 0;
  for (int i = 0; i <= 1000; i++) {
    for (int j = 1; j <= n; j++)
      for (int k = 0; k <= 10; k++)
        tot[j][k] = tot[j - 1][k] + (b[id[j]][i] - '0' == k);
    for (int j = 0; j <= n; j++)
      if (~f[i][j]) {
        if (i >= al || a[i] != '?') {
          int cnt = 0, ans = f[i][j], cha = (i >= al) ? 0 : (a[i] - '0');
          for (int k = 0; k <= 9; k++) {
            int ch = k + cha + 1, t = tot[j][k];
            ans += c[ch % 10] * t;
            cnt += (ch >= 10) * t;
            ch = k + cha;
            t = tot[n][k] - tot[j][k];
            ans += c[ch % 10] * t;
            cnt += (ch >= 10) * t;
          }
          if (i > al) ans += c[1] * tot[j][10];
          upd(f[i + 1][cnt], ans);
        } else {
          int st = ((i == al - 1) ? 1 : 0);
          for (int cha = st; cha <= 9; cha++) {
            int cnt = 0, ans = f[i][j];
            for (int k = 0; k <= 9; k++) {
              int ch = k + cha + 1, t = tot[j][k];
              ans += c[ch % 10] * t;
              cnt += (ch >= 10) * t;
              ch = k + cha;
              t = tot[n][k] - tot[j][k];
              ans += c[ch % 10] * t;
              cnt += (ch >= 10) * t;
            }
            upd(f[i + 1][cnt], ans);
          }
        }
      }
    reverse(id + 1, id + n + 1);
    for (int j = 0; j < 10; j++) tmp[j].clear();
    for (int j = 1; j <= n; j++) tmp[(b[id[j]][i] - '0') % 10].push_back(id[j]);
    int l = 0;
    for (int j = 0; j < 10; j++) {
      int len = tmp[j].size();
      for (int k = 0; k < len; k++) id[++l] = tmp[j][k];
    }
    reverse(id + 1, id + l + 1);
  }
  int ans = -1;
  for (int j = 0; j <= n; j++) upd(ans, f[1001][j]);
  cout << ans << endl;
  return 0;
}
