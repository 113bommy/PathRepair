#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2050;
struct ppp {
  long long val;
  int cs, ps;
} P[MAX_N][MAX_N];
long long a[MAX_N * 100];
int main() {
  int N, tt, px, py, fx, fy;
  long long mid;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf("%lld", &P[i][j].val);
  memset(a, 0, sizeof(a));
  tt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; i + j < N; j++) {
      P[j][i + j].cs = tt;
      a[tt] += P[j][i + j].val;
    }
    tt++;
    if (i == 0) continue;
    for (int j = 0; i + j < N; j++) {
      P[i + j][j].cs = tt;
      a[tt] += P[i + j][j].val;
    }
    tt++;
  }
  for (int i = N - 1; i >= 0; i--) {
    for (int j = 0; i - j >= 0; j++) {
      P[j][i - j].ps = tt;
      a[tt] += P[j][i - j].val;
    }
    tt++;
    if (i == N - 1) continue;
    for (int j = 0; N - 1 - i + j < N; j++) {
      P[N - 1 - i + j][N - 1 - j].ps = tt;
      a[tt] += P[N - 1 - i + j][N - 1 - j].val;
    }
    tt++;
  }
  px = py = -1;
  fx = fy = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((i + j) % 2 == 0) continue;
      if (px == -1 || py == -1) {
        px = i;
        py = j;
      } else if (a[P[i][j].cs] + a[P[i][j].ps] - P[i][j].val >
                 a[P[px][py].cs] + a[P[px][py].ps] - P[px][py].val) {
        px = i;
        py = j;
      }
    }
  }
  mid = a[P[px][py].cs] + a[P[px][py].ps] - P[px][py].val;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if ((i + j) % 2 != 0) continue;
      if (fx == -1 || fy == -1) {
        fx = i;
        fy = j;
      } else if (a[P[i][j].cs] + a[P[i][j].ps] - P[i][j].val >
                 a[P[fx][fy].cs] + a[P[fx][fy].ps] - P[fx][fy].val) {
        fx = i;
        fy = j;
      }
    }
  }
  mid += a[P[fx][fy].cs] + a[P[fx][fy].ps] - P[fx][fy].val;
  if (mid == 0) {
    printf("%lld\n", mid);
    printf("%d %d %d %d\n", 1, 1, 1, 2);
  } else {
    printf("%lld\n", mid);
    printf("%d %d %d %d\n", px + 1, py + 1, fx + 1, fy + 1);
  }
  return 0;
}
