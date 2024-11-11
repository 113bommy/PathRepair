#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
bitset<N> a[N], mask[N];
int n;
int base[N], b[N];
char s[N];
int main() {
  scanf("%d", &n);
  memset(base, -1, sizeof(base));
  for (int i = 1; i <= n; i++) {
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    reverse(s + 1, s + 1 + len);
    for (int j = 1; j <= len; j++) b[j] = s[j] - '0';
    int cnt = 0;
    a[i] = 0;
    while (len > 1 || b[1] > 0) {
      int rest = 0;
      for (int j = len; j >= 1; j--) {
        b[j] += rest * 10;
        rest = b[j] & 1;
        b[j] >>= 1;
      }
      a[i][++cnt] = rest;
      while (b[len] == 0 && len > 1) len--;
    }
    bool flag = 1;
    for (int j = 1; j <= cnt + 1; j++) {
      if (!a[i][j]) continue;
      if (base[j] == -1) {
        mask[i][i] = 1;
        base[j] = i;
        flag = 0;
        break;
      }
      mask[i] ^= mask[base[j]];
      a[i] ^= a[base[j]];
    }
    if (!flag) {
      puts("0");
      continue;
    }
    printf("%d", (int)mask[i].count());
    for (int j = 1; j < i; j++) {
      if (mask[i][j]) printf(" %d", j - 1);
    }
    puts("");
  }
  return 0;
}
