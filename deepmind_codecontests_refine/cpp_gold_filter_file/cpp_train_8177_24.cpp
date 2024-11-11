#include <bits/stdc++.h>
using namespace std;
int const N = 3333;
int const Q = 500500;
int const len = 10400400;
int const SHIFT = 5;
int const AND = (1 << SHIFT) - 1;
char input[len];
char ans[len];
int cur = 0;
int ne() {
  while (input[cur] < 33) ++cur;
  int ret = 0;
  while (input[cur] > 32) ret = 10 * ret + input[cur++] - '0';
  return ret;
}
unsigned int a[N][N];
unsigned int inf[N][N];
int x[Q], y[Q];
int main() {
  fread(input, 1, len, stdin);
  int n = ne(), m = ne();
  for (int i = 0; i < m; ++i) {
    x[i] = ne() - 1;
    y[i] = ne() - 1;
    a[x[i]][y[i] >> SHIFT] |= (1ull << (y[i] & AND));
  }
  for (int i = 0; i < n; ++i) {
    inf[i][i >> SHIFT] = 1ull << (i & AND);
  }
  int cnt = (n + AND) >> SHIFT;
  for (int i = 0; i < n; ++i) {
    int row = -1;
    for (int r = i; r < n; ++r) {
      if (a[r][i >> SHIFT] & (1ull << (i & AND))) {
        row = r;
        break;
      }
    }
    if (i != row) {
      for (int x = 0; x < cnt; ++x) {
        swap(a[i][x], a[row][x]);
        swap(inf[i][x], inf[row][x]);
      }
    }
    for (int r = 0; r < n; ++r) {
      if (r != i && (a[r][i >> SHIFT] & (1ull << (i & AND)))) {
        for (int x = 0; x < cnt; ++x) {
          a[r][x] ^= a[i][x];
          inf[r][x] ^= inf[i][x];
        }
      }
    }
  }
  int len = 0;
  for (int i = 0; i < m; ++i) {
    auto no = inf[y[i]][x[i] >> SHIFT] & (1ull << (x[i] & AND));
    if (no) {
      ans[++len] = 'N';
      ans[++len] = 'O';
    } else {
      ans[++len] = 'Y';
      ans[++len] = 'E';
      ans[++len] = 'S';
    }
    ans[++len] = '\n';
  }
  fwrite(ans + 1, 1, len, stdout);
}
