#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = 1ll << 60;
const double Inf = 1e20;
const double eps = 1e-9;
void gmax(int &a, int b) { a = (a > b ? a : b); }
void gmin(int &a, int b) { a = (a < b ? a : b); }
const int maxn = 500050;
char op[maxn][2];
int constant[maxn];
int n, final[10], x, y;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%s%d", op[i], &constant[i]);
  for (int i = 0; i <= 9; ++i) {
    x = 0;
    y = (1 << i);
    for (int i = 1; i <= n; ++i) {
      if (op[i][0] == '|') {
        x |= constant[i];
        y |= constant[i];
      }
      if (op[i][0] == '&') {
        x &= constant[i];
        y &= constant[i];
      }
      if (op[i][0] == '^') {
        x ^= constant[i];
        y ^= constant[i];
      }
    }
    x &= (1 << i);
    y &= (1 << i);
    if (x != 0 && y != 0)
      final[i] = 1;
    else if (x == 0 && y == 0)
      final[i] = 2;
    else if (x != 0 && y == 0)
      final[i] = 3;
    else
      final[i] = 4;
  }
  printf("3\n");
  int x = (1 << 10) - 1;
  for (int i = 0; i <= 9; ++i)
    if (final[i] == 2) x -= (1 << i);
  printf("& %d\n", x);
  x = 0;
  for (int i = 0; i <= 9; ++i)
    if (final[i] == 3) x += (1 << i);
  x = 0;
  printf("^ %d\n", x);
  x = 0;
  for (int i = 0; i <= 9; ++i)
    if (final[i] == 1) x += (1 << i);
  printf("| %d\n", x);
  return 0;
}
