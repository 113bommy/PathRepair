#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
char ch[N];
char nw[N];
int w[N][21];
int m, n;
inline int query(int x, int len) {
  int y = x;
  for (int i = 20; i >= 0; --i) {
    if ((len >> i) & 1) y = w[y][i];
  }
  if (y != 0)
    return y + len;
  else {
    len = 0;
    y = x;
    for (int i = 20; i >= 0; --i) {
      if (w[y][i] != 0) {
        y = w[y][i];
        len += (1 << i);
      }
    }
    y = w[y][0];
    ++len;
    return y + len;
  }
}
int main() {
  scanf("%s", ch + 1);
  n = strlen(ch + 1);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    vector<int> id;
    int x, y;
    scanf("%d%d", &x, &y);
    int cur = 1;
    while ((int)id.size() < x) {
      id.push_back(cur);
      if (cur + y <= x)
        cur += y;
      else
        cur = (cur % y) + 1;
    }
    for (int j = 0; j <= x - 1; ++j) w[id[j]][0] = j;
    w[0][0] = 0;
    for (int j = 1; j <= 20; ++j)
      for (int k = 0; k <= x; ++k) w[k][j] = w[w[k][j - 1]][j - 1];
    for (int j = 1; j <= n; ++j) {
      int res;
      if (j < x) {
        res = query(j, j);
        nw[res] = ch[j];
      } else {
        res = query(x, min(x, n - j + 1)) + j - x;
        nw[res] = ch[j];
      }
    }
    for (int j = 1; j <= n; ++j) ch[j] = nw[j];
    for (int j = 1; j <= n; ++j) printf("%c", ch[j]);
    puts("");
  }
}
