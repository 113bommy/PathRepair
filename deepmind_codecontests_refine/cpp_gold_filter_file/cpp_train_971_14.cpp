#include <bits/stdc++.h>
char str[2][1000000];
int d[2][1000000];
struct {
  int lor;
  int s;
} queue[2000000];
int qt = 0, qh = 0;
int n, exitf = 0;
void add(int lor, int s, int z) {
  if (s >= n) {
    exitf = 1;
    return;
  }
  if (s >= 0 && str[lor][s] == '-' && !d[lor][s] && s >= z) {
    queue[qh].lor = lor;
    queue[qh].s = s;
    qh++;
    d[lor][s] = z;
  }
  return;
}
int main() {
  int k;
  scanf("%d %d\n%s\n%s", &n, &k, str[0], str[1]);
  add(0, 0, 0);
  while (qt < qh && !exitf) {
    add(queue[qt].lor, queue[qt].s + 1, d[queue[qt].lor][queue[qt].s] + 1);
    add(queue[qt].lor, queue[qt].s - 1, d[queue[qt].lor][queue[qt].s] + 1);
    add((queue[qt].lor) ? 0 : 1, queue[qt].s + k,
        d[queue[qt].lor][queue[qt].s] + 1);
    qt++;
  }
  printf("%s", ((exitf) ? "YES" : "NO"));
  return 0;
}
