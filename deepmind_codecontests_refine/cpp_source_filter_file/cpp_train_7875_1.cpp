#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
const int INF = 9999999;
const int MAXN = 300000;
int Q;
bool vis[MAXN + 1];
int kek = 0, u;
int main() {
  Q = read();
  while (Q--) {
    int opr = read();
    if (opr == 1) {
      kek++;
      u = read();
      vis[u] = true;
    } else {
      int x = read(), k = read(), s = read();
      if (x % k != 0) {
        puts("-1");
        continue;
      }
      if (kek == 1) {
        if (u % k == 0 && x + u <= s)
          printf("%d\n", u);
        else
          printf("-1\n");
        continue;
      }
      int ans = -INF, tmp = 0;
      int c = (int)((s - x) / k) * k;
      for (int i = c; i >= 1; i -= k) {
        if (ans && (tmp - i > x + 10)) break;
        if (vis[i] && (x ^ i) > ans) ans = x ^ i, tmp = i;
      }
      if (tmp)
        printf("%d\n", tmp);
      else
        printf("-1\n");
    }
  }
  return 0;
}
