#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
const double eps = 1e-8;
void read(int &k) {
  k = 0;
  char x = getchar();
  while (x < '0' || x > '9') x = getchar();
  while (x >= '0' && x <= '9') {
    k = k * 10 - 48 + x;
    x = getchar();
  }
}
int c, d, l0, l1, now, use[110], cnt, best, tmp[110], ct[110];
char s0[110], s1[110];
int check(int x) {
  int len = 0, las = x;
  for (int i = 0, nxt; i < l1; i++) {
    for (nxt = las; nxt < las + l0; nxt++)
      if (s0[nxt % l0] == s1[i]) break;
    if (nxt >= las + l0) return -1;
    len += nxt - las + 1;
    las = (nxt + 1) % l0;
  }
  return len;
}
int main() {
  scanf("%d%d%s%s", &c, &d, s0, s1);
  l0 = strlen(s0);
  l1 = strlen(s1);
  for (int i = 0; i < l0; i++) use[i] = check(i);
  for (int i = 0; i < l0; i++) {
    now = i;
    while (now < l0 && use[i] >= 0) now = now + use[i], ct[i]++;
    if (use[i] == -1)
      tmp[i] = -1;
    else
      tmp[i] = now - i;
  }
  now = 0;
  int lth = 0;
  while (tmp[now] >= 0) {
    if (lth + tmp[now] > c * l0) break;
    lth += tmp[now];
    cnt += ct[now];
    now = (now + tmp[now]) % l0;
  }
  while (use[now] >= 0) {
    if (lth + use[now] > c * l0) break;
    lth += use[now];
    cnt++;
    now = (now + use[now]) % l0;
  }
  printf("%d\n", cnt / d);
  return 0;
}
