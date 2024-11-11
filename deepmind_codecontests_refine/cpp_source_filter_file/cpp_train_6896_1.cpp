#include <bits/stdc++.h>
using namespace std;
int T, n, k, pos, len, s;
char ch[10];
int random(int x) {
  int y = rand() % x;
  if (y == 0) y += x;
  return y;
}
bool check(int s, int len) {
  printf("? %d %d\n", len, len);
  for (int i = 1; i <= len; i++) printf("%d ", i);
  puts("");
  for (int i = 1; i <= len; i++) printf("%d ", s + i - 1);
  puts("");
  fflush(stdout);
  scanf("%s", ch + 1);
  return ch[1] == 'E';
}
void solve(int l, int r) {
  if (l == r) {
    printf("! %d\n", l);
    fflush(stdout);
    return;
  }
  int mid = (l + r) >> 1, len = mid - l + 1;
  if (check(l, len))
    solve(mid + 1, r);
  else
    check(l, mid);
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &k);
    pos = random(n);
    s = len = 0;
    for (int i = 1; i <= 20; i++) {
      int now = random(n);
      while (now == pos) now = random(n);
      printf("? 1 1\n%d\n%d\n", pos, now);
      fflush(stdout);
      scanf("%s", ch + 1);
      if (ch[1] == 'S') pos = now;
    }
    if (pos != 1) {
      printf("? 1 1\n%d\n%d\n", pos, 1);
      fflush(stdout);
      scanf("%s", ch + 1);
      if (ch[1] != 'E') {
        puts("! 1");
        fflush(stdout);
        continue;
      }
    }
    for (int i = 1; i <= n / 2; i <<= 1) {
      printf("? %d %d\n", i, i);
      s = i;
      for (int j = 1; j <= i; j++) printf("%d ", j);
      puts("");
      for (int j = 1; j <= i; j++) printf("%d ", i + j);
      puts("");
      fflush(stdout);
      scanf("%s", ch + 1);
      if (ch[1] != 'E') {
        len = i;
        break;
      }
    }
    if (!len)
      solve(s * 2 + 1, n);
    else
      solve(s + 1, s + len);
  }
}
