#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 50;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
inline long long cede(long long a, long long b) {
  if (b < 0) return cede(-a, -b);
  if (a < 0) return a / b;
  return (a + b - 1) / b;
}
inline long long flde(long long a, long long b) {
  if (b < 0) return flde(-a, -b);
  if (a < 0) return (a - b + 1) / b;
  return a / b;
}
int a[MAXN];
set<pair<int, int> > st[MAXN];
set<pair<int, int> > sst[MAXN];
struct S {
  int pos, f;
  bool operator<(const S &R) const {
    return pos == R.pos ? f < R.f : pos < R.pos;
  }
} s[MAXN];
void add(int i, int x, int y) {
  if (x > y) return;
  sst[i].insert({x, y});
}
void work() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  sort(a + 1, a + 1 + n);
  int l = 0, r = INF;
  for (int i = 1; i <= n; i++) {
    int vv = (n - i) % k;
    l = max(l, a[i] - i + 1);
    int nr = a[i] - 1;
    int nl = a[i] + 1 - n;
    st[(a[i] % k - i % k + k) % k].insert({nl, nr});
    if (vv == 0) l = max(l, nl);
    if (vv == n % k) r = min(r, nr);
  }
  set<int> ans;
  for (int i = 0; i < k; i++) {
    int cntS = 0;
    for (auto x : st[i]) {
      s[++cntS] = {x.first, 0};
      s[++cntS] = {x.second, 1};
    }
    sort(s + 1, s + 1 + cntS);
    int now = 0, lasL = l;
    for (int j = 1; j <= cntS; j++) {
      if (now == 0) add(i, lasL, min(r, s[j].pos));
      if (s[j].f)
        now--;
      else
        now++;
      if (now == 0) lasL = max(s[j].pos, l);
    }
    add(i, lasL, r);
  }
  for (int i = 0; i < k; i++) {
    for (auto x : sst[i]) {
      int QAQ = cede(x.first - i, k) * k;
      for (; QAQ <= x.second - i; QAQ += k) ans.insert(QAQ + i);
    }
  }
  printf("%d\n", ans.size());
  for (auto x : ans) printf("%d ", x);
}
int main() { work(); }
