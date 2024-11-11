#include <bits/stdc++.h>
using namespace std;
const int MaxN = 105;
int matrix[MaxN][MaxN];
int flag[MaxN];
int pre[MaxN];
int N, M;
int dfs(int x, int tag) {
  if (pre[x] != -1) {
    return pre[x] == tag;
  }
  pre[x] = tag;
  for (int i = 1; i <= N; ++i) {
    if (matrix[x][i] != -1) {
      if (!dfs(i, tag ^ matrix[x][i])) return 0;
    }
  }
  return 1;
}
int main() {
  scanf("%d%d", &N, &M);
  memset(matrix, -1, sizeof(matrix));
  memset(flag, -1, sizeof(flag));
  for (int i = 0; i < M; ++i) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    matrix[a][b] = matrix[b][a] = c ^ 1;
  }
  int F = 1;
  for (int i = 1; i <= N; ++i) {
    if (flag[i] == -1) {
      memset(pre, -1, sizeof(pre));
      if (dfs(i, 0)) {
        for (int j = 1; j <= N; ++j) {
          if (flag[j] == -1 && pre[j] != -1) {
            flag[j] = pre[j];
          }
        }
        continue;
      }
      memset(pre, -1, sizeof(pre));
      if (dfs(i, 1)) {
        for (int j = 1; j <= N; ++j) {
          if (flag[j] == -1 && pre[j] != -1) {
            flag[j] = pre[j];
          }
        }
        continue;
      }
      F = 0;
      break;
    }
  }
  if (!F)
    puts("Impossible");
  else {
    int sum = 0;
    for (int i = 1; i <= N; ++i)
      if (flag[i] == 1) sum++;
    printf("%d\n", sum);
    for (int i = 1; i <= N; ++i)
      if (flag[i] == 1) printf("%d ", i);
    puts("");
  }
}
