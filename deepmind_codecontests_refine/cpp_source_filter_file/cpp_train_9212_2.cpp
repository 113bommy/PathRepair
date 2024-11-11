#include <bits/stdc++.h>
using namespace std;
const long long base = (long long)1e17;
const int N = 1e5 + 100;
const int mod = 1e9 + 7;
const long long tbase = base % mod;
inline void read(int& n) {
  n = 0;
  int ch = getchar();
  while (!isdigit(ch)) ch = getchar();
  while (isdigit(ch)) n = n * 10 + ch - '0', ch = getchar();
}
int x[3][2];
int main() {
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 2; j++) scanf("%d", &x[i][j]);
  bool flag = false;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        if (x[0][i] == x[1][j] && x[1][j] == x[2][k]) {
          int wid = x[0][i];
          if (x[0][i ^ 1] + x[1][j ^ 1] + x[2][k ^ 1] != wid) continue;
          printf("%d\n", wid);
          for (int q = 0; q < x[0][i ^ 1]; q++) {
            for (int l = 0; l < wid; l++) printf("A");
            printf("\n");
          }
          for (int q = 0; q < x[1][j ^ 1]; q++) {
            for (int l = 0; l < wid; l++) printf("B");
            printf("\n");
          }
          for (int q = 0; q < x[2][k ^ 1]; q++) {
            for (int l = 0; l < wid; l++) printf("C");
            printf("\n");
          }
          return 0;
        }
      }
  for (int ii = 0; ii < 3; ii++)
    for (int jj = 0; jj < 2; jj++) {
      int wid = x[ii][jj];
      int p[2], cc = 0;
      for (int k = 0; k < 3; k++)
        if (k != ii) p[cc++] = k;
      for (int c1 = 0; c1 < 2; c1++)
        for (int c2 = 0; c2 < 2; c2++) {
          if (x[p[0]][c1] + x[p[1]][c2] == wid &&
              x[p[0]][c1 ^ 1] == x[p[1]][c2 ^ 1] &&
              x[p[0]][c1 ^ 1] + x[ii][jj] == wid) {
            printf("%d\n", wid);
            for (int i = 0; i < x[ii][jj ^ 1]; i++) {
              for (int j = 0; j < wid; j++) printf("%c", 'A' + ii);
              printf("\n");
            }
            for (int i = 0; i < x[p[0]][c1 ^ 1]; i++) {
              for (int j = 0; j < x[p[0]][c1] + x[p[1]][c2]; j++) {
                if (j < x[p[0]][c1])
                  printf("%c", 'A' + p[0]);
                else
                  printf("%c", 'A' + p[1]);
              }
              printf("\n");
            }
            return 0;
          }
        }
    }
  printf("-1\n");
  return 0;
}
