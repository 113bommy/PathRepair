#include <bits/stdc++.h>
using namespace std;
int i, n, t, tot, j, ans, now, k, l, r, mm;
int s[6] = {500, 1000, 1500, 2000, 2500, 3000};
int a[5010][3], Tot[2][3], val[3], X[3], f[2][100][100][100];
vector<int> v;
struct pp {
  int l, r;
} p[6];
vector<pair<int, int> > B[5010];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline int work() {
  int i, ans = 0, Me, now, last, boom, m, j, k, kk, len, J, K, KK, t, I;
  for (i = 1; i <= n; i++) {
    last = 0;
    for (k = 0; k < 3; k++)
      if (a[i][k]) last += val[k] * (250 - abs(a[i][k])) / 250;
    B[i].clear();
    B[i].push_back(make_pair(0, last));
    for (j = 1; j <= 7; j++) {
      now = 0;
      for (k = 0; k < 3; k++)
        if ((1 << k) & j) {
          if (a[i][k] >= 0) {
            now = last;
            break;
          }
        } else if (a[i][k])
          now += val[k] * (250 - abs(a[i][k])) / 250;
      if (now != last) B[i].push_back(make_pair(j, now));
    }
    if (i == 1) Me = last + (X[0] + X[1] + X[2]) * 100;
    t = 0;
    for (j = 0; j <= 2; j++) t += (a[i][j] >= 0);
    if (t == 3 && last > Me) ans++;
  }
  memset(f, 1, sizeof(f));
  boom = f[0][0][0][0];
  f[0][0][0][0] = ans;
  m = v.size() - 1;
  l = 0;
  r = 1;
  for (i = 1; i <= m; i++, swap(l, r))
    for (j = 0; j <= min(i - 1, X[0]); j++)
      for (k = 0; k <= min(i - 1, X[1]); k++)
        for (kk = 0; kk <= min(i - 1, X[2]); kk++)
          if (f[l][j][k][kk] != boom) {
            len = B[v[i]].size();
            for (I = 0; I < len; I++) {
              J = j;
              K = k;
              KK = kk;
              if (B[v[i]][I].first & 1) J++;
              if (B[v[i]][I].first & 2) K++;
              if (B[v[i]][I].first & 4) KK++;
              f[r][J][K][KK] = min(f[r][J][K][KK],
                                   f[l][j][k][kk] + (Me < B[v[i]][I].second));
            }
            f[l][j][k][kk] = boom;
          }
  return f[l][X[0]][X[1]][X[2]];
}
int main() {
  n = read();
  v.push_back(0);
  for (i = 1; i <= n; i++) {
    t = 0;
    for (j = 0; j <= 2; j++) {
      a[i][j] = read();
      if (a[i][j] > 0)
        Tot[0][j]++;
      else if (a[i][j] < 0)
        t++, Tot[1][j]++;
    }
    if (t) v.push_back(i);
    tot += t;
  }
  if (tot >= 90) {
    puts("1");
    return 0;
  }
  ans = n + 1;
  for (i = 0; i <= n; i++) {
    if (n < 2 * i && 2 * i <= 2 * n) {
      if (!p[0].l) p[0].l = i;
      p[0].r = i;
    }
    if (n < 4 * i && 4 * i <= 2 * n) {
      if (!p[1].l) p[1].l = i;
      p[1].r = i;
    }
    if (n < 8 * i && 8 * i <= 2 * n) {
      if (!p[2].l) p[2].l = i;
      p[2].r = i;
    }
    if (n < 16 * i && 16 * i <= 2 * n) {
      if (!p[3].l) p[3].l = i;
      p[3].r = i;
    }
    if (n < 32 * i && 32 * i <= 2 * n) {
      if (!p[4].l) p[4].l = i;
      p[4].r = i;
    }
    if (32 * i <= n) {
      if (!p[5].l) p[5].l = i;
      p[5].r = i;
    }
  }
  mm = 6;
  for (i = 0; i < mm; i++) {
    val[0] = s[i];
    if (Tot[0][0] > p[i].r || Tot[0][0] + Tot[1][0] < p[i].l) continue;
    X[0] = min(Tot[1][0], Tot[1][0] - p[i].l + Tot[0][0]);
    for (j = 0; j < mm; j++) {
      val[1] = s[j];
      if (Tot[0][1] > p[j].r || Tot[0][1] + Tot[1][1] < p[j].l) continue;
      X[1] = min(Tot[1][1], Tot[1][1] - p[j].l + Tot[0][1]);
      for (k = 0; k < mm; k++) {
        val[2] = s[k];
        if (Tot[0][2] > p[k].r || Tot[0][2] + Tot[1][2] < p[k].l) continue;
        X[2] = min(Tot[1][2], Tot[1][2] - p[k].l + Tot[0][2]);
        ans = min(ans, work());
      }
    }
  }
  write(ans + 1);
}
