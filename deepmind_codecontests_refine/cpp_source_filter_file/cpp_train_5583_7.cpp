#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int DEBUG, lim;
int n, k;
int a[N][6], b[N][6];
int fa[N], size[N];
int fd(int x) { return x == fa[x] ? x : fa[x] = fd(fa[x]); }
int cal(int x, int y) {
  x = fd(x);
  y = fd(y);
  for (int i = 1; i <= k; i++)
    if (b[x][i] > a[y][i]) return 1;
  return 0;
}
struct node {
  int x;
  bool operator<(const node &t) const {
    for (int i = 1; i <= k; i++)
      if (b[fd(x)][i] > a[fd(t.x)][i]) return 1;
    return 0;
  }
};
set<node> s;
void pri() {
  set<node>::iterator it;
  for (it = s.begin(); it != s.end(); it++) printf("%d ", (*it).x);
  puts("");
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> k;
  lim = pow(n, 0.41);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= k; j++) cin >> a[i][j], b[i][j] = a[i][j];
  for (int i = 1; i <= n; i++) fa[i] = i, size[i] = 1;
  if (n <= 2000) lim = n;
  for (int i = 1; i <= n; i++) {
    node pt;
    pt.x = i;
    set<node>::iterator t1, t2, it;
    t1 = s.lower_bound(pt), t2 = s.upper_bound(pt);
    it = t2;
    while (1) {
      int sp = (*it).x;
      if (fd(i) != fd(sp) && cal(sp, i) && cal(i, sp)) {
        sp = fd(sp);
        size[i] += size[sp];
        for (int j = 1; j <= k; j++) {
          a[i][j] = min(a[i][j], a[sp][j]);
          b[i][j] = max(b[i][j], b[sp][j]);
        }
        fa[sp] = i;
        DEBUG = 0;
      } else {
        if (fd(i) != fd(sp))
          break;
        else if (++DEBUG > lim)
          break;
      }
      if (it == s.end()) break;
      it++;
    }
    it = t2;
    while (1) {
      int sp = (*it).x;
      if (fd(sp) != fd(i) && cal(sp, i) && cal(i, sp)) {
        sp = fd(sp);
        size[i] += size[sp];
        for (int j = 1; j <= k; j++) {
          a[i][j] = min(a[i][j], a[sp][j]);
          b[i][j] = max(b[i][j], b[sp][j]);
        }
        fa[sp] = i;
        DEBUG = 0;
      } else {
        if (fd(i) != fd(sp))
          break;
        else if (++DEBUG > lim)
          break;
      }
      if (it == t1 || it == s.begin()) break;
      it--;
    }
    s.insert(pt);
    cout << size[fd((*s.begin()).x)] << "\n";
  }
  return 0;
}
