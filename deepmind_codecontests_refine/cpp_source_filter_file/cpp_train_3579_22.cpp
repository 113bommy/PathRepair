#include <bits/stdc++.h>
using namespace std;
const int MAXN = 310;
bool dp3[MAXN][MAXN][MAXN];
bool dp2[MAXN][MAXN];
bool solve2(vector<int> a) {
  int M = a[1];
  for (int i = 0; i < M; ++i)
    for (int j = i; j < M; ++j)
      if (!dp2[i][j]) {
        for (int k = 1; k + i <= M; ++k) {
          dp2[i + k][j] = dp2[j][i + k] = 1;
          if (j + k <= M) dp2[i][j + k] = dp2[i + k][j + k] = 1;
        }
      }
  return dp2[a[0]][a[1]];
}
bool solve3(vector<int> a) {
  int M = a[2];
  for (int i = 0; i < M; ++i)
    for (int j = i; j < M; ++j)
      for (int k = j; k <= M; ++k)
        if (!dp3[i][j][k]) {
          for (int l = 1; l + i <= M; ++l) {
            dp3[i + l][j][k] = dp3[j][i + l][k] = dp3[j][k][i + l] = 1;
            if (j + l <= M) dp3[i][j + l][k] = dp3[i][k][j + l] = 1;
            if (k + l <= M) dp3[i][j][k + l] = dp3[i + l][j + l][k + l] = 1;
          }
        }
  return dp3[a[0]][a[1]][a[2]];
}
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  bool flag = 1;
  if (N == 2)
    flag = solve2(a);
  else if (N == 3)
    flag = solve3(a);
  puts(flag ? "BitLGM" : "BitAryo");
  return 0;
}
