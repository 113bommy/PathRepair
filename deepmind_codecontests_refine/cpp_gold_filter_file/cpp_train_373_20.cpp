#include <bits/stdc++.h>
using namespace std;
int cnt[1010000], n, size, excnt, ex[1010000], x[1010000], y[1010000],
    op[1010000], i, id, pos[1010000], bl, a[1010000];
char ch[1010000];
long long b[1010000][6];
void init() {
  sort(ex + 1, ex + 1 + excnt);
  size = unique(ex + 1, ex + 1 + excnt) - ex - 1;
  for (i = 1; i <= n; i++) y[i] = lower_bound(ex + 1, ex + 1 + size, x[i]) - ex;
}
void update(int id) {
  int l = (id - 1) * bl + 1, r = id * bl, t = 0;
  memset(b[id], 0, sizeof(b[id]));
  cnt[id] = 0;
  for (int i = l; i <= r; i++)
    if (a[i] > 0) {
      t++;
      if (t >= 5) t -= 5;
      b[id][t] += a[i];
      cnt[id]++;
    }
}
long long calc() {
  long long ret = 0, t = 0;
  for (int i = 1; i <= size / bl + 1; i++) {
    ret += b[i][(8 - t) % 5];
    (t += cnt[i]) %= 5;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", ch);
    if (ch[0] == 's') {
      op[i] = 2;
      if (n == 1) {
        cout << 0 << endl;
        return 0;
      }
    } else {
      scanf("%d", &x[i]);
      ex[++excnt] = x[i];
      op[i] = ch[0] == 'a' ? 0 : 1;
    }
  }
  init();
  bl = sqrt(size);
  for (i = 1; i <= size; i++) pos[i] = (i - 1) / bl + 1;
  for (i = 1; i <= n; i++) {
    if (op[i] == 2)
      printf("%I64d\n", calc());
    else {
      if (op[i] == 0)
        a[y[i]] = x[i];
      else
        a[y[i]] = 0;
      update(pos[y[i]]);
    }
  }
}
