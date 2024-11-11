#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 10;
long long top_u[maxn], top_d[maxn], bot_u[maxn], bot_d[maxn], ans[maxn];
int uu[maxn], ud[maxn], du[maxn], dd[maxn];
char s[maxn];
int main(void) {
  int n, cnt_u, cnt_d;
  scanf("%d %s", &n, s + 1);
  for (int i = 2; i <= n + 1; i++) {
    du[i] = du[i - 1] + (s[i - 1] == 'U');
    dd[i] = dd[i - 1] + (s[i - 1] == 'D');
  }
  for (int i = n - 1; i >= 0; i--) {
    uu[i] = uu[i + 1] + (s[i + 1] == 'U');
    ud[i] = ud[i + 1] + (s[i + 1] == 'D');
  }
  cnt_u = cnt_d = 0;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U')
      bot_u[cnt_u + 1] = bot_u[cnt_u] + i, cnt_u++;
    else
      bot_d[cnt_d + 1] = bot_d[cnt_d] + i, cnt_d++;
  }
  cnt_u = cnt_d = 0;
  for (int i = n; i > 0; i--) {
    if (s[i] == 'U')
      top_u[cnt_u + 1] = top_u[cnt_u] + (n - i + 1), cnt_u++;
    else
      top_d[cnt_d + 1] = top_d[cnt_d] + (n - i + 1), cnt_d++;
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'U') {
      if (ud[i] <= du[i])
        ans[i] = (bot_d[dd[n + 1]] - bot_d[dd[i + 1]] +
                  top_u[uu[i - 1] + dd[n + 1] - dd[i + 1]] - top_u[uu[i - 1]] -
                  (long long)(n + 1) * (dd[n + 1] - dd[i + 1])) *
                     2 +
                 n - i + 1;
      else
        ans[i] = (bot_d[dd[i + 1] + uu[0] - uu[i - 1] + 1] - bot_d[dd[i + 1]] +
                  top_u[uu[0]] - top_u[uu[i - 1]] -
                  (long long)(n + 1) * (uu[0] - uu[i - 1]) - i) *
                     2 +
                 i;
    } else {
      if (du[i] <= ud[i])
        ans[i] = (top_u[uu[0]] - top_u[uu[i - 1]] +
                  bot_d[dd[i + 1] + uu[0] - uu[i - 1]] - bot_d[dd[i + 1]] -
                  (long long)(n + 1) * (uu[0] - uu[i - 1])) *
                     2 +
                 i;
      else
        ans[i] = (top_u[uu[i - 1] + dd[n + 1] - dd[i + 1] + 1] -
                  top_u[uu[i - 1]] + bot_d[dd[n + 1]] - bot_d[dd[i + 1]] -
                  (long long)(n + 1) * (dd[n + 1] - dd[i + 1]) - (n - i + 1)) *
                     2 +
                 n - i + 1;
    }
  }
  for (int i = 1; i <= n; i++) printf("%I64d ", ans[i]);
  return 0;
}
