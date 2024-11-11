#include <bits/stdc++.h>
using namespace std;
template <class T>
bool setmax(T &_a, T _b) {
  if (_b > _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
bool setmin(T &_a, T _b) {
  if (_b < _a) {
    _a = _b;
    return true;
  }
  return false;
}
template <class T>
T gcd(T _a, T _b) {
  return _b == 0 ? _a : gcd(_b, _a % _b);
}
const int MAXN = 110, MAXM = 110;
const int MAXNum = 3030;
int a[MAXN], xi[MAXM], xj[MAXM];
int n, m;
int vals[MAXNum], st[MAXN], en[MAXN];
int num;
vector<int> es[MAXNum];
int lnk[MAXNum];
bool vis[MAXNum];
bool find(int x) {
  for (int y : es[x])
    if (!vis[y]) {
      vis[y] = true;
      if (lnk[y] == 0 || find(lnk[y])) {
        lnk[y] = x;
        return true;
      }
    }
  return false;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = int(1); i <= int(n); ++i) scanf("%d", &a[i]);
  for (int j = int(1); j <= int(m); ++j) scanf("%d%d", &xi[j], &xj[j]);
  num = 0;
  for (int i = int(1); i <= int(n); ++i) {
    int x = a[i];
    st[i] = num + 1;
    for (int y = 2; y * y <= x; ++y)
      while (x % y == 0) {
        vals[++num] = y;
        x /= y;
      }
    if (x > 1) vals[++num] = x;
    en[i] = num;
  }
  for (int i = int(1); i <= int(num); ++i) es[i].clear();
  for (int k = int(1); k <= int(m); ++k) {
    int i = xi[k], j = xj[k];
    if (i % 2 != 1) swap(i, j);
    for (int x = int(st[i]); x <= int(en[i]); ++x)
      for (int y = int(st[j]); y <= int(en[j]); ++y)
        if (vals[x] == vals[y]) es[x].push_back(y);
  }
  memset(lnk, 0, sizeof(lnk));
  int ans = 0;
  for (int i = int(1); i <= int(n); ++i)
    if (i % 2 == 1)
      for (int x = int(st[i]); x <= int(en[i]); ++x) {
        memset(vis, false, sizeof(vis));
        if (find(i)) ++ans;
      }
  printf("%d\n", ans);
  return 0;
}
