#include <bits/stdc++.h>
using namespace std;
char G[105][105];
int farmer[105][105];
int value[66];
int r, c, k;
int main() {
  int t;
  int color = 0;
  for (int i = 'a'; i <= 'z'; i++) value[color++] = i;
  for (int i = 'A'; i <= 'Z'; i++) value[color++] = i;
  for (int i = '0'; i <= '9'; i++) value[color++] = i;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &r, &c, &k);
    int sum = 0;
    for (int i = 0; i < r; i++) {
      scanf("%s", G[i]);
      for (int j = 0; j < c; j++) {
        if (G[i][j] == 'R') sum++;
      }
    }
    int cnt = sum / k;
    int rem = sum % k;
    int aa = cnt;
    if (rem) {
      aa++;
      rem--;
    }
    color = 0;
    for (int i = 0; i < r; i++) {
      if (i % 2) {
        for (int j = c - 1; j >= 0; j--) {
          farmer[i][j] = color;
          if (G[i][j] == 'R') {
            aa--;
            if (aa == 0) {
              if (color != k) color++;
              aa = cnt;
              if (rem) {
                aa++;
                rem--;
              }
            }
          }
        }
      } else {
        for (int j = 0; j < c; j++) {
          farmer[i][j] = color;
          if (G[i][j] == 'R') {
            aa--;
            if (aa == 0) {
              if (color != k) color++;
              aa = cnt;
              if (rem) {
                aa++;
                rem--;
              }
            }
          }
        }
      }
    }
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) printf("%c", value[farmer[i][j]]);
      printf("\n");
    }
  }
  return 0;
}
