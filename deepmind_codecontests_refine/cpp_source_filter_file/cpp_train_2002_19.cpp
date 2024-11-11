#include <bits/stdc++.h>
using namespace std;
int nextInt() {
  int x = 0, p = 1;
  char c;
  do {
    c = getchar();
  } while (c <= 32);
  if (c == '-') {
    p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x * p;
}
const int N = 500;
const int INF = 1000000000, mod = 1000000000;
const long long LLINF = 1000000000000000000ll;
int n, m, k;
char s[N][N];
int c[N][N];
int f(int x, int y) { return x >= 0 && y >= 0 && x < n && y < m ? c[x][y] : 0; }
int isStar(int x, int y) {
  if (x < 2 || y < 2) return 0;
  return s[x - 1][y] == '1' && s[x][y - 1] == '1' && s[x - 1][y - 1] == '1' &&
         s[x - 2][y - 1] == '1' && s[x - 1][y - 2] == '1';
}
int calc(int xa, int ya, int xb, int yb) {
  if (xa < 0) return 0;
  return f(xb, yb) - f(xa - 1, yb) - f(xb, ya - 1) + f(xa - 1, ya - 1);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    scanf("\n%s", s[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      c[i][j] = f(i - 1, j) + f(i, j - 1) - f(i - 1, j - 1) + isStar(i, j);
    }
  }
  long long answer = 0LL;
  for (int l = 0; l < n; ++l) {
    for (int r = l + 2; r < n; ++r) {
      int rj = 2;
      for (int lj = 0; lj < m; ++lj) {
        rj = max(rj, lj + 1);
        while (rj < m && calc(l + 2, lj + 2, r, rj) < k) rj++;
        answer += max(0, m - rj);
      }
    }
  }
  printf("%I64d\n", answer);
  return 0;
}
