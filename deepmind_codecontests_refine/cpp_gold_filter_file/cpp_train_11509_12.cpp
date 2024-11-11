#include <bits/stdc++.h>
using namespace std;
char board[501][501];
int ccidx[501][501];
int ccsize[250001];
int timestamp[250001];
const int dy[4] = {-1, 0, 0, 1};
const int dx[4] = {0, -1, 1, 0};
const char EMPTY = '.';
int n, k;
bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < n; }
void add(int y, int x, int &answer, int cur_time) {
  if (inRange(y, x) && board[y][x] == EMPTY) {
    int idx = ccidx[y][x];
    if (timestamp[idx] != cur_time) {
      timestamp[idx] = cur_time;
      answer += ccsize[idx];
    }
  }
}
int dfs(int y, int x, int num) {
  int ret = 1;
  if (ccidx[y][x] == 0) {
    ccidx[y][x] = num;
    for (int dir = 0; dir < 4; dir++) {
      int ny, nx;
      ny = y + dy[dir];
      nx = x + dx[dir];
      if (inRange(ny, nx) && ccidx[ny][nx] == 0 && board[ny][nx] == EMPTY)
        ret += dfs(ny, nx, num);
    }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf(" %s", board[i]);
  }
  int connected_num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ccidx[i][j] == 0 && board[i][j] == EMPTY) {
        ccsize[connected_num] = dfs(i, j, connected_num);
        connected_num++;
      }
    }
  }
  int tt = 1;
  int result = 0;
  for (int i = 0; i <= n - k; i++) {
    for (int y = i; y < i + k; y++) {
      for (int x = 0; x < k; x++) {
        --ccsize[ccidx[y][x]];
      }
    }
    for (int j = 0; j <= n - k; j++) {
      int answer = k * k;
      for (int y = i; y < i + k; y++) {
        add(y, j - 1, answer, tt);
        add(y, j + k, answer, tt);
      }
      for (int x = j; x < j + k; x++) {
        add(i - 1, x, answer, tt);
        add(i + k, x, answer, tt);
      }
      ++tt;
      result = max(answer, result);
      if (j + k != n) {
        for (int y = i; y < i + k; y++) {
          ccsize[ccidx[y][j]]++;
          ccsize[ccidx[y][j + k]]--;
        }
      }
    }
    for (int y = i; y < i + k; ++y) {
      for (int x = n - k; x < n; ++x) ++ccsize[ccidx[y][x]];
    }
  }
  printf("%d\n", result);
  return 0;
}
