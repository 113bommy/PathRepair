#include <bits/stdc++.h>
using namespace std;
char s[100010];
int n;
int func(char c) { return c - 'a'; }
int a[100010];
int c[1 << 6], f[1 << 6];
void _insert(int pos) {
  for (int j = 1; j < 64; j++)
    if (j & a[pos]) c[j]++;
}
void _delete(int pos) {
  for (int j = 1; j < 64; j++)
    if (j & a[pos]) c[j]--;
}
char ans[100010];
bool check() {
  for (int j = 1; j < 64; j++)
    if (f[j] > c[j]) return 0;
  return 1;
}
int main() {
  scanf("%s", s + 1);
  n = strlen(s + 1);
  for (int i = 1; i <= n; i++) a[i] = 63;
  int m;
  scanf("%d", &m);
  while (m--) {
    int pos;
    char tmp[10];
    scanf("%d%s", &pos, tmp);
    a[pos] = 0;
    for (int i = 0; tmp[i]; i++) a[pos] |= 1 << (func(tmp[i]));
  }
  for (int i = 1; i <= n; i++) _insert(i);
  for (int i = 1; i <= n; i++) f[1 << (func(s[i]))]++;
  for (int j = 1; j < 64; j++) {
    int t = __builtin_ctz(j);
    if (j != (1 << t)) f[j] = f[j ^ (1 << t)] + f[1 << t];
  }
  for (int i = 1; i <= n; i++) {
    _delete(i);
    for (int j = 0; j < 6; j++)
      if (f[1 << j] > 0 && ((a[i] >> j) & 1)) {
        for (int k = 1; k < 64; k++)
          if ((k >> j) & 1) f[k]--;
        if (check()) {
          ans[i] = j + 'a';
          break;
        }
        for (int k = 1; k < 64; k++)
          if ((k >> j) & 1) f[k]++;
      }
    if (!ans[i]) break;
  }
  ans[n + 1] = 0;
  if (ans[n])
    puts(ans + 1);
  else
    puts("Impossible");
}
