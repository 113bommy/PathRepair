#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
const int yon[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int N, M;
char ar[MAXN][MAXN];
bool used[MAXN][MAXN];
bool used2[MAXN][MAXN];
vector<pair<int, int> > vec;
int main() {
  scanf(" %d %d", &N, &M);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      scanf(" %c", &ar[i][j]);
      if (ar[i][j] == 'B') vec.push_back(pair<int, int>(i, j));
    }
  for (int i = 0; i < (int)vec.size() - 1; i++) {
    for (int j = 0; j <= M; j++) {
      if (ar[vec[i].first][vec[i].second + j] == 'B')
        used[vec[i].first][vec[i].second + j] = 1;
      else
        break;
    }
    for (int j = 0; j <= vec[i].second; j++) {
      if (ar[vec[i].first][vec[i].second - j] == 'B')
        used[vec[i].first][vec[i].second - j] = 1;
      else
        break;
    }
    for (int j = 0; j <= N; j++) {
      if (ar[vec[i].first + j][vec[i].second] == 'B')
        used[vec[i].first + j][vec[i].second] = 1;
      else
        break;
    }
    for (int j = 0; j <= vec[i].first; j++) {
      if (ar[vec[i].first - j][vec[i].second] == 'B')
        used[vec[i].first - j][vec[i].second] = 1;
      else
        break;
    }
    for (int j = 1; j <= N; j++)
      for (int k = 1; k <= M; k++)
        if (used[j][k] == 1) {
          for (int l = 0; l <= M; l++) {
            if (ar[j][k + l] == 'B')
              used2[j][k + l] = 1;
            else
              break;
          }
          for (int l = 0; l <= k; l++) {
            if (ar[j][k - l] == 'B')
              used2[j][k - l] = 1;
            else
              break;
          }
          for (int l = 0; l <= N; l++) {
            if (ar[j + l][k] == 'B')
              used2[j + l][k] = 1;
            else
              break;
          }
          for (int l = 0; l <= j; l++) {
            if (ar[j - l][k] == 'B')
              used2[j - l][k] = 1;
            else
              break;
          }
        }
    for (int j = 0; j < (int)vec.size(); j++)
      if (!used[vec[j].first][vec[j].second] &&
          !used2[vec[j].first][vec[j].second]) {
        printf("NO\n");
        return 0;
      }
    memset(used, 0, sizeof used);
    memset(used2, 0, sizeof used2);
  }
  printf("YES\n");
  return 0;
}
