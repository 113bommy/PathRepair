#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
const int SIZE = 210;
struct node {
  int son[21], val, fail;
} t[SIZE];
int Lnum[SIZE], Rnum[SIZE];
int dp[SIZE][SIZE][510][3];
int N, M, K, tot;
queue<int> Q;
void Read() {
  scanf("%d%d%d", &N, &M, &K);
  scanf("%d", &Lnum[0]);
  for (int i = 1; i <= Lnum[0]; i++) scanf("%d", &Lnum[i]);
  scanf("%d", &Rnum[0]);
  for (int i = 1; i <= Rnum[0]; i++) scanf("%d", &Rnum[i]);
}
void Init() {
  for (int i = 1; i <= N; i++) {
    int m;
    scanf("%d", &m);
    int now = 0;
    for (int j = 1; j <= m; j++) {
      int x;
      scanf("%d", &x);
      if (!t[now].son[x]) t[now].son[x] = ++tot;
      now = t[now].son[x];
    }
    int val;
    scanf("%d", &val);
    t[now].val += val;
  }
}
void AC() {
  for (int i = 0; i <= M - 1; i++)
    if (t[0].son[i]) Q.push(t[0].son[i]);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    t[x].val += t[t[x].fail].val;
    for (int i = 0; i <= M - 1; i++)
      if (t[x].son[i]) {
        t[t[x].son[i]].fail = t[t[x].fail].son[i];
        Q.push(t[x].son[i]);
      } else
        t[x].son[i] = t[t[x].fail].son[i];
  }
}
void Updata(int &A, int B) {
  A += B;
  if (A >= md) A -= md;
}
int Solve(int *now) {
  memset(dp, 0, sizeof(dp));
  int ln = now[0];
  dp[1][0][0][0] = 1;
  for (int i = 1; i <= ln; i++)
    for (int j = 0; j <= tot; j++)
      for (int k = 0; k <= K; k++)
        for (int ope = 0; ope <= 2; ope++) {
          if (dp[i][j][k][ope] == 0) continue;
          if (ope == 0) {
            Updata(dp[i + 1][j][k][ope], dp[i][j][k][ope]);
            int ed;
            if (i == 1)
              ed = now[i];
            else
              ed = M - 1;
            for (int nxt = 1; nxt <= ed; nxt++) {
              if (k + t[t[j].son[nxt]].val > K) continue;
              if (i == 1 && nxt == now[i])
                Updata(dp[i + 1][t[j].son[nxt]][k + t[t[j].son[nxt]].val][2],
                       dp[i][j][k][ope]);
              else
                Updata(dp[i + 1][t[j].son[nxt]][k + t[t[j].son[nxt]].val][1],
                       dp[i][j][k][ope]);
            }
          }
          if (ope == 1) {
            for (int nxt = 0; nxt <= M - 1; nxt++) {
              if (k + t[t[j].son[nxt]].val > K) continue;
              Updata(dp[i + 1][t[j].son[nxt]][k + t[t[j].son[nxt]].val][1],
                     dp[i][j][k][ope]);
            }
          }
          if (ope == 2) {
            for (int nxt = 0; nxt <= now[i]; nxt++) {
              if (k + t[t[j].son[nxt]].val > K) continue;
              if (nxt == now[i])
                Updata(dp[i + 1][t[j].son[nxt]][k + t[t[j].son[nxt]].val][2],
                       dp[i][j][k][ope]);
              else
                Updata(dp[i + 1][t[j].son[nxt]][k + t[t[j].son[nxt]].val][1],
                       dp[i][j][k][ope]);
            }
          }
        }
  int ans = 0;
  for (int i = 0; i <= tot; i++)
    for (int j = 0; j <= K; j++)
      for (int ope = 1; ope <= 2; ope++) Updata(ans, dp[ln + 1][i][j][ope]);
  return ans;
}
void Write() {
  int ans = Solve(Rnum) - Solve(Lnum);
  ans += md;
  if (ans >= md) ans -= md;
  int now = 0, val = 0;
  for (int i = 1; i <= Lnum[0]; i++) {
    now = t[now].son[Lnum[i]];
    val += t[now].val;
  }
  if (val <= K) ans++;
  printf("%d\n", ans);
}
int main() {
  Read();
  Init();
  AC();
  Write();
  return 0;
}
