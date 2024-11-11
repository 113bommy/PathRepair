#include <bits/stdc++.h>
using namespace std;
int const N = 1 << 10;
bool e[N][N];
int main() {
  int k, d, c = 2, S = 0, T = 1;
  scanf("%d", &k);
  for (d = 30; d >= 0 && !(k & 1 << d); --d)
    ;
  e[S][c] = e[c][S] = true;
  for (int i = 0; i < d; ++i) {
    e[c][c + 1] = e[c + 1][c] = true;
    e[c][c + 2] = e[c + 2][c] = true;
    e[c + 1][c + 3] = e[c + 3][c + 1] = true;
    e[c + 2][c + 3] = e[c + 3][c + 2] = true;
    c += 3;
  }
  e[T][c] = e[c][T] = true;
  ++c;
  for (int i = 0; i < d; ++i)
    if (k & 1 << i) {
      int st = 3 * i + 2;
      e[st][c] = e[c][st] = true;
      e[c][c + 1] = e[c + 1][c] = true;
      ++c;
      for (int j = i + 1; j < d; ++j) {
        e[c][c + 1] = e[c + 1][c] = true;
        e[c + 1][c + 2] = e[c + 2][c + 1] = true;
        c += 2;
      }
      e[T][c] = e[c][T] = true;
      ++c;
    }
  printf("%d\n", c);
  for (int i = 0; i <= c; ++i) {
    for (int j = 0; j <= c; ++j) printf("%c", e[i][j] ? 'Y' : 'N');
    puts("");
  }
  return 0;
}
