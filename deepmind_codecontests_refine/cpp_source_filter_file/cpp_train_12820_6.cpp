#include <bits/stdc++.h>
using namespace std;
const int N = 255;
const int NN = 1e5 + 10;
int dp[N][N][N];
int has[N][26];
string S[3];
int dfs(int x, int y, int z) {
  if (x < 0 || y < 0 || z < 0) return NN - 1;
  if (dp[x][y][z] != -1) return dp[x][y][z];
  int res = NN - 1;
  int u = dfs(x - 1, y, z);
  if (u < NN - 1) res = min(res, has[u][S[0][x - 1] - 'a']);
  u = dfs(x, y - 1, z);
  if (u < NN - 1) res = min(res, has[u][S[1][y - 1] - 'a']);
  u = dfs(x, y, z - 1);
  if (u < NN - 1) res = min(res, has[u][S[2][z - 1] - 'a']);
  return dp[x][y][z] = res + 1;
}
int G[26];
char A[NN];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  scanf(" %s", A);
  for (int i = 0; i < 26; i++) G[i] = NN - 1;
  fill(&has[0][0], &has[N - 1][26], NN - 1);
  for (int i = n - 1; i > -1; i--) {
    G[A[i] - 'a'] = i;
    for (int j = 0; j < 26; j++) has[i][j] = G[j];
  }
  fill(&dp[0][0][0], &dp[N - 1][N - 1][N], -1);
  dp[0][0][0] = 0;
  while (q--) {
    char t, c;
    int v;
    scanf(" %c %d", &t, &v);
    v--;
    if (t == '+') {
      scanf(" %c", &c);
      S[v] += c;
      dfs(S[0].length(), S[1].length(), S[2].length());
    } else {
      for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
          int x, y, z;
          if (v == 0)
            x = S[0].length(), y = i, z = j;
          else if (v == 1)
            y = S[1].length(), x = i, z = j;
          else
            y = S[2].length(), x = i, y = j;
          dp[x][y][z] = -1;
        }
      S[v].pop_back();
    }
    if (dp[S[0].length()][S[1].length()][S[2].length()] <= n)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
