#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 500;
inline int read() {
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    ;
  int res = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9') res = res * 10 + ch - '0';
  return res;
}
int tot, n, ans[N << 3];
struct linbas {
  int p[19], w[19];
  void ins(int x) {
    int now = x;
    for (int i = 18; i >= 0; i--)
      if ((x >> i) & 1) {
        if (!p[i]) {
          p[i] = x;
          w[i] = now;
          return;
        }
        if (w[i] > now) swap(w[i], now), swap(p[i], x);
        x ^= p[i];
        if (!x) return;
      }
  }
} G;
void dfs(int num) {
  if (num == -1) return;
  dfs(num - 1);
  ans[++tot] = G.w[num];
  dfs(num - 1);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) G.ins(read());
  int orz = 0;
  while (orz <= 18 && G.p[orz]) orz++;
  while (orz >= 0 && G.w[orz - 1] >= (1 << orz)) orz--;
  printf("%d\n", orz);
  ans[++tot] = 0;
  dfs(orz - 1);
  for (int i = 1; i <= tot; i++) printf("%d ", ans[i] ^= ans[i - 1]);
  return 0;
}
