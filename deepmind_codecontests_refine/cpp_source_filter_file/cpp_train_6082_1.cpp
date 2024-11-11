#include <bits/stdc++.h>
inline int read() {
  int x = 0, f = 0;
  register char ch = getchar();
  for (; ch < 48 || ch > 57; ch = getchar()) f |= ch == '-';
  for (; ch > 47 && ch < 58; ch = getchar())
    x = (x << 1) + (x << 3) + (ch ^ 48);
  return f ? ~x + 1 : x;
}
using namespace std;
int t[7005], l[7005], r[7005], x[7005], pos[7005][2], cnt;
set<int> s;
int main() {
  int n = read(), m = read();
  for (int i = 0; i < m; ++i) {
    int k = read();
    if (k == 1)
      t[++cnt] = read(), l[cnt] = read(), r[cnt] = read(), x[cnt] = read();
    else {
      int lvl = read();
      pos[lvl][1] = pos[lvl][0] = read();
      s.clear();
      for (int i = lvl; i < n; ++i) {
        int k = pos[i][0], j = 0, c = 0;
        for (; k; k >>= 1, ++j) c += k & 1;
        pos[i + 1][0] = pos[i][0] + j - (c == 1);
        k = pos[i][1], j = 0;
        for (; k; k >>= 1, ++j)
          ;
        pos[i + 1][1] = pos[i][1] + j;
      }
      for (int i = 1; i <= cnt; ++i)
        if (t[i] >= lvl && (l[i] <= pos[t[i]][0] && pos[t[i]][0] <= r[i] ||
                            l[i] <= pos[t[i]][1] && pos[t[i]][1] <= l[i] ||
                            pos[t[i]][0] <= l[i] && r[i] <= pos[t[i]][1]))
          s.insert(x[i]);
      printf("%d\n", s.size());
    }
  }
  return 0;
}
