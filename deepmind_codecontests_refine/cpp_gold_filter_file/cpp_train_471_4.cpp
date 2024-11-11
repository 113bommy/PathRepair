#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void read(T &x) {
  int f = 0;
  x = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) f |= (ch == '-');
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  if (f) x = -x;
}
const int N = 100005;
int xx[N], yy[N], yes[N], n, m, cnt, now, flag, x, y, X, Y, K, L = 13;
vector<int> a[N];
int calc(int x, int y) {
  int res = 0;
  res += a[x - 1][y - 1] & a[x - 1][y];
  res += a[x - 1][y - 1] & a[x][y - 1];
  res += a[x - 1][y] & a[x][y - 1];
  res += a[x - 1][y] & a[x - 1][y + 1];
  return res;
}
int chk(int s) {
  static int q[N];
  int l = 0, r = 0;
  for (int i = (1); i <= (cnt); i++) {
    a[xx[i]][yy[i]] = 0;
    yes[i] = 0;
    if (!(s >> (i - 1) & 1)) continue;
    if (xx[i] == x || xx[i] == x + 1 && yy[i] <= y) yes[i] = 1, q[r++] = i;
  }
  while (l < r) {
    int u = q[l++];
    for (int v = (1); v <= (cnt); v++)
      if (s >> (v - 1) & 1) {
        if (!yes[v] && abs(xx[u] - xx[v]) + abs(yy[u] - yy[v]) == 1) {
          yes[v] = 1, q[r++] = v;
        }
      }
  }
  for (int i = (1); i <= (cnt); i++)
    if ((s >> (i - 1) & 1) && !yes[i]) return 0;
  int sum = now;
  for (int i = (1); i <= (cnt); i++)
    if (s >> (i - 1) & 1) sum += calc(xx[i], yy[i]), a[xx[i]][yy[i]] = 1;
  return sum == K;
}
void rmain() {
  read(n), read(m), read(K);
  if (n < m)
    swap(n, m), flag = 1;
  else
    flag = 0;
  for (int i = (0); i <= (n + 1); i++) a[i].clear(), a[i].resize(m + 2);
  now = 0, x = n, y = m;
  int rem = n * m;
  for (int i = (1); i <= (n); i++) {
    int owo = 0;
    for (int j = (1); j <= (m); j++) {
      int nxt = calc(i, j);
      rem--;
      if (now + nxt <= K && rem >= L)
        now += nxt, a[i][j] = 1;
      else {
        x = i, y = j - 1;
        if (y == 0) y = m, x--;
        owo = 1;
        break;
      }
    }
    if (owo) break;
  }
  cnt = 0, X = x, Y = y;
  int Flag = (x < n);
  while (cnt + flag < L) {
    Y++;
    if (Y > m) X++, Y = 1;
    if (X > n) break;
    xx[++cnt] = X, yy[cnt] = Y;
    if (X == x + 1 && Y == y) Flag = 0;
  }
  if (Flag) xx[++cnt] = x + 1, yy[cnt] = y;
  int found = 0;
  for (int s = (x == 0 ? 1 : 0); s < (1 << cnt); s++)
    if (chk(s)) {
      found = 1;
      break;
    }
  if (!found) {
    puts("-1");
    return;
  }
  if (flag) swap(n, m);
  for (int i = (1); i <= (n); i++) {
    for (int j = (1); j <= (m); j++)
      printf("%c", (flag ? a[j][i] : a[i][j]) ? '*' : '.');
    puts("");
  }
}
int main() {
  int T;
  read(T);
  while (T--) rmain(), puts("");
  return 0;
}
