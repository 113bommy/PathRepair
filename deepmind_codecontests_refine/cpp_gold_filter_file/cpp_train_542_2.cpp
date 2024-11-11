#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 233;
int n, q, a[MAXN];
pair<int, int> mx[MAXN][18], mn[MAXN][18];
int lg[MAXN], tormx[MAXN], tormn[MAXN], tolmx[MAXN], tolmn[MAXN];
int bs3mx[MAXN], bs3mn[MAXN], bs4[MAXN];
vector<int> badmn[MAXN], badmx[MAXN], bad4[MAXN];
pair<int, int> qrymx(int l, int r) {
  int len = lg[r - l + 1];
  return max(mx[l][len], mx[r - (1 << len) + 1][len]);
}
pair<int, int> qrymn(int l, int r) {
  int len = lg[r - l + 1];
  return min(mn[l][len], mn[r - (1 << len) + 1][len]);
}
struct ST_T {
  pair<int, int> a[MAXN][18];
  void build() {
    for (int j = 1; j <= 17; ++j)
      for (int i = 1; i <= n; ++i) {
        if (i + (1 << j) - 1 <= n) {
          a[i][j] = min(a[i][j - 1], a[i + (1 << (j - 1))][j - 1]);
        }
      }
  }
  pair<int, int> query(int l, int r) {
    int len = lg[r - l + 1];
    return min(a[l][len], a[r - (1 << len) + 1][len]);
  }
} stmx, stmn, st4;
int main() {
  scanf("%d%d", &n, &q);
  lg[1] = 0;
  for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i)
    mx[i][0] = make_pair(a[i], i), mn[i][0] = make_pair(a[i], i);
  for (int j = 1; j <= 17; ++j)
    for (int i = 1; i <= n; ++i) {
      if (i + (1 << j) - 1 <= n) {
        mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
        mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
      }
    }
  for (int i = 1; i <= n; ++i)
    tormx[i] = tormn[i] = n + 1, tolmx[i] = tolmn[i] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    if (qrymx(i + 1, n).first > a[i]) {
      int l = i + 1, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (qrymx(i + 1, mid).first <= a[i])
          l = mid + 1;
        else
          r = mid;
      }
      tormx[i] = l + 1;
    }
    if (qrymn(i + 1, n).first < a[i]) {
      int l = i + 1, r = n;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (qrymn(i + 1, mid).first >= a[i])
          l = mid + 1;
        else
          r = mid;
      }
      tormn[i] = l + 1;
    }
  }
  for (int i = 2; i <= n; ++i) {
    if (qrymx(1, i - 1).first > a[i]) {
      int l = 1, r = i;
      while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (qrymx(mid, i - 1).first <= a[i])
          r = mid;
        else
          l = mid;
      }
      tolmx[i] = l - 1;
    }
    if (qrymn(1, i - 1).first < a[i]) {
      int l = 1, r = i;
      while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (qrymn(mid, i - 1).first >= a[i])
          r = mid;
        else
          l = mid;
      }
      tolmn[i] = l - 1;
    }
  }
  set<int> okmx, okmn, ok4;
  for (int i = 1; i <= n; ++i) {
    if (tolmx[i] != 0) okmx.insert(i);
    if (tolmn[i] != 0) okmn.insert(i);
    if (min(tolmx[i], tolmn[i]) != 0) ok4.insert(i);
    badmn[tolmn[i]].push_back(i);
    badmx[tolmx[i]].push_back(i);
    bad4[min(tolmn[i], tolmx[i])].push_back(i);
  }
  okmx.insert(n + 1);
  okmn.insert(n + 1);
  ok4.insert(n + 1);
  for (int i = 1; i <= n; ++i) {
    bs3mx[i] = *okmx.lower_bound(tormx[i]);
    bs3mn[i] = *okmn.lower_bound(tormn[i]);
    bs4[i] = *ok4.lower_bound(max(tormx[i], tormn[i]));
    for (auto it : badmn[i]) okmn.erase(it);
    for (auto it : badmx[i]) okmx.erase(it);
    for (auto it : bad4[i]) ok4.erase(it);
    stmx.a[i][0] = make_pair(bs3mx[i], i);
    stmn.a[i][0] = make_pair(bs3mn[i], i);
    st4.a[i][0] = make_pair(bs4[i], i);
  }
  stmx.build();
  stmn.build();
  st4.build();
  for (int i = 1; i <= q; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (st4.query(l, r).first <= r) {
      int z = st4.query(l, r).second;
      printf("4\n");
      int x, y;
      x = qrymx(z, bs4[z]).second;
      y = qrymn(z, bs4[z]).second;
      printf("%d %d %d %d\n", z, min(x, y), max(x, y), bs4[z]);
      continue;
    } else if (stmx.query(l, r).first <= r) {
      int z = stmx.query(l, r).second;
      printf("3\n%d %d %d\n", z, qrymx(z, bs3mx[z]).second, bs3mx[z]);
      continue;
    } else if (stmn.query(l, r).first <= r) {
      int z = stmn.query(l, r).second;
      printf("3\n%d %d %d\n", z, qrymn(z, bs3mn[z]).second, bs3mn[z]);
      continue;
    }
    puts("0");
  }
  return 0;
}
