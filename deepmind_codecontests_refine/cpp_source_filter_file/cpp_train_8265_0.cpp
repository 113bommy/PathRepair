#include <bits/stdc++.h>
char map[9][9];
typedef struct {
  int x;
  int y;
} location;
location loc[2];
int k = 0;
int abs(int a) { return (a > 0 ? a : -a); }
int main() {
  int n;
  scanf("%d", &n);
  while (n--) {
    k = 0;
    for (int i = 0; i < 8; i++) {
      scanf("%s", map[i]);
      for (int j = 0; j < 8; ++j) {
        if (map[i][j] == 'K') {
          loc[k].x = i;
          loc[k].y = j;
          map[i][j] = '.';
          k++;
        }
      }
    }
    if (abs(loc[0].x - loc[1].x) % 4 == 0 && abs(loc[0].y - loc[1].y) % 4 == 0)
      printf("YES");
    else
      printf("NO");
  }
  return 0;
}
