#include <bits/stdc++.h>
using namespace std;
char m[55][55];
int a, b, c, d;
int main() {
  scanf("%d%d%d%d", &a, &b, &c, &d);
  for (int i = 0; i < 25; ++i)
    for (int j = 0; j < 25; ++j) m[i][j] = 'A';
  for (int i = 0; i < 25; ++i)
    for (int j = 25; j < 50; ++j) m[i][j] = 'B';
  for (int i = 25; i < 50; ++i)
    for (int j = 0; j < 25; ++j) m[i][j] = 'C';
  for (int i = 25; i < 50; ++i)
    for (int j = 25; j < 50; ++j) m[i][j] = 'D';
  a--;
  b--;
  c--;
  d--;
  int sy = 0;
  while (a--) {
    m[(sy / 25) * 2 + 25][sy % 25 + 25] = 'A';
    sy += 2;
  }
  sy = 0;
  while (b--) {
    m[(sy / 25) * 2 + 25][sy % 25] = 'B';
    sy += 2;
  }
  sy = 0;
  while (c--) {
    m[(sy / 25) * 2][sy % 15 + 25] = 'C';
    sy += 2;
  }
  sy = 0;
  while (d--) {
    m[(sy / 25) * 2][sy % 25] = 'D';
    sy += 2;
  }
  printf("50 50\n");
  for (int i = 0; i < 50; ++i) {
    for (int j = 0; j < 50; ++j) {
      putchar(m[i][j]);
    }
    putchar('\n');
  }
  return 0;
}
