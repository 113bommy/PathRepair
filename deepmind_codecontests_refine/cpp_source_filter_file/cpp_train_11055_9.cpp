#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
struct station {
  int t, a, b;
  bool operator<(const station &A) const { return t < A.t; }
} sta[N];
int stk[N], r[N];
int n, m, c0, c;
inline void solve() {
  scanf("%d%d%d%d", &n, &m, &c, &c0);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d%d", &sta[i].t, &sta[i].a, &sta[i].b);
  }
  sort(sta + 1, sta + 1 + n);
  sta[n + 1].t = m, sta[n + 1].a = 0, sta[n + 1].b = 0;
  map<int, int> q;
  long long res = 0;
  q[0] = c0;
  int sum = c0;
  for (int i = 1; i <= n + 1; i++) {
    int t = sta[i].t;
    int cnt = sta[i].a;
    int cost = sta[i].b;
    int dist = t - sta[i - 1].t;
    while (q.size() && dist != 0) {
      int can = min(q.begin()->second, dist);
      res += 1ll * can * q.begin()->first;
      dist -= can;
      sum -= can;
      q.begin()->second -= can;
      if (q.begin()->second == 0) q.erase(q.begin());
    }
    if (dist > 0) {
      puts("-1");
      return;
    }
    int add = min(c - sum, cnt);
    sum += add;
    while (add < cnt && q.rbegin()->first > cost && !q.empty()) {
      if (sta[i].a - add >= q.rbegin()->second) {
        add += q.rbegin()->second;
        q.erase(--q.end());
      } else {
        q.rbegin()->second -= cnt - add;
        add = cnt;
      }
    }
    q[cost] = add;
  }
  printf("%lld\n", res);
}
int main() {
  int _ = 1;
  scanf("%d", &_);
  while (_--) {
    solve();
  }
  return 0;
}
