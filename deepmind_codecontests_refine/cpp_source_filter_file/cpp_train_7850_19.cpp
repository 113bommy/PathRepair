#include <bits/stdc++.h>
using namespace std;
int k, cnt, point, g;
int q[10000], v[5100][5100], a[1000];
int main() {
  scanf("%d", &k);
  for (; k; k /= 2) a[++g] = k & 1;
  point = 2;
  v[1][2 + g] = v[2 + g][1] = 1;
  int now1 = 2 + g, now2 = 2 + g;
  for (int i = 1; i < g; ++i) {
    ++point;
    v[point][now1] = v[now1][point] = v[now1][point + g] = v[point + g][now1] =
        1;
    v[point + g][now2] = v[now2][point + g] = v[point][now2] = v[now2][point] =
        1;
    now1 = point, now2 = point + g;
  }
  v[now1][2] = v[2][now1] = v[now2][2] = v[2][now2] = 1;
  point += g - 1;
  int now = 1;
  for (int i = g - 1; i >= 1; --i) {
    ++point;
    v[point][now] = v[now][point] = 1;
    now = point;
    if (a[i]) v[2 + g - i][point] = v[point][2 + g - i] = 1;
  }
  printf("%d\n", point);
  for (int i = 1; i <= point; ++i, printf("\n"))
    for (int j = 1; j <= point; ++j) printf("%c", v[i][j] ? 'Y' : 'N');
}
