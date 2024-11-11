#include <bits/stdc++.h>
int n, k, block, ans, tg[2005], tot, cnt;
char s[10];
void query(int id) {
  for (int i = 1, x = id * block + 1; i <= block; i++, x++) {
    if (tg[x]) continue;
    printf("? %d\n", x);
    cnt++;
    fflush(stdout);
    scanf("%s", s + 1);
    if (s[1] == 'Y') {
      tg[x] = 1;
      ans--;
    }
  }
}
int main() {
  scanf("%d%d", &n, &k);
  ans = n;
  block = std::max(1, k / 2), tot = n / block;
  for (int i = 0; i < tot / 2; i++) {
    puts("R");
    fflush(stdout);
    for (int cnt = 1, d = 0; cnt <= tot; cnt++) {
      int j = (i + d + tot) % tot;
      query(j);
      if (d <= 0)
        d = -d + 1;
      else
        d = -d;
    }
  }
  printf("! %d\n", ans);
}
