#include <bits/stdc++.h>
using namespace std;
const int maxn = 201000;
const int INF = 0x3f3f3f3f;
const int alt[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 2, 0},
                       {1, 0, 2}, {2, 0, 1}, {2, 1, 0}};
int n;
char s[maxn], a[maxn];
int id(char c) {
  if (c == 'R')
    return 0;
  else if (c == 'G')
    return 1;
  else
    return 2;
}
int main() {
  while (scanf("%d", &n) != EOF) {
    getchar();
    scanf("%s", s);
    int ans = INF, y = -1;
    for (int i = 0; i < 6; i++) {
      int a = 0;
      for (int j = 0; j < min(3, n); j++)
        if (id(s[j]) != alt[i][j]) a++;
      for (int j = 3; j < n; j++) {
        if (id(s[j]) != alt[i][j]) a++;
      }
      if (a < ans) {
        ans = a;
        y = i;
      }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
      if (alt[y][i % 3] == 0)
        printf("R");
      else if (alt[y][i % 3] == 1)
        printf("G");
      else
        printf("B");
    }
    printf("\n");
  }
}
