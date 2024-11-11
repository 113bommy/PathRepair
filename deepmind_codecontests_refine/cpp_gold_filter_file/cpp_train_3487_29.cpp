#include <bits/stdc++.h>
using namespace std;
const long long INF = 1 << 29;
const long long LINF = 1ll << 61;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
template <class T>
inline void putnum(T x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
int X, n, a[22][22], b[22][22], suf[22];
bool visx[22], visy[22];
int ans, mx[22], my[22], lx[22], ly[22], slk[22], tc[22][22];
bool dfs(int x) {
  visx[x] = 1;
  for (int y = 1; y <= n; y++) {
    if (lx[x] + ly[y] > tc[x][y]) {
      slk[y] = min(slk[y], lx[x] + ly[y] - tc[x][y]);
    } else if (!visy[y]) {
      visy[y] = 1;
      if (my[y] == -1 || dfs(my[y])) {
        mx[x] = y;
        my[y] = x;
        return true;
      }
    }
  }
  return false;
}
void go(int x) {
  for (int i = 1; i <= n; i++) slk[i] = INF;
  memset(visx, 0, sizeof(visx));
  memset(visy, 0, sizeof(visy));
  while (!dfs(x)) {
    int d = INF * 2;
    for (int i = 1; i <= n; i++)
      if (!visy[i]) d = min(d, slk[i]);
    if (d == INF * 2) {
      puts("WTF!");
      exit(1);
    }
    for (int i = 1; i <= n; i++)
      if (visx[i]) lx[i] -= d, visx[i] = 0;
    for (int i = 1; i <= n; i++)
      if (visy[i]) ly[i] += d, visy[i] = 0;
    for (int i = 1; i <= n; i++) slk[i] = INF;
  }
}
void calc(int cnta, int cntb) {
  int tans = 0;
  for (int i = 1; i < X; i++) tans += tc[i][mx[i]];
  if (clock() > 200) {
    cout << ans << endl;
    exit(0);
  }
  if (tans + suf[X] <= ans) return;
  if (X > n) {
    ans = tans;
    return;
  }
  if (cnta < n / 2 && cntb < n / 2) {
    int tlx[22], tly[22], tmx[22], tmy[22];
    for (int i = 1; i <= n; i++)
      tlx[i] = lx[i], tly[i] = ly[i], tmx[i] = mx[i], tmy[i] = my[i];
    for (int i = 1; i <= n; i++) tc[X][i] = a[X][i];
    go(X);
    X++;
    calc(cnta + 1, cntb);
    X--;
    for (int i = 1; i <= n; i++)
      lx[i] = tlx[i], ly[i] = tly[i], mx[i] = tmx[i], my[i] = tmy[i];
    for (int i = 1; i <= n; i++) tc[X][i] = b[X][i];
    go(X);
    X++;
    calc(cnta, cntb + 1);
    X--;
  } else if (cnta < n / 2) {
    for (int i = 1; i <= n; i++) tc[X][i] = a[X][i];
    go(X);
    X++;
    calc(cnta + 1, cntb);
    X--;
  } else if (cntb < n / 2) {
    for (int i = 1; i <= n; i++) tc[X][i] = b[X][i];
    go(X);
    X++;
    calc(cnta, cntb + 1);
    X--;
  }
}
int main() {
  n = getnum();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = getnum();
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      b[i][j] = getnum();
    }
  }
  for (int i = n; i >= 1; i--) {
    suf[i] = max(*max_element(a[i] + 1, a[i] + 1 + n),
                 *max_element(b[i] + 1, b[i] + 1 + n));
    suf[i] += suf[i + 1];
  }
  for (int i = 1; i <= n; i++) lx[i] = INF;
  memset(mx, -1, sizeof(mx));
  memset(my, -1, sizeof(my));
  X = 1;
  calc(0, 0);
  cout << ans << endl;
  return 0;
}
