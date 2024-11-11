#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000009;
int num(char c) {
  if (c == 'A') return 0;
  if (c == 'G') return 1;
  if (c == 'C')
    return 2;
  else
    return 3;
}
const int N = 1010;
const int M = 110;
int n, m, ch[M][4], fail[M], val[M], tail = 0;
long long dp[N][M][15], ans = 0;
char s[20];
queue<int> Q;
void insert() {
  int len = strlen(s);
  int tmp = 0;
  for (int i = 0; i < len; i++) {
    int c = num(s[i]);
    if (!ch[tmp][c]) ch[tmp][c] = ++tail;
    tmp = ch[tmp][c];
  }
  val[tmp] = len;
}
void getfail() {
  for (int i = 0; i < 4; i++)
    if (ch[0][i]) {
      Q.push(ch[0][i]);
      fail[ch[0][i]] = 0;
    }
  while (!Q.empty()) {
    int top = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      if (!ch[top][i]) {
        ch[top][i] = ch[fail[top]][i];
        continue;
      }
      int u = ch[top][i];
      fail[u] = ch[fail[top]][u];
      val[u] = max(val[u], val[fail[u]]);
      Q.push(u);
    }
  }
}
void getans() {
  memset(dp, 0, sizeof(dp));
  dp[0][0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int u = 0; u <= tail; u++) {
      for (int j = 0; j <= 10; j++) {
        for (int c = 0; c < 4; c++) {
          int v = ch[u][c];
          if (val[v] >= j + 1)
            dp[i + 1][v][0] = (dp[i + 1][v][0] + dp[i][u][j]) % mod;
          else
            dp[i + 1][v][j + 1] = (dp[i][u][j] + dp[i + 1][v][j + 1]) % mod;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 1; i <= tail; i++) {
    ans = (ans + dp[n][i][0]) % mod;
  }
  printf("%I64d\n", ans);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%s", s);
    insert();
  }
  getfail();
  getans();
  return 0;
}
