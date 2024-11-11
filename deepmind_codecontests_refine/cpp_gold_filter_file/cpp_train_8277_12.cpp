#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(T &first) {
  char ch;
  for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-';) ch = getchar();
  first = 0;
  int t = 1;
  if (ch == '-') {
    ch = getchar();
    t = -1;
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) first = first * 10 + ch - '0';
  first *= t;
}
double dp[500010][42];
int fa[500010];
int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i <= 40; i++) dp[1][i] = 1;
  int n = 1;
  while (q--) {
    int op, first;
    scanf("%d%d", &op, &first);
    if (op == 1) {
      fa[++n] = first;
      for (int j = 0; j <= 40; j++) dp[n][j] = 1;
      double pre = dp[first][0];
      dp[first][0] /= 2;
      double now = pre / 2;
      first = fa[first];
      for (int i = 1; first && i <= 40; i++, first = fa[first]) {
        double t = dp[first][i];
        dp[first][i] = dp[first][i] * (now + 1) / (pre + 1);
        pre = t;
        now = dp[first][i];
      }
    } else {
      double ans = 0;
      for (int i = 1; i <= 40; i++)
        ans = ans + (dp[first][i] - dp[first][i - 1]) * i;
      printf("%.10lf\n", ans);
    }
  }
  return 0;
}
