#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
const int INF = 1e9 + 5;
char mat[MAXN][MAXN];
int dp[MAXN][MAXN];
pair<int, int> P[MAXN][MAXN];
bool done[MAXN][MAXN];
const int X[] = {0, 1};
const int Y[] = {1, 0};
struct node {
  int x, y;
  char c;
  bool operator<(const node &o) const { return o.c < c; }
};
int main() {
  for (int i = 0; i < int(MAXN); i++)
    for (int j = 0; j < int(MAXN); j++) dp[i][j] = INF;
  int n, k;
  cin >> n >> k;
  scanf("%d %d ", &n, &k);
  for (int i = 0; i < int(n); i++) {
    for (int j = 0; j < int(n); j++) scanf("%c", &mat[i + 1][j + 1]);
    getchar();
  }
  n++;
  dp[1][0] = dp[0][1] = 0;
  for (int i = int(1); i < int(n); i++)
    for (int j = int(1); j < int(n); j++)
      dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + (mat[i][j] != 'a');
  vector<pair<int, int> > inds;
  int indS = 0;
  int maxi = 0;
  for (int i = int(1); i < int(n); i++)
    for (int j = int(1); j < int(n); j++)
      if ((dp[i][j] > maxi or (dp[i][j] == maxi and (i + j - 1) >= indS)) and
          dp[i][j] <= k) {
        if ((dp[i][j] > maxi) or ((i + j - 1) > indS)) inds.clear();
        maxi = max(maxi, dp[i][j]);
        inds.push_back({j, i});
        indS = i + j - 1;
      }
  string rta;
  rta += string(indS, 'a');
  queue<node> Q;
  priority_queue<node> toProcesar;
  for (auto &i : inds) Q.push({i.first, i.second, 'a'});
  if (inds.empty()) {
    Q.push({1, 1, mat[1][1]});
    rta += mat[1][1];
  }
  while (not Q.empty() or not toProcesar.empty()) {
    while (not Q.empty()) {
      auto e = Q.front();
      Q.pop();
      for (int i = 0; i < int(2); i++) {
        int tX = e.x + X[i], tY = e.y + Y[i];
        if (tX >= n or tY >= n) continue;
        if (done[tX][tY]) continue;
        done[tX][tY] = true;
        toProcesar.push({tX, tY, mat[tY][tX]});
      }
    }
    if (toProcesar.empty()) break;
    char myC = toProcesar.top().c;
    rta += myC;
    while (not toProcesar.empty()) {
      if (toProcesar.top().c == myC) Q.push(toProcesar.top());
      toProcesar.pop();
    }
  }
  if (dp[n - 1][n - 1] <= k) {
    for (int i = int(1); i < int(2 * (n - 1)); i++) putchar('a');
    return 0;
  }
  printf("%s", rta.c_str());
  return 0;
}
