#include <bits/stdc++.h>
using namespace std;
int n, m;
char name[2000], part[2000000];
int work() {
  int p = 0;
  for (int i = 0; i < m; i++) {
    if (part[i] == name[p]) p++;
    if (p == n) return i;
  }
  return m;
}
int main() {
  scanf("%s", name);
  scanf("%s", part);
  n = strlen(name), m = strlen(part);
  int x = work();
  reverse(name, name + n);
  reverse(part, part + m);
  int y = work();
  printf("%d\n", max(0, m - y - x - 1));
  return 0;
}
