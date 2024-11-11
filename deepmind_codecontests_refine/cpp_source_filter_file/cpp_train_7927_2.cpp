#include <bits/stdc++.h>
using namespace std;
const int INF = 3.5e7;
int read() {
  int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
  return x * f;
}
int k, n, a[5002], p[5002], q[5002], bel[5002], v[5002];
bool in[5002];
void fix(int x, int y) {
  register int now = q[x] ^ v[x], t = bel[now];
  if (t == x) return;
  if (t == y) {
    swap(p[x], p[y]), swap(bel[p[x]], bel[p[y]]);
    return;
  }
  swap(bel[now], bel[p[x]]);
  swap(p[now], p[x]), swap(q[now], q[y]);
  fix(now, y);
}
signed main() {
  k = read();
  n = (1 << k);
  register int tmp = 0;
  for (int i = 0; i < n; i++)
    a[i] = read(), tmp ^= a[i], p[i] = q[i] = bel[i] = i;
  if (tmp) {
    puts("Fou");
    return 0;
  }
  puts("Shi");
  for (int i = 0; i + 1 < n; i++) {
    if (v[i] != a[i]) {
      tmp = v[i] ^ a[i], v[i] ^= tmp, v[i + 1] ^= tmp;
      fix(i, i + 1);
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", p[i]);
  puts("");
  for (int i = 0; i < n; i++) printf("%d ", q[i]);
  return 0;
}
