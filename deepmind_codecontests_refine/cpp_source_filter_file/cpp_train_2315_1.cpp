#include <bits/stdc++.h>
using namespace std;
char s[1100000];
int p[1100000][2];
char last[1100000][2];
bool choose[1100000][2];
int i, j, n, m;
int mymin(int a, int b) { return a < b ? a : b; }
int enc(int a, int b) { return a * 4 + b; }
int main() {
  scanf("%s", &s[1]);
  s[0] = '0';
  n = strlen(s);
  p[n][1] = n + 1;
  p[n][0] = 0;
  for (i = n - 1; i >= 0; i--) {
    if (s[i] == '1') {
      p[i][0] = n + 1;
      if (p[i + 1][0] + 1 < p[i][0]) {
        p[i][0] = p[i + 1][0] + 1;
        last[i][0] = 1;
        choose[i][0] = 0;
      }
      p[i][1] = n + 1;
      if (p[i + 1][1] < p[i + 1][0] + 1) {
        p[i][1] = p[i + 1][1];
        last[i][1] = 0;
        choose[i][1] = 1;
      } else {
        p[i][1] = p[i + 1][0] + 1;
        last[i][1] = -1;
        choose[i][1] = 0;
      }
    } else {
      if (p[i + 1][0] < p[i + 1][1] + 1) {
        p[i][0] = p[i + 1][0];
        last[i][0] = 0;
        choose[i][0] = 0;
      } else {
        p[i][0] = p[i + 1][1] + 1;
        last[i][0] = 1;
        choose[i][0] = 1;
      }
      p[i][1] = n + 1;
      if (p[i + 1][1] + 1 < p[i + 1][1]) {
        p[i][1] = p[i + 1][1] + 1;
        last[i][1] = -1;
        choose[i][1] = 1;
      }
    }
  }
  printf("%d\n", p[0][0]);
  int now = 0;
  for (i = 0; i < n; i++) {
    if (last[i][now]) {
      if (last[i][now] < 0) {
        printf("-2^");
      } else {
        printf("+2^");
      }
      printf("%d\n", n - i - 1);
    }
    now = choose[i][now];
  }
  return 0;
}
