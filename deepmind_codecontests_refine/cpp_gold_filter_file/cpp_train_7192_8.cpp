#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, tot, minu, ans;
char son[205];
int al[205][105];
int dp[205][205][105];
int ed[205];
int tr[205][2];
int fail[205];
void build(char b[]) {
  int now = 0;
  int len = strlen(b + 1);
  for (int i = 1; i <= len; i++) {
    int k = -1;
    if (b[i] == '(')
      k = 1;
    else
      k = 0;
    if (!tr[now][k]) tr[now][k] = ++cnt;
    now = tr[now][k];
  }
  ed[now] = 1;
}
void getfail() {
  queue<int> que;
  int now = 0;
  if (tr[0][0]) que.push(tr[0][0]);
  if (tr[0][1]) que.push(tr[0][1]);
  while (!que.empty()) {
    int s = que.front();
    que.pop();
    if (tr[s][0]) {
      fail[tr[s][0]] = tr[fail[s]][0];
      que.push(tr[s][0]);
    } else {
      tr[s][0] = tr[fail[s]][0];
    }
    if (tr[s][1]) {
      fail[tr[s][1]] = tr[fail[s]][1];
      que.push(tr[s][1]);
    } else {
      tr[s][1] = tr[fail[s]][1];
    }
  }
}
int main() {
  scanf("%d", &n);
  scanf("%s", son + 1);
  build(son);
  getfail();
  al[1][1] = 1;
  for (int i = 2; i <= 2 * n; i++) {
    for (int j = 0; j <= n; j++) {
      (al[i][j] += al[i - 1][j + 1]) %= 1000000007;
      if (j) (al[i][j] += al[i - 1][j - 1]) %= 1000000007;
    }
  }
  tot = al[2 * n][0];
  dp[0][0][0] = 1;
  for (int i = 1; i <= 2 * n; i++) {
    for (int j = 0; j <= cnt; j++) {
      for (int k = 0; k <= n; k++) {
        if (!ed[tr[j][0]]) {
          (dp[i][tr[j][0]][k] += dp[i - 1][j][k + 1]) %= 1000000007;
        }
        if (!ed[tr[j][1]] && k) {
          (dp[i][tr[j][1]][k] += dp[i - 1][j][k - 1]) %= 1000000007;
        }
      }
    }
  }
  for (int i = 0; i < cnt; i++) {
    (minu += dp[2 * n][i][0]) %= 1000000007;
  }
  ans = ((tot - minu) % 1000000007 + 1000000007) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
