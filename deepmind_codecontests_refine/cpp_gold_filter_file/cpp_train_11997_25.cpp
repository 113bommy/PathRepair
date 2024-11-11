#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-8;
int bpr = 0, bpc = 0, dp = 1, cp = -1, cpp = 0;
int r[20005] = {0};
int c[20005] = {0};
int record[55][55][4][2];
char arr[55][55];
int curr = 0, curc = 0;
int cnt = 0;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int m, N, n;
void getNext() {
  int clr = arr[curr][curc];
  for (;
       curr >= 0 && curr < m && curc >= 0 && curc < N && arr[curr][curc] == clr;
       curr += dr[dp], curc += dc[dp])
    ;
  curr -= dr[dp];
  curc -= dc[dp];
  for (;
       curr >= 0 && curr < m && curc >= 0 && curc < N && arr[curr][curc] == clr;
       curr += dr[cpp], curc += dc[cpp])
    ;
  curr -= dr[cpp];
  curc -= dc[cpp];
  int nr = curr + dr[dp];
  int nc = curc + dc[dp];
  if (nr < 0 || nr >= m || nc < 0 || nc >= N || arr[nr][nc] == '0') {
    if (cp == -1)
      cp = 1;
    else {
      cp = -1;
      dp = (dp + 1) % 4;
    }
  } else {
    curr = nr;
    curc = nc;
  }
  cpp = (dp + cp + 4) % 4;
}
int main(int argc, char *argv[]) {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < m; ++i) {
    scanf("%s", arr[i]);
    N = strlen(arr[i]);
  }
  int i;
  for (i = 1; i <= n; ++i) {
    getNext();
    if (record[curr][curc][dp][cpp]) {
      ++cnt;
      break;
    }
    record[curr][curc][dp][cpp] = ++cnt;
    r[cnt - 1] = curr;
    c[cnt - 1] = curc;
  }
  int first = 0;
  if (i != n + 1) {
    cnt = cnt - record[curr][curc][dp][cpp];
    first = record[curr][curc][dp][cpp];
    n = (n - first) % cnt + first - 1;
  } else
    n = n - 1;
  printf("%c\n", arr[r[n]][c[n]]);
  return 0;
}
