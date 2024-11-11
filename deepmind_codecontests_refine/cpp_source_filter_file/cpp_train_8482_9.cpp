#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 200010;
int n, m;
struct node {
  long long l, r;
  int id;
  bool operator<(const node &rhs) const { return r > rhs.r; }
} a[N];
struct pp {
  long long x;
  int pos;
} p[N];
int ans[N];
priority_queue<node> q;
bool cmp(const pp &e, const pp &r) { return e.x < r.x; }
bool cmp1(const node &z, const node &x) { return z.r < x.r; }
int main() {
  while (~scanf("%d%d", &n, &m)) {
    while (!q.empty()) q.pop();
    long long l, r, lll, rrr;
    for (int i = 1; i <= n; ++i) {
      ans[i] = -1;
      scanf("%lld%lld", &l, &r);
      if (i >= 2) {
        a[i].l = l - rrr;
        a[i].r = r - lll;
        a[i].id = i;
      }
      lll = l;
      rrr = r;
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%lld", &p[i].x);
      p[i].pos = i;
    }
    if (m < n - 1) {
      puts("No");
      continue;
    }
    sort(p + 1, p + m + 1, cmp);
    sort(a + 1, a + 1 + n, cmp1);
    int cur = 2;
    for (int i = 1; i <= m; ++i) {
      while (cur <= n && a[cur].l <= p[i].x) {
        q.push(a[cur]);
        cur++;
      }
      while (!q.empty()) {
        node c = q.top();
        q.pop();
        if (p[i].x <= c.r) {
          ans[c.id] = p[i].pos;
          break;
        }
      }
    }
    bool OK = 1;
    for (int i = 2; i <= n; ++i) {
      if (ans[i] == -1) {
        OK = 0;
        break;
      }
    }
    if (!OK)
      puts("No");
    else {
      puts("Yes");
      for (int i = 2; i <= n; ++i) printf("%d ", ans[i]);
      puts("");
    }
  }
  return 0;
}
