#include <bits/stdc++.h>
using namespace std;
vector<int> V[2];
const int maxn = 70005;
int dp[2][maxn], n;
bool visit[2][maxn];
int search(int x, int y) {
  if (dp[x][y]) return dp[x][y];
  if (visit[x][y]) return dp[x][y];
  visit[x][y] = 1;
  for (int i = 0; i < V[x].size(); i++) {
    if ((y + V[x][i]) % n == 0) {
      dp[x][y] = 1;
      return 1;
    }
  }
  int t, temp, sum = 0;
  for (int i = 0; i < V[x].size(); i++) {
    t = (y + V[x][i]) % n;
    temp = search(x ^ 1, t);
    if (temp == 2) {
      dp[x][y] = 1;
      return 1;
    } else if (temp == 1) {
      sum++;
    }
    if (sum == V[x].size()) {
      dp[x][y] = 2;
      return 2;
    }
  }
  return dp[x][y];
}
int main() {
  char str[][8] = {"Loop", "Win", "Lose"};
  int k, s;
  scanf("%d", &n);
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &s);
    V[0].push_back(s);
  }
  scanf("%d", &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &s);
    V[1].push_back(s);
  }
  for (int j = 0; j < 2; j++) {
    memset(visit, 0, sizeof(visit));
    for (int i = 1; i < n; i++) {
      search(0, i);
      search(1, i);
    }
  }
  for (int i = 0; i < 2; i++) {
    for (int j = 1; j < n; j++)
      if (j == 1)
        printf("%s", str[dp[i][j]]);
      else
        printf(" %s", str[dp[i][j]]);
    printf("\n");
  }
  return 0;
}
