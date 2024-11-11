#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long inf = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
const int N = 2e5 + 10;
int n, m;
vector<int> vc;
int p[N], s[N], b[N], inc[N], pref[N], ans[N];
struct BIT {
  int sum[N], n;
  int lowbit(int x) { return x & -x; }
  void add(int p, int x) {
    for (int i = p; i <= n; i += lowbit(i)) sum[i] += x;
  }
  int qry(int r) {
    int res = 0;
    for (int i = r; i > 0; i -= lowbit(i)) res += sum[i];
    return res;
  }
} b1, b2;
struct X {
  int p, x, y, op, id;
  bool operator<(const X& b) const { return p == b.p ? id < b.id : p < b.p; }
};
vector<X> vv;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &inc[i]);
  for (int i = 1; i <= m; i++) scanf("%d", &pref[i]);
  for (int i = 1; i <= n; i++) {
    vc.push_back(b[i] - p[i]);
    vc.push_back(b[i] + p[i] - 1);
  }
  for (int i = 1; i <= m; i++) {
    vc.push_back(inc[i] + pref[i]);
    vc.push_back(pref[i] - inc[i]);
  }
  sort(vc.begin(), vc.end());
  vc.erase(unique(vc.begin(), vc.end()), vc.end());
  b1.n = b2.n = (int)vc.size();
  for (int i = 1; i <= n; i++) {
    vv.push_back(X{p[i], b[i], p[i], 1, 0});
    vv.push_back(X{s[i] + 1, b[i], p[i], -1, 0});
  }
  for (int i = 1; i <= m; i++) {
    vv.push_back(X{inc[i], inc[i], pref[i], 0, i});
  }
  sort(vv.begin(), vv.end());
  for (auto t : vv) {
    if (t.id) {
      int x = lower_bound(vc.begin(), vc.end(), t.x + t.y) - vc.begin() + 1;
      int y = lower_bound(vc.begin(), vc.end(), t.y - t.x) - vc.begin() + 1;
      ans[t.id] = b1.qry(x) + b2.qry(y);
    } else {
      int x = lower_bound(vc.begin(), vc.end(), t.x + t.y) - vc.begin() + 1;
      int y = lower_bound(vc.begin(), vc.end(), t.x - t.y + 1) - vc.begin() + 1;
      b1.add(x, t.op);
      b2.add(y, -t.op);
    }
  }
  for (int i = 1; i <= m; i++) printf("%d%s", ans[i], i == m ? "\n" : " ");
  return 0;
}
