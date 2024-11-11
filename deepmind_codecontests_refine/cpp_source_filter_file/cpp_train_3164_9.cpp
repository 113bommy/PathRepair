#include <bits/stdc++.h>
using namespace std;
const int inf = 2147483647;
char s1[1005][1005], s2[1005][1005];
int color[1005][1005];
int h, w, k, reversed = 0, E = 0;
void init() {
  int i, j;
  scanf("%d%d%d\n", &h, &w, &k);
  if (w * (h - 1) > (w - 1) * h && k > 1) reversed = 1;
  for (i = 1; i <= h; ++i) {
    for (j = 1; j <= w - 1; ++j) {
      if (reversed) {
        s2[j][i] = getchar();
      } else {
        s1[i][j] = getchar();
        if (s1[i][j] == 'E') E++;
      }
    }
    getchar();
    if (i == h) continue;
    for (j = 1; j <= w; ++j) {
      if (reversed) {
        s1[j][i] = getchar();
      } else {
        s2[i][j] = getchar();
        if (s2[i][j] == 'E') E++;
      }
    }
    getchar();
  }
  if (reversed) swap(w, h);
}
void work() {
  int i, j, tmp, num = w * (h - 1) + h * (w - 1);
  if (k == 1) {
    if (E * 4 >= 3 * num) {
      puts("YES");
      for (i = 1; i <= h; ++i) {
        for (j = 1; j <= w; ++j) {
          printf("1 ");
        }
        printf("\n");
      }
    } else {
      puts("NO");
    }
  } else {
    puts("YES");
    for (i = 1; i <= h; ++i) {
      for (j = 1; j <= w; ++j) {
        if (j == 1) {
          color[i][j] = 1;
        } else {
          color[i][j] =
              s1[i][j - 1] == 'E' ? color[i][j - 1] : 3 - color[i][j - 1];
        }
      }
      if (i == 1) continue;
      tmp = 0;
      for (j = 1; j <= w; ++j) {
        if (s2[i - 1][j] == 'E')
          tmp += (color[i][j] == color[i - 1][j]);
        else
          tmp += (color[i][j] != color[i][j]);
      }
      if (tmp * 2 < w) {
        for (j = 1; j <= w; ++j) color[i][j] = 3 - color[i][j];
      }
    }
    if (reversed) {
      for (j = 1; j <= w; ++j) {
        for (i = 1; i <= h; ++i) {
          printf("%d ", color[i][j]);
        }
        printf("\n");
      }
    } else {
      for (i = 1; i <= h; ++i) {
        for (j = 1; j <= w; ++j) {
          printf("%d ", color[i][j]);
        }
        printf("\n");
      }
    }
  }
}
int main() {
  init();
  work();
}
