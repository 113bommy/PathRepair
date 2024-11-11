#include <bits/stdc++.h>
using namespace std;
const int N = 12;
const int M = 10005;
const int lim = 200000;
const int inf = 1e9;
int T;
int n, m;
int x[N];
char s[N][M];
int cnt[M];
int b[M];
int ans[M];
bool cmp(int i, int j) { return cnt[i] < cnt[j]; }
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n - 1; ++i) scanf("%d", &x[i]);
    for (int i = 0; i <= n - 1; ++i) scanf("%s", s[i]);
    int ret = 0;
    for (int mask = 0; mask <= (1 << n) - 1; ++mask) {
      for (int j = 0; j <= m - 1; ++j) cnt[j] = 0;
      for (int i = 0; i <= n - 1; ++i) {
        for (int j = 0; j <= m - 1; ++j) {
          if (s[i][j] == '1') {
            if (mask & (1 << i))
              ++cnt[j];
            else
              --cnt[j];
          }
        }
      }
      for (int j = 0; j <= m - 1; ++j) b[j] = j;
      sort(b, b + m, cmp);
      int tmp = 0;
      for (int i = 0; i <= n - 1; ++i) {
        int r = 0;
        for (int j = 0; j <= m - 1; ++j) {
          if (s[i][b[j]] == '1') {
            r += j + 1;
          }
        }
        if (mask & (1 << i))
          tmp += r - x[i];
        else
          tmp -= r - x[i];
      }
      if (tmp > ret) {
        ret = tmp;
        for (int j = 0; j <= m - 1; ++j) ans[b[j]] = j + 1;
      }
    }
    for (int j = 0; j <= m - 1; ++j) printf("%d ", ans[j]);
    printf("\n");
  }
  return 0;
}
