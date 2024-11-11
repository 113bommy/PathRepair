#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 100;
int n, a[N], id[N], mx, ans[N], sta[N];
set<int> equ, ed0;
struct dsu {
  int fa[N];
  void init() {
    for (int i = 1; i <= n; ++i) fa[i] = i;
  }
  int getfa(int x) { return x == fa[x] ? x : fa[x] = getfa(fa[x]); }
  void merge(int x, int y) { fa[getfa(x)] = getfa(y); }
} L, R;
void mdf(int x) {
  int l = L.getfa(x), r = R.getfa(x), pos;
  if (l < r || x == 1 || x == n) {
    set<int>::iterator it = equ.lower_bound(l);
    if (l > 1 && it != equ.begin()) {
      it--;
      pos = (*it) + 1;
      mx = max(mx, (l - pos) >> 1),
      l = sta[pos] ? pos + 1 : ((pos + l) >> 1) + 1;
    }
    it = equ.upper_bound(r);
    if (it != equ.end()) {
      pos = (*it);
      mx = max(mx, (pos - r) >> 1), r = sta[pos] ? pos - 1 : ((pos + r) >> 1);
    }
  } else {
    set<int>::iterator it1 = equ.lower_bound(l);
    it1--;
    set<int>::iterator it2 = equ.upper_bound(r);
    int nl = (*it1) + 1, nr = (*it2);
    mx = max(mx, (nr - nl) >> 1);
    if (sta[nl] && sta[nr]) l = nl + 1, r = nr - 1;
    if (sta[nl] && !sta[nr]) l = nl + 1, r = ((nl + nr) >> 1);
    if (!sta[nl] && sta[nr]) l = ((nl + nr) >> 1) + 1, r = nr - 1;
    if (!sta[nl] && !sta[nr]) l = 1, r = 0;
  }
  if (l <= r) {
    set<int>::iterator it = ed0.lower_bound(l), las = it;
    while (it != ed0.end() && (*it) <= r) {
      ans[(*it)] = a[x], las = it, it++, ed0.erase(las);
    }
  }
}
bool cmpa(int x, int y) { return a[x] < a[y]; }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), id[i] = i;
  if (n == 1) {
    printf("0\n%d", a[1]);
    return 0;
  }
  if (n == 2) {
    printf("0\n%d %d", a[1], a[2]);
    return 0;
  }
  for (int i = 0; i <= n; ++i) equ.insert(i);
  for (int i = 1; i <= n; ++i) ed0.insert(i);
  sort(id + 1, id + n + 1, cmpa);
  L.init(), R.init();
  for (int i = 1; i <= n; ++i) {
    if (a[id[i]] == a[id[i - 1]]) continue;
    int l = i, r = i, x;
    while (a[id[r + 1]] == a[id[r]]) ++r;
    for (int j = l; j <= r; ++j) {
      x = id[j];
      if (!sta[x - 1]) equ.erase(x - 1);
      if (!sta[x + 1]) equ.erase(x);
      sta[x] = 1;
      if (x == 1) sta[0] = 1;
      if (x == n) sta[n + 1] = 1;
      if (sta[x - 1]) equ.insert(x - 1);
      if (sta[x + 1]) equ.insert(x);
      if (x > 1 && sta[x - 1]) L.merge(x, x - 1), R.merge(x - 1, x);
      if (x < n && sta[x + 1]) R.merge(x, x + 1), L.merge(x + 1, x);
    }
    for (int j = l; j <= r; ++j) {
      mdf(id[j]);
    }
  }
  printf("%d\n", mx);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
