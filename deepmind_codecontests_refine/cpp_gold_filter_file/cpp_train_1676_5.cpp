#include <bits/stdc++.h>
using namespace std;
int x[21000];
int y[21000];
int dp[2][20005];
int save[143][20005];
int modu;
int z;
inline int f(int a, int b) { return (x[a] + y[b]) % modu; }
int n, m;
void DoSaveZ(int pos) {
  for (int(i) = 0; (i) < (m); ++(i)) save[pos][i] = dp[z][i];
}
int minidp[144][20005];
long long profit = 0LL;
void Retrieve(int candy, int stone) {
  if (candy == 0) {
    while (stone) {
      profit += f(candy, stone);
      printf("S");
      --stone;
    }
    return;
  }
  int bottom_candy = candy / 143;
  if (candy % 143 == 0) --bottom_candy;
  int botmult = bottom_candy * 143;
  int iter = candy - botmult;
  for (int(i) = 0; (i) < (144); ++(i))
    for (int(j) = 0; (j) < (20005); ++(j)) minidp[i][j] = 0LL;
  for (int(j) = 0; (j) < (m); ++(j)) minidp[0][j] = save[bottom_candy][j];
  for (int(i) = (1); (i) < (iter + 1); ++(i)) {
    minidp[i][0] = minidp[i - 1][0] + f(botmult + i, 0);
    for (int(j) = (1); (j) < (m); ++(j)) {
      minidp[i][j] =
          max(minidp[i][j - 1], minidp[i - 1][j]) + f(botmult + i, j);
    }
  }
  while (candy != botmult) {
    profit += f(candy, stone);
    if (stone == 0) {
      printf("C");
      --candy;
    } else {
      if (minidp[candy - botmult - 1][stone] >
          minidp[candy - botmult][stone - 1]) {
        printf("C");
        --candy;
      } else {
        printf("S");
        --stone;
      }
    }
  }
  Retrieve(candy, stone);
}
int main() {
  cin >> n >> m >> modu;
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> x[n - i - 1];
  }
  for (int(i) = 0; (i) < (m); ++(i)) {
    cin >> y[m - i - 1];
  }
  for (int(i) = 0; (i) < (2); ++(i))
    for (int(j) = 0; (j) < (20005); ++(j)) dp[i][j] = 0;
  z = 0;
  int last_save = 0;
  dp[z][0] = f(0, 0);
  for (int(i) = (1); (i) < (m); ++(i)) dp[z][i] = dp[z][i - 1] + f(0, i);
  DoSaveZ(0);
  if (n == 1) cout << dp[0][m - 1] << endl;
  for (int(i) = (1); (i) < (n); ++(i)) {
    int y = z ^ 1;
    for (int(j) = 0; (j) < (m); ++(j)) dp[y][j] = 0;
    dp[y][0] = dp[z][0] + f(i, 0);
    for (int(j) = (1); (j) < (m); ++(j))
      dp[y][j] = max(dp[y][j - 1], dp[z][j]) + f(i, j);
    z = y;
    if (i % 143 == 0) {
      ++last_save;
      DoSaveZ(last_save);
    }
    if (i == n - 1) {
      profit = -dp[z][m - 1];
      cout << dp[z][m - 1] << endl;
    }
  }
  Retrieve(n - 1, m - 1);
  cout << endl;
  return 0;
}
