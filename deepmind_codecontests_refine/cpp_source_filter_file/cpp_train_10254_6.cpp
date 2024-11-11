#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
const int M = 26;
char s1[N], s2[N], z1[N][M], z2[N][M];
int n;
bool check(int l1, int r1, int l2, int r2) {
  int l, i, t1, t2;
  for (i = 0; i < M; ++i) {
    t1 = z1[r1 - 1][i];
    if (l1) t1 -= z1[l1 - 1][i];
    t2 = z2[r2 - 1][i];
    if (l2) t2 -= z2[l2 - 1][i];
    if (t1 != t2) return false;
  }
  l = r1 - l1;
  if (l & 1) {
    for (i = 0; i < l; ++i)
      if (s1[l1 + i] != s2[l2 + i]) return false;
    return true;
  }
  l >>= 1;
  if (check(l1, l1 + l, l2, l2 + l) && check(l1 + l, r1, l2 + l, r2))
    return true;
  if (check(l1, l1 + l, l2 + l, r2) && check(l1 + l, r2, l2, l2 + l))
    return true;
  return false;
}
int main() {
  if (0) {
    freopen("input.txt", "w", stdout);
    int n, i;
    n = 8192;
    for (i = 0; i < n; ++i) printf("a");
    printf("\n");
    for (i = 0; i < n; ++i) printf("a");
    printf("\n");
    return 0;
  }
  int i, j;
  scanf("%s", s1);
  scanf("%s", s2);
  n = strlen(s1);
  ++z1[0][s1[0] - 'a'];
  ++z2[0][s2[0] - 'a'];
  for (i = 1; i < n; ++i) {
    for (j = 0; j < M; ++j) z1[i][j] += z1[i - 1][j], z2[i][j] += z2[i - 1][j];
    ++z1[i][s1[i] - 'a'];
    ++z2[i][s2[i] - 'a'];
  }
  printf("%s\n", (check(0, n, 0, n)) ? "YES" : "NO");
  return 0;
}
