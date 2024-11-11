#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
const int blocksize = 400;
const int inf = 1000000000;
struct fish {
  int time, lim, v;
} a[maxn];
bool cmp(fish a, fish b) { return a.time < b.time; }
FILE *fp;
long long orians[maxn / blocksize + 2][maxn];
long long ans, slim[maxn], sv[maxn];
int cur[maxn], lim[maxn], v[maxn], l[maxn], r[maxn], i, j, n, m, n2,
    belong[maxn], curt[maxn], ori[maxn];
void init() {
  fscanf(fp, "%d", &n);
  for (int i = 1; i <= n; ++i) {
    fscanf(fp, "%d%d%d", &cur[i], &lim[i], &v[i]);
    a[i].time = v[i] == 0 ? inf : lim[i] / v[i] + (lim[i] % v[i] == 0 ? 0 : 1);
    a[i].lim = lim[i];
    a[i].v = v[i];
  }
  memset(orians, 0, sizeof(orians));
  n2 = 0;
  for (int i = 1; i <= n / blocksize; ++i) {
    n2++, l[n2] = (n2 - 1) * blocksize + 1, r[n2] = n2 * blocksize;
    sort(a + l[n2], a + r[n2] + 1, cmp);
    slim[l[n2]] = a[l[n2]].lim;
    for (int j = l[n2] + 1; j <= r[n2]; ++j) slim[j] = slim[j - 1] + a[j].lim;
    sv[r[n2]] = a[r[n2]].v;
    for (int j = r[n2] - 1; j >= l[n2]; --j) sv[j] = sv[j + 1] + a[j].v;
    int tmp = l[n2];
    if (i == 2) {
    }
    for (int j = 0; j <= maxn; ++j) {
      while (tmp <= r[n2] && a[tmp].time <= j) ++tmp;
      orians[n2][j] = (tmp <= r[n2] ? (long long)j * sv[tmp] : 0) +
                      (tmp > l[n2] ? slim[tmp - 1] : 0);
    }
  }
  if (n % blocksize != 0) {
    n2++;
    l[n2] = (n2 - 1) * blocksize + 1;
    r[n2] = n;
    sort(a + l[n2], a + r[n2] + 1, cmp);
    slim[l[n2]] = a[l[n2]].lim;
    for (int j = l[n2] + 1; j <= r[n2]; ++j) slim[j] = slim[j - 1] + a[j].lim;
    sv[r[n2]] = a[r[n2]].v;
    for (int j = r[n2] - 1; j >= l[n2]; --j) sv[j] = sv[j + 1] + a[j].v;
    int tmp = l[n2];
    for (int j = 0; j <= maxn; ++j) {
      while (tmp <= r[n2] && a[tmp].time <= j) ++tmp;
      orians[n2][j] = (tmp <= r[n2] ? (long long)j * sv[tmp] : 0) +
                      (tmp > l[n2] ? slim[tmp - 1] : 0);
    }
  }
  for (int i = 1; i <= n2; ++i)
    for (int j = l[i]; j <= r[i]; ++j) belong[j] = i;
}
void spread(int bid, int lbound, int rbound, int t) {
  for (int i = l[bid]; i <= lbound - 1; ++i) {
    long long tmp = (t - curt[bid]) * (long long)v[i] + cur[i];
    cur[i] = tmp <= lim[i] ? tmp : lim[i];
  }
  for (int i = rbound + 1; i <= r[bid]; ++i) {
    long long tmp = (t - curt[bid]) * (long long)v[i] + cur[i];
    cur[i] = tmp <= lim[i] ? tmp : lim[i];
  }
  for (int i = lbound; i <= rbound; ++i) {
    long long tmp = (t - curt[bid]) * (long long)v[i] + cur[i];
    ans += tmp <= lim[i] ? tmp : lim[i];
    cur[i] = 0;
  }
  ori[bid] = 0;
  curt[bid] = t;
}
void calc(int bid, int t) {
  if (ori[bid]) {
    ans += orians[bid][(t - curt[bid]) > maxn ? maxn : (t - curt[bid])];
    curt[bid] = t;
  } else {
    for (int i = l[bid]; i <= r[bid]; ++i) {
      long long tmp = (t - curt[bid]) * (long long)v[i] + cur[i];
      ans += tmp <= lim[i] ? tmp : lim[i];
      cur[i] = 0;
    }
    ori[bid] = 1;
    curt[bid] = t;
  }
}
void work() {
  memset(ori, 0, sizeof(ori));
  memset(curt, 0, sizeof(curt));
  fscanf(fp, "%d", &m);
  for (int i = 1; i <= m; ++i) {
    int x, y, t;
    fscanf(fp, "%d%d%d", &t, &x, &y);
    int xx = belong[x];
    int yy = belong[y];
    ans = 0;
    if (i == 4) {
    }
    if (xx == yy)
      spread(xx, x, y, t);
    else {
      spread(xx, x, r[xx], t);
      spread(yy, l[yy], y, t);
      for (int j = xx + 1; j <= yy - 1; ++j) calc(j, t);
    }
    printf("%I64d\n", ans);
  }
}
int main() {
  fp = stdin;
  init();
  work();
  return 0;
}
