#include <bits/stdc++.h>
using namespace std;
const int inf = 2000000000;
int n, m, cv, cd, x, y, z, h[5005], t[200005][4], w, d[5005], f[5005][2],
    mw[5005], out;
bool v[5005], flag;
void adde(int x, int y, int z, int id) {
  t[w][0] = y;
  t[w][1] = z;
  t[w][2] = h[x];
  t[w][3] = id;
  h[x] = w++;
}
struct node {
  int i, d;
  bool operator<(const node &t) const { return d > t.d; }
} temp;
priority_queue<node> q;
int mst(int mi, int mii, int miy) {
  int ret = 0;
  d[miy] = mi;
  f[miy][0] = cv;
  f[miy][1] = mii;
  temp.i = miy;
  temp.d = d[miy];
  q.push(temp);
  while (!q.empty()) {
    temp = q.top();
    q.pop();
    x = temp.i;
    if (v[x]) {
      v[x] = false;
      ret += temp.d;
      for (int i = h[x]; i != -1; i = t[i][2]) {
        y = t[i][0];
        if ((v[y]) && (t[i][1] < d[y])) {
          d[y] = t[i][1];
          f[y][0] = x;
          f[y][1] = i;
          temp.i = y;
          temp.d = d[y];
          q.push(temp);
        }
      }
    }
  }
  return ret;
}
int Q[5005], wQ;
void weight(int z) {
  if (z == cv) return;
  Q[wQ = 0] = z;
  while (mw[Q[wQ]] == -1) {
    Q[wQ + 1] = f[Q[wQ]][0];
    wQ++;
  }
  if (Q[wQ] == cv) mw[Q[--wQ]] = 0;
  for (int i = wQ - 1; i >= 0; i--)
    mw[Q[i]] = max(mw[Q[i + 1]], t[f[Q[i]][1]][1]);
}
int main() {
  scanf("%d%d%d", &n, &m, &cd);
  cv = 0;
  memset(h, -1, sizeof(h));
  w = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    x--;
    y--;
    adde(x, y, z, i + 1);
    adde(y, x, z, i + 1);
  }
  for (int i = 0; i < n; i++) d[i] = inf;
  d[cv] = 0;
  memset(f, -1, sizeof(f));
  f[cv][0] = cv;
  memset(v, true, sizeof(v));
  v[cv] = false;
  out = 0;
  while (1) {
    int mi = inf, mii, miy;
    for (int i = h[cv]; i != -1; i = t[i][2]) {
      y = t[i][0];
      if ((f[y][0] == -1) && (t[i][1] < mi)) {
        mi = t[i][1];
        mii = i;
        miy = t[i][0];
      }
    }
    if (mi == inf) break;
    cd--;
    out += mst(mi, mii, miy);
  }
  for (int i = 0; i < n; i++) {
    if (v[i]) {
      printf("-1\n");
      return 0;
    }
  }
  if (cd < 0) {
    printf("-1\n");
    return 0;
  }
  while (cd--) {
    memset(mw, -1, sizeof(mw));
    mw[cv] = 0;
    for (int i = 0; i < n; i++) weight(i);
    int mi = inf, mii, miy;
    for (int i = h[cv]; i != -1; i = t[i][2]) {
      y = t[i][0];
      if ((f[y][0] != cv) && (t[i][1] - mw[y] < mi)) {
        mi = t[i][1] - mw[y];
        mii = i;
        miy = t[i][0];
      }
    }
    if (mi == inf) {
      printf("-1\n");
      return 0;
    }
    out += mi;
    for (int i = miy, j = f[i][0], k = f[j][0], l = f[i][1];
         (t[l][1] != mw[miy]) && (k != cv); i = j, j = k, k = f[j][0]) {
      f[j][0] = i;
      swap(f[j][1], l);
      f[j][1] ^= 1;
    }
    f[miy][0] = cv;
    f[miy][1] = mii;
  }
  printf("%d\n", n - 1);
  flag = false;
  for (int i = 0; i < n; i++) {
    if (i != cv) {
      if (flag) printf(" ");
      flag = true;
      printf("%d", t[f[i][1]][3]);
    }
  }
  printf("\n");
  return 0;
}
