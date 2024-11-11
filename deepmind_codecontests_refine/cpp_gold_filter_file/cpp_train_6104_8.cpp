#include <bits/stdc++.h>
using namespace std;
inline void up(int& x, int y) {
  x = x + y < 1000000007 ? x + y : x + y - 1000000007;
}
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
string a = "What are you doing at the end of the world? Are you busy? Will you "
           "save us?",
       b = "What are you doing while sending \"",
       c = "\"? Are you busy? Will you send \"";
long long d, e, f, g[100010], h;
char kk(int q, long long w) {
  if (q == 0) return a[w - 1];
  if (w <= 34) return b[w - 1];
  if (q - 1 >= h || g[q - 1] + 34 >= w) return kk(q - 1, w - 34);
  if (66 + g[q - 1] >= w) return c[w - 35 - g[q - 1]];
  if (w == g[q] - 1) return '"';
  if (w == g[q]) return '?';
  return kk(q - 1, w - 66 - g[q - 1]);
}
int main() {
  g[0] = 75;
  for (int i = 1; i <= 1000; i++) {
    g[i] = 2 * g[i - 1] + 68;
    if (g[i] > 1e18) {
      h = i;
      break;
    }
  }
  cin >> d;
  while (d--) {
    cin >> e >> f;
    if (e < h && f > g[e])
      cout << ".";
    else
      cout << kk(e, f);
  }
  return 0;
}
