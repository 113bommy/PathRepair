#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
const int maxn = 100000 + 10, N = 100000 + 3;
set<int> ZS[maxn * 2], FS[maxn * 2];
set<int>::iterator it;
void R(int &x) {
  x = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c <= '9' && c >= '0') {
    x = (x << 3) + (x << 1) + c - '0';
    c = getchar();
  }
}
int sx, sy, SX, SY;
long long Ans = 0, flag;
set<int> SET[maxn], Q[maxn];
void init(int x, int y) { Q[x].insert(y); }
int mp(int x, int y) {
  it = Q[x].find(y);
  if (it == Q[x].end()) return 0;
  return 1;
}
void init2(int x, int y) { SET[x].insert(y); }
int mp2(int x, int y) {
  it = SET[x].find(y);
  if (it == SET[x].end()) return 0;
  return 1;
}
int NXT(int &x, int &y, int op) {
  if (op == 1) {
    int c1 = mp(x + 1, y);
    int c2 = mp(x, y + 1);
    if (c1 && c2) {
      return x++, y++, 4;
    }
    if (!c1 && !c2) return x++, y++, 4;
    if (c1) return y++, 3;
    return x++, 2;
  }
  if (op == 2) {
    int c1 = mp(x, y + 1);
    int c2 = mp(x - 1, y);
    if (c1 && c2) return x--, y++, 3;
    if (!c1 && !c2) return x--, y++, 3;
    if (c1) return x--, 1;
    return y++, 4;
  }
  if (op == 3) {
    int c1 = mp(x, y - 1);
    int c2 = mp(x + 1, y);
    if (c1 && c2) return x++, y--, 2;
    if (!c1 && !c2) return x++, y--, 2;
    if (c1) return x++, 4;
    return y--, 1;
  }
  if (op == 4) {
    int c1 = mp(x, y - 1);
    int c2 = mp(x - 1, y);
    if (c1 && c2) return x--, y--, 1;
    if (!c1 && !c2) return x--, y--, 1;
    if (c1) return x--, 3;
    return y--, 2;
  }
}
int STA(int &x, int &y, int &op) {
  init2(x, y);
  if (op == 1) {
    int tmp = x - y;
    it = FS[x - y + N].lower_bound(y);
    it--;
    Ans += y - (*it);
    y = (*it);
    x = y + tmp;
    op = NXT(x, y, op);
    if (op == 4) return 1;
    return 0;
  }
  if (op == 2) {
    int tmp = x + y;
    it = ZS[x + y].lower_bound(y);
    it--;
    Ans += y - (*it);
    y = (*it);
    x = tmp - y;
    op = NXT(x, y, op);
    if (op == 3) return 1;
    return 0;
  }
  if (op == 3) {
    int tmp = x + y;
    it = ZS[x + y].lower_bound(y);
    Ans += *it - y;
    y = *it;
    x = tmp - y;
    op = NXT(x, y, op);
    if (op == 2) return 1;
    return 0;
  }
  if (op == 4) {
    int tmp = x - y;
    it = FS[x - y + N].lower_bound(y);
    Ans += *it - y;
    y = *it;
    x = y + tmp;
    op = NXT(x, y, op);
    if (op == 1) return 1;
    return 0;
  }
}
int main() {
  int n, m, k;
  R(n);
  R(m);
  R(k);
  for (int i = 1; i <= k; i++) {
    int x, y;
    R(x);
    R(y);
    ZS[x + y].insert(y);
    FS[x - y + N].insert(y);
    init(x, y);
  }
  for (int i = 0; i <= n + 1; i++) {
    ZS[i].insert(0);
    FS[N + i].insert(0);
    ZS[i + m + 1].insert(m + 1);
    FS[N + i - m - 1].insert(m + 1);
    init(i, 0);
    init(i, m + 1);
  }
  for (int i = 0; i <= m + 1; i++) {
    ZS[i].insert(i);
    FS[N - i].insert(i);
    ZS[i + n + 1].insert(i);
    FS[N + n + 1 - i].insert(i);
    init(0, i);
    init(n + 1, i);
  }
  char op[5];
  R(sx);
  R(sy);
  SX = sx;
  SY = sy;
  scanf("%s", op);
  int D = 0;
  if (op[1] == 'W') {
    if (op[0] == 'N')
      D = 1;
    else
      D = 2;
  } else {
    if (op[0] == 'N')
      D = 3;
    else
      D = 4;
  }
  STA(sx, sy, D);
  SET[SX].erase(SY);
  SX = sx, SY = sy;
  Ans = 0;
  int SS = D;
  while (1) {
    flag = STA(sx, sy, D);
    if (flag) {
      break;
    }
    if (mp2(sx, sy)) break;
  }
  if (flag) {
    Ans--;
    if (SS == 1) D = 4;
    if (SS == 2) D = 3;
    if (SS == 3) D = 2;
    if (SS == 4) D = 1;
    sx = SX, sy = SY;
    while (1) {
      flag = STA(sx, sy, D);
      if (mp2(sx, sy)) break;
    }
  }
  printf("%lld\n", Ans);
}
