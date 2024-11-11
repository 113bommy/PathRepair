#include <bits/stdc++.h>
using namespace std;
int ans, n, v[200001], f[200001];
char s[200001];
void get(int x) {
  int i, j;
  for (i = 1; i <= x; i++)
    if (x % i == 0) f[i] = x / i;
  for (i = x; i; i--)
    for (j = i * 2; j <= x; j += i) f[i] -= f[j];
}
int main() {
  int i, j, now, nt, ha, hh, flag;
  scanf("%d", &n);
  scanf("%s", s + 1);
  get(n);
  for (i = 1; i <= n; i++)
    if (n % i == 0) {
      memset(v, 0, sizeof(v));
      ha = 0;
      for (j = 1; j <= n; j++)
        if (!v[j]) {
          now = j;
          flag = 0;
          hh = 0;
          while (!flag || now != j) {
            flag = 1;
            v[now] = 1;
            nt = (now + i - 1) % n + 1;
            if (s[nt] == '1') hh++;
            now = nt;
          }
          if (hh % 2 == 1) {
            ha = 1;
            break;
          }
        }
      if (!ha) ans += f[i];
    }
  flag = 1;
  for (i = 1; i <= n; i++)
    if (s[i] == '1') flag = 0;
  ans += flag;
  printf("%d", ans);
}
