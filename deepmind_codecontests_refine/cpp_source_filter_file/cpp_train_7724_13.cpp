#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int N, a[MAXN], p[MAXN], mat[MAXN][MAXN];
bool cmp(int x, int y) { return a[x] > a[y]; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) scanf("%d", &a[i]), p[i] = i;
  sort(p + 1, p + N + 1, cmp);
  for (int i = 1; i <= N; ++i) {
    for (int j = p[i]; a[p[i]];) {
      mat[j][p[i]] = 1, --a[p[i]];
      ++j;
      if (j == N + 2) j = 1;
    }
  }
  printf("%d\n", N + 1);
  for (int i = 1; i <= N + 1; ++i) {
    for (int j = 1; j <= N; ++j) printf("%d", mat[i][j]);
    putchar('\n');
  }
  return 0;
}
