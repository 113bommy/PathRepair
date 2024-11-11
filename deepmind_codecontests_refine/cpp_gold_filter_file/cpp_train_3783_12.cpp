#include <bits/stdc++.h>
using namespace std;
const int MaxN = 505;
int sum[MaxN][MaxN];
int num[MaxN][MaxN];
int temp[MaxN][MaxN];
int ans[MaxN][MaxN];
int getsum(int l1, int r1, int l2, int r2) {
  int x1 = min(l1, l2);
  int x2 = max(l1, l2);
  int y1 = min(r1, r2);
  int y2 = max(r1, r2);
  x1--, y1--;
  return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}
int main() {
  int N, M;
  scanf("%d%d", &N, &M);
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      scanf("%d", &num[i][j]);
    }
  }
  for (int i = 1; i <= N; ++i) {
    for (int j = 1; j <= M; ++j) {
      sum[i][j] = num[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
  }
  int daan = -2000000000;
  for (int i = 1; i <= N - 2; ++i) {
    for (int j = 1; j <= M - 2; ++j) {
      ans[i][j] = getsum(i, j, i, j + 2) + num[i + 1][j + 2] +
                  getsum(i + 2, j, i + 2, j + 2);
    }
  }
  for (int i = 1; i <= N - 2; ++i) {
    for (int j = 1; j <= M - 2; ++j) {
      temp[i][j] = ans[i][j];
      daan = max(daan, temp[i][j]);
    }
  }
  for (int len = 5; len <= min(N, M); len += 2) {
    for (int i = 1; i <= N - len + 1; ++i) {
      for (int j = 1; j <= M - len + 1; ++j) {
        int x1, y1, x2, y2;
        ans[i][j] =
            getsum(i + 1, j + 1, i + len - 2, j + len - 2) - temp[i + 1][j + 1];
        ans[i][j] += getsum(i + 2, j, i + len - 1, j) +
                     getsum(i + len - 1, j + 1, i + len - 1, j + len - 1) +
                     getsum(i, j + len - 1, i + len - 2, j + len - 1) +
                     getsum(i, j, i, j + len - 2);
      }
    }
    for (int i = 1; i <= N - len + 1; ++i)
      for (int j = 1; j <= M - len + 1; ++j) {
        temp[i][j] = ans[i][j];
        daan = max(daan, temp[i][j]);
      }
  }
  cout << daan << endl;
}
