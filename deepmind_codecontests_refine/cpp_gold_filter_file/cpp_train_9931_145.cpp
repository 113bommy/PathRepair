#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1600 + 3;
int h, w;
bool A[MAXN][MAXN];
bool B[MAXN][MAXN];
void add(bool A[][MAXN]) {
  static bool tmp[MAXN][MAXN];
  memcpy(tmp, A, sizeof(tmp));
  for (int i = 1; i < h - 1; i++)
    for (int j = 1; j < w - 1; j++) {
      if (A[i + 1][j] || A[i][j + 1] || A[i - 1][j] || A[i][j - 1])
        tmp[i][j] = true;
    }
  memcpy(A, tmp, sizeof(tmp));
}
void remove(bool A[][MAXN]) {
  static bool tmp[MAXN][MAXN];
  memcpy(tmp, A, sizeof(tmp));
  for (int i = 1; i < h - 1; i++)
    for (int j = 1; j < w - 1; j++) {
      if (!A[i + 1][j] || !A[i][j + 1] || !A[i - 1][j] || !A[i][j - 1])
        tmp[i][j] = false;
    }
  memcpy(A, tmp, sizeof(tmp));
}
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int solveB(int x, int y) {
  static pair<int, int> que[MAXN * MAXN];
  int low = 0, high = 0;
  que[high++] = make_pair(x, y);
  B[x][y] = false;
  while (low < high) {
    x = que[low].first, y = que[low].second;
    low++;
    for (int i = 0; i < 4; i++) {
      int p = x + dx[i], q = y + dy[i];
      if (B[p][q]) {
        B[p][q] = false;
        que[high++] = make_pair(p, q);
      }
    }
  }
  return (int)(high > 5);
}
int solveA(int x, int y) {
  static pair<int, int> que[MAXN * MAXN];
  int low = 0, high = 0;
  que[high++] = make_pair(x, y);
  A[x][y] = false;
  int ret = 0;
  while (low < high) {
    x = que[low].first, y = que[low].second;
    low++;
    for (int i = 0; i < 4; i++) {
      int p = x + dx[i], q = y + dy[i];
      if (B[p][q]) {
        ret += solveB(p, q);
      }
      if (A[p][q]) {
        A[p][q] = false;
        que[high++] = make_pair(p, q);
      }
    }
  }
  return ret;
}
int main() {
  scanf("%d%d", &h, &w);
  for (int i = 1; i <= h; i++)
    for (int j = 1; j <= w; j++) {
      int x;
      scanf("%d", &x);
      A[i][j] = x;
    }
  h += 2, w += 2;
  memcpy(B, A, sizeof(A));
  for (int i = 0; i < 4; i++) remove(A);
  for (int i = 0; i < 8; i++) add(A);
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (A[i][j]) B[i][j] = false;
  int cntAns = 0;
  static int ans[10000];
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
      if (A[i][j]) {
        ans[cntAns++] = solveA(i, j);
      }
  printf("%d\n", cntAns);
  sort(ans, ans + cntAns);
  for (int i = 0; i < cntAns; i++) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
