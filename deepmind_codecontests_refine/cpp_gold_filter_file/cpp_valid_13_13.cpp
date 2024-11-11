#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int n, m, sk;
void into() { scanf("%d%d%d", &n, &m, &sk); }
int ans0, ans[N + 9][N + 9];
void Get_ans(int n, int m) {
  ans0 = 0;
  if (n & 1) {
    for (int i = 0; i < m >> 1; ++i)
      ans[n - 1][i << 1] = ans[n - 1][i << 1 | 1] = 8 | i & 1;
    sk -= m >> 1;
    --n;
  }
  if (m & 1) {
    for (int i = 0; i < n >> 1; ++i)
      ans[i << 1][m - 1] = ans[i << 1 | 1][m - 1] = 8 | i & 1;
    --m;
  }
  if (sk < 0) return;
  if (sk > n * m >> 1) return;
  if (sk & 1) return;
  ans0 = 1;
  for (int i = 0; i < n >> 1; ++i)
    for (int j = 0; j < m >> 1; ++j) {
      if (sk) {
        ans[i << 1][j << 1] = ans[i << 1][j << 1 | 1] = (i & 1) << 2 | (j & 1)
                                                                           << 1;
        ans[i << 1 | 1][j << 1] = ans[i << 1 | 1][j << 1 | 1] =
            (i & 1) << 2 | (j & 1) << 1 | 1;
        sk -= 2;
      } else {
        ans[i << 1][j << 1] = ans[i << 1 | 1][j << 1] = (i & 1) << 2 | (j & 1)
                                                                           << 1;
        ans[i << 1][j << 1 | 1] = ans[i << 1 | 1][j << 1 | 1] =
            (i & 1) << 2 | (j & 1) << 1 | 1;
      }
    }
}
void work() { Get_ans(n, m); }
void outo() {
  if (ans0) {
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) putchar(ans[i][j] + 'a');
      puts("");
    }
  } else
    puts("NO");
}
int main() {
  int T = 1;
  scanf("%d", &T);
  for (; T--;) {
    into();
    work();
    outo();
  }
  return 0;
}
