#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - 48;
    s = getchar();
  }
  return f * x;
}
const int N = 5005;
int id1[N], id2[N], p[N], q[N], a[N];
int tmp1[N], tmp2[N];
int main() {
  int k = read(), n = 1 << k;
  for (int i = 1; i <= n; i++) a[i] = read();
  memset(p, -1, sizeof(p)), memset(q, -1, sizeof(q));
  while (clock() / CLOCKS_PER_SEC < 0.8) {
    int tot = 0, cnt = 0;
    memset(id1, 0, sizeof(id1)), memset(id2, 0, sizeof(id2));
    for (int i = 1; i <= n; i++)
      if (p[i] != -1)
        id1[p[i]] = i, id2[q[i]] = i;
      else
        tmp1[++cnt] = i;
    if (!cnt) {
      puts("Shi");
      for (int i = 1; i <= n; i++) printf("%d ", p[i]);
      puts("");
      for (int i = 1; i <= n; i++) printf("%d ", q[i]);
      puts("");
      return 0;
    }
    for (int i = 0; i < n; i++)
      if (!id1[i]) tmp2[++tot] = i;
    int res = tmp1[rand() % cnt + 1];
    int flag = 1;
    for (int i = 1; i <= tot; i++) {
      int t = a[res] ^ tmp2[i];
      if (!id2[t]) {
        p[res] = tmp2[i];
        q[res] = t;
        flag = 0;
        break;
      }
    }
    if (flag) {
      int v = tmp2[rand() % tot + 1];
      int t = a[res] ^ v;
      p[id2[t]] = q[id2[t]] = -1;
      p[res] = v, q[res] = t;
    }
  }
  puts("Fou");
  return 0;
}
