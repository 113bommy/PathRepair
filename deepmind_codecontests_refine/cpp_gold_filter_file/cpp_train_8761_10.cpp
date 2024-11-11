#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int n, m, ch[N][2], r[N][2], l[N][2];
char s[N];
signed main() {
  cin >> n >> m;
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    ch[i][0] = ch[i - 1][0], ch[i][1] = ch[i - 1][1];
    if (s[i] == '1')
      ch[i][1]++;
    else
      ch[i][0]++;
  }
  for (int i = m; i <= n; i++) {
    if (ch[i][1] - ch[i - m][1] == ch[n][1]) {
      puts("tokitsukaze");
      return 0;
    }
    if (ch[i][0] - ch[i - m][0] == ch[n][0]) {
      puts("tokitsukaze");
      return 0;
    }
  }
  for (int i = n - m; i >= 0; i--)
    r[i][1] = max(r[i + 1][1], ch[i + m][1] - ch[i][1]),
    r[i][0] = max(r[i + 1][0], ch[i + m][0] - ch[i][0]);
  for (int i = m; i <= n; i++)
    l[i][1] = max(l[i - 1][1], ch[i][1] - ch[i - m][1]),
    l[i][0] = max(l[i - 1][0], ch[i][0] - ch[i - m][0]);
  for (int i = 1; i < m; i++) l[i][1] = ch[i][1], l[i][0] = ch[i][0];
  for (int i = n; i > n - m; i--)
    r[i][1] = ch[n][1] - ch[i - 1][1], r[i][0] = ch[n][0] - ch[i - 1][0];
  for (int i = m; i <= n; i++) {
    int d = ch[n][1] + (ch[i][0] - ch[i - m][0]);
    if (r[i + 1][0] < n - d && l[i - m][0] < n - d) {
      puts("once again");
      return 0;
    }
    d = ch[n][0] + (ch[i][1] - ch[i - m][1]);
    if (r[i + 1][1] < n - d && l[i - m][1] < n - d) {
      puts("once again");
      return 0;
    }
  }
  puts("quailty");
  return 0;
  return 0;
}
