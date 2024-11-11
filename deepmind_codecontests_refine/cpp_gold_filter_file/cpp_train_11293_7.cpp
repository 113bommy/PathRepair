#include <bits/stdc++.h>
using namespace std;
int n, m;
char f[100][100];
char ans1[100][100];
char ans2[200][200];
void rotate1() {
  int cx = 0;
  int cy = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (int j = 0; j < n; j++) {
      ans1[j][i] = f[cy][cx];
      cx++;
      if (cx == n) {
        cx = 0;
        cy++;
      }
    }
  }
}
void rotate2() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m / 2; j++) {
      swap(ans1[i][j], ans1[i][m - 1 - j]);
    }
  }
}
int main() {
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%c", &f[i][j]);
    }
    scanf("\n");
  }
  rotate1();
  rotate2();
  for (int i = 0; i < n * 2; i++) {
    for (int j = 0; j < m * 2; j++) {
      printf("%c", ans1[i / 2][j / 2]);
    }
    printf("\n");
  }
  return 0;
}
