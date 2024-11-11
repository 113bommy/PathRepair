#include <bits/stdc++.h>
using namespace std;
int n, q1[505], q2[505];
bool cmp(int x, int y) {
  if (x == 2 * n + 1 || y == 2 * n + 1) return 0;
  printf("? %d %d\n", x, y);
  fflush(stdout);
  char s[10];
  scanf("%s", s + 1);
  return s[1] == '<';
}
void solve() {
  scanf("%d", &n);
  int v1 = (n + 1) / 2, v2 = n + 1 - v1;
  *q1 = 0;
  *q2 = 0;
  for (int i = (int)(1); i <= (int)(v1); i++) q1[++*q1] = i;
  for (int i = (int)(1); i <= (int)(v2); i++) q2[++*q2] = i + v1;
  for (int i = (int)(1); i <= (int)(v1); i++)
    for (int j = (int)(i + 1); j <= (int)(v1); j++)
      if (cmp(q1[j], q1[i])) swap(q1[i], q1[j]);
  for (int i = (int)(1); i <= (int)(v2); i++)
    for (int j = (int)(i + 1); j <= (int)(v2); j++)
      if (cmp(q2[j], q2[i])) swap(q2[i], q2[j]);
  for (int i = (int)(n + 2); i <= (int)(2 * n + 1); i++)
    if (cmp(q1[1], q2[1])) {
      q1[1] = i;
      for (int j = (int)(1); j <= (int)(v1 - 1); j++)
        if (cmp(q1[j + 1], q1[j]))
          swap(q1[j + 1], q1[j]);
        else
          break;
    } else {
      q2[1] = i;
      for (int j = (int)(1); j <= (int)(v2 - 1); j++)
        if (cmp(q2[j + 1], q2[j]))
          swap(q2[j + 1], q2[j]);
        else
          break;
    }
  puts("!");
  fflush(stdout);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
