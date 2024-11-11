#include <bits/stdc++.h>
using namespace std;
char e[10005];
int match[10005], len, dpmax[10005][105], dpmin[10005][105], p, m, cnt[10005];
void solve() {
  stack<int> stk;
  for (int i = 0; i < len; i++) {
    if (e[i] == '(')
      stk.push(i);
    else if (e[i] == ')') {
      match[stk.top()] = i;
      match[i] = stk.top();
      stk.pop();
      cnt[i] = cnt[i - 1] + cnt[match[match[i] + 1]] + 1;
      for (int j = 0; j <= cnt[i]; j++) {
        dpmax[i][j] = -10000;
        dpmin[i][j] = 10000;
      }
      for (int j = 0; j <= cnt[i - 1]; j++)
        for (int k = 0; k <= cnt[match[match[i] + 1]]; k++) {
          dpmax[i][j + k + (p < m)] =
              max(dpmax[i][j + k + (p < m)],
                  dpmax[i - 1][j] + dpmax[match[match[i] + 1]][k]);
          dpmax[i][j + k + (p >= m)] =
              max(dpmax[i][j + k + (p >= m)],
                  -dpmin[i - 1][j] + dpmax[match[match[i] + 1]][k]);
          dpmin[i][j + k + (p < m)] =
              min(dpmin[i][j + k + (p < m)],
                  dpmin[i - 1][j] + dpmin[match[match[i] + 1]][k]);
          dpmin[i][j + k + (p >= m)] =
              min(dpmin[i][j + k + (p >= m)],
                  -dpmax[i - 1][j] + dpmin[match[match[i] + 1]][k]);
        }
    } else if (e[i] != '?') {
      match[i] = i;
      dpmax[i][0] = dpmin[i][0] = e[i] - '0';
    }
  }
  printf("%d\n", dpmax[len - 1][min(p, m)]);
}
int main() {
  scanf("%s", e);
  len = strlen(e);
  scanf("%d%d", &p, &m);
  solve();
  return 0;
}
