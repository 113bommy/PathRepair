#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, num;
int sg[5010], f[5010];
char p[5010];
inline int mex() {
  int i;
  for (i = 0; f[i] == num; i++)
    ;
  return i;
}
inline int S(int x) { return x < 0 ? 0 : sg[x]; }
inline void prepare() {
  int i, j;
  for (i = 1; i <= n; i++) {
    num++;
    for (j = 1; j <= i; j++) f[S(j - 2) ^ S(i - j - 1)] = num;
    sg[i] = mex();
  }
}
inline void work(int x) {
  int i, an = 0, j;
  for (i = 2; i < x - 1;) {
    for (; i < x - 1 && p[i - 1] != p[i + 1]; i++)
      ;
    if (i == x - 1) break;
    for (j = i; j < x - 1 && p[j - 1] == p[j + 1]; j++)
      ;
    an ^= sg[j - i];
    i = j;
  }
  for (i = x + 2; i < n;) {
    for (; i < n && p[i - 1] != p[i + 1]; i++)
      ;
    if (i == n) break;
    for (j = i; j < n && p[j - 1] == p[j + 1]; j++)
      ;
    an ^= sg[j - i];
    i = j;
  }
  if (an ^ 1) {
    printf("First\n%d\n", x);
    exit(0);
  }
}
int main() {
  scanf("%s", p + 1);
  n = strlen(p + 1);
  prepare();
  for (i = 2; i <= n - 1; i++)
    if (p[i - 1] == p[i + 1]) work(i);
  printf("Second\n");
  return 0;
}
