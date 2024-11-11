#include <bits/stdc++.h>
inline int in() {
  int x = 0;
  char c = getchar();
  bool f = false;
  while (c < '0' || c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
inline long long lin() {
  long long x = 0;
  char c = getchar();
  bool f = false;
  while (c < '0' || c > '9') f |= c == '-', c = getchar();
  while (c >= '0' && c <= '9')
    x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
  return f ? -x : x;
}
int main() {
  int n;
  do {
    puts("next 0 1");
    fflush(stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%*s");
    puts("next 1");
    fflush(stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%*s");
  } while (n == 3);
  do {
    puts("next 2 3 4 5 6 7 8 9");
    fflush(stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%*s");
  } while (n == 2);
  puts("done");
  return 0;
}
