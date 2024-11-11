#include <bits/stdc++.h>
using namespace std;
char t[200010];
char p[200010];
int a[200010];
int length;
bool check(int x) {
  int b[200010], N, i, j;
  char p1[200010];
  N = length;
  for (i = 0; i < N; i++) b[i] = a[i];
  sort(b + N - x, b + N);
  for (i = 0; i < x; i++) p1[i] = t[b[N - x + i] - 1];
  p1[i] = '\0';
  i = 0;
  for (j = 0; j < x; j++)
    if (p1[j] == p[i]) i++;
  if (i < strlen(p))
    return 0;
  else
    return 1;
}
int main() {
  int i, st, ed, mid;
  scanf("%s", t);
  scanf("%s", p);
  length = strlen(t);
  st = 0;
  ed = length + 1;
  for (i = 0; i < length; i++) scanf("%d", &a[i]);
  while (ed - st > 1) {
    mid = (st + ed) / 2;
    if (check(mid))
      ed = mid;
    else
      st = mid;
  }
  printf("%d\n", length - ed);
  return 0;
}
