#include <bits/stdc++.h>
using namespace std;
int cnt[1010000], n, size, excnt, ex[1010000], x[1010000], y[1010000],
    op[1010000], i, id, bas = (1 << 17);
long long a[1010000][6];
char ch[1010000];
void init() {
  sort(ex + 1, ex + 1 + excnt);
  size = unique(ex + 1, ex + 1 + excnt) - ex - 1;
  for (i = 1; i <= n; i++) y[i] = lower_bound(ex + 1, ex + 1 + size, x[i]) - ex;
}
void pushup(int rt) {
  int ls = rt << 1, rs = ls + 1;
  for (int i = 0; i <= 4; i++) a[rt][i] = a[ls][i];
  for (int i = 0; i <= 4; i++) a[rt][(i + cnt[ls]) % 5] += a[rs][i];
  cnt[rt] = cnt[ls] + cnt[rs];
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", ch);
    if (ch[0] == 's')
      op[i] = 2;
    else {
      scanf("%d", &x[i]);
      ex[++excnt] = x[i];
      op[i] = ch[0] == 'a' ? 0 : 1;
    }
  }
  init();
  for (i = 1; i <= n; i++) {
    if (op[i] == 2)
      printf("%I64d\n", a[1][3]);
    else {
      id = bas + y[i];
      a[id][1] = (1 - op[i]) * x[i];
      cnt[id] = (1 - op[i]);
      for (id /= 2; id >= 1; id /= 2) pushup(id);
    }
  }
  return 0;
}
