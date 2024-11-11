#include <bits/stdc++.h>
using namespace std;
const int N = 105;
const int MEX = 300;
int r, n;
int rowPos[N];
int dp[N][N];
int grundy(int a, int b) {
  if (a < 0) a = 0;
  if (b < 0) b = 0;
  if (a < b) swap(a, b);
  int &res = dp[a][b];
  if (res != -1) return res;
  vector<char> mex(MEX);
  if (a == r && b == r) {
    for (int i = 0; i < r; i++) {
      int v1 = grundy(i, i - 1);
      int v2 = grundy(r - i - 1, r - i - 2);
      int locXor = (v1 ^ v2);
      mex[locXor] = 1;
    }
  } else {
    for (int i = 0; i < a; i++) {
      int v1 = grundy(i, i - 2);
      int v2 = grundy(a - i - 1, b - i - 2);
      int locXor = (v1 ^ v2);
      mex[locXor] = 1;
    }
    for (int i = 0; i < b; i++) {
      int v1 = grundy(i, i);
      int v2 = grundy(a - i - 2, b - i - 1);
      int locXor = (v1 ^ v2);
      mex[locXor] = 1;
    }
  }
  for (int i = 0; i < MEX; i++)
    if (!mex[i]) {
      res = i;
      return i;
    }
  throw;
}
int main() {
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) dp[i][j] = -1;
  for (int i = 0; i < N; i++) rowPos[i] = -1;
  scanf("%d%d", &r, &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    rowPos[x] = y;
  }
  int xorSum = 0;
  int pos = -1;
  for (int i = 0; i <= r; i++)
    if (i == r || rowPos[i] != -1) {
      int a = i - pos - 1;
      int b = a;
      if (pos != -1 && rowPos[pos] == 1) a--;
      if (pos != -1 && rowPos[pos] == 0) b--;
      if (i != r && rowPos[i] == 1) a--;
      if (i != r && rowPos[i] == 0) b--;
      xorSum ^= grundy(a, b);
      pos = i;
    }
  if (xorSum == 0)
    printf("LOSE");
  else
    printf("WIN");
  return 0;
}
