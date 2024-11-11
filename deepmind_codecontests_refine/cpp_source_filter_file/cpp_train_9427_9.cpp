#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 10;
char ans[MAXN];
struct node {
  char s[MAXN][MAXN];
  int sum;
} head[MAXN];
char s[MAXN];
int main() {
  int n, m;
  int i;
  scanf("%d%d", &n, &m);
  for (i = 0; i < 100; ++i) head[i].sum = 0;
  for (i = 0; i < n; ++i) {
    scanf("%s", s);
    int l = strlen(s);
    strcpy(head[l].s[head[l].sum++], s);
  }
  scanf("%s", ans);
  int ansl = strlen(ans);
  int MIN = 0;
  for (i = 1; i < ansl; ++i) {
    MIN += head[i].sum;
  }
  int MAX = MIN + head[i].sum;
  MIN += MIN / m * 5;
  MIN++;
  MAX += MAX / m * 5;
  printf("%d %d\n", MIN, MAX);
  return 0;
}
