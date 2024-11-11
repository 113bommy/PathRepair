#include <bits/stdc++.h>
using namespace std;
int N;
char c[3000][3000];
int color[3000][3000];
int row[3000];
int col[3000];
int main() {
  scanf("%d", &N);
  for (int Ni = 0; Ni < N; Ni++) scanf("%s", c[Ni]);
  for (int Ni = 0; Ni < N; Ni++)
    for (int Nj = 0; Nj < N; Nj++) color[Ni][Nj] = c[Ni][Nj] - '0';
  int cnt = 0;
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  for (int i = N - 1; i >= 0; i--)
    for (int j = 0; j < i; j++)
      if ((row[i] + col[j]) % 2 != color[i][j]) {
        cnt++;
        row[i]++;
        col[j]++;
      }
  int p[3000];
  for (int Ni = 0; Ni < N; Ni++) p[Ni] = (row[Ni] + col[Ni]) / 2;
  memset(row, 0, sizeof(row));
  memset(col, 0, sizeof(col));
  for (int i = 0; i < N; i++)
    for (int j = N - 1; j > i; j--)
      if ((row[i] + col[j]) % 2 != color[i][j]) {
        cnt++;
        row[i]++;
        col[j]++;
      }
  for (int Ni = 0; Ni < N; Ni++) {
    p[Ni] = (p[Ni] + row[Ni] + col[Ni]) / 2;
    if (p[Ni] != color[Ni][Ni]) cnt++;
  }
  printf("%d", cnt);
  puts("");
}
