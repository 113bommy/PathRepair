#include <bits/stdc++.h>
using namespace std;
int n;
int up[1010];
int down[1010];
char graphic[1010][1010];
int main() {
  memset(graphic, 0, sizeof(graphic));
  cin >> n;
  int cur = 1000;
  int h = 1000, hh = 1000;
  for (int i = 1; i <= n; i++) {
    int ai;
    scanf("%d", &ai);
    if (i % 2) {
      down[i] = cur;
      up[i] = cur - ai + 1;
      cur = up[i];
      if (cur < h) h = cur;
    } else {
      up[i] = cur;
      down[i] = cur + ai - 1;
      cur = down[i];
      if (cur > hh) hh = cur;
    }
  }
  for (int i = 1; i <= n; i++) {
    up[i] -= h;
    down[i] -= h;
  }
  int k = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2) {
      for (int j = down[i]; j >= up[i]; j--) {
        graphic[j][k] = '/';
        k++;
      }
    } else {
      for (int j = up[i]; j <= down[i]; j++) {
        graphic[j][k] = '\\';
        k++;
      }
    }
  }
  for (int i = 0; i <= hh - h; i++) {
    for (int j = 0; j < k; j++) {
      if (graphic[i][j]) {
        printf("%c", graphic[i][j]);
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}
