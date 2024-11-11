#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n, m, k, a, b;
int c[maxn];
int ne;
struct edge {
  int n1, n2, c1, c2;
  long long val;
} e[maxn];
int cnt;
int pre[maxn * 2];
bool not_ok[maxn];
stack<pair<int, int> > roll;
bool cmp(edge a, edge b) { return a.val < b.val; }
long long find(int x) {
  int r = x, cnt = 0;
  while (pre[r] != r) {
    ++cnt;
    r = pre[r];
  }
  long long ans = (long long)cnt * maxn + r;
  if (cnt % 2 == 0) x = pre[x], --cnt;
  while (cnt > 6) {
    int i = pre[x];
    pre[x] = r;
    x = pre[i];
    cnt -= 2;
  }
  return ans;
}
bool join(int x, int y) {
  long long fx = find(x), fy = find(y);
  int rx = fx % maxn, ry = fy % maxn;
  int cx = fx / maxn, cy = fy / maxn;
  if (rx == ry) {
    return (cx + cy) % 2 == 1;
  } else {
    roll.push(pair<int, int>(rx, pre[rx]));
    if ((cx + cy) % 2)
      pre[rx] = ++n, pre[n] = ry;
    else
      pre[rx] = ry;
    return true;
  }
}
void roll_back() {
  while (!roll.empty()) {
    pair<int, int> pr = roll.top();
    roll.pop();
    pre[pr.first] = pr.second;
  }
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i <= m + n; ++i) pre[i] = i;
  cnt = k;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    if (c[a] == c[b]) {
      if (!join(a, b) && !not_ok[c[a]]) {
        --cnt;
        not_ok[c[a]] = 1;
      }
    } else {
      e[ne].n1 = a;
      e[ne].n2 = b;
      e[ne].c1 = min(c[a], c[b]);
      e[ne].c2 = max(c[a], c[b]);
      e[ne].val = (long long)e[ne].c1 * maxn + e[ne].c2;
      ++ne;
    }
  }
  sort(e, e + ne, cmp);
  while (!roll.empty()) roll.pop();
  long long ans = (long long)cnt * (cnt - 1) / 2;
  bool flag = 0;
  for (int i = 0; i < ne; ++i) {
    a = e[i].n1, b = e[i].n2;
    if (not_ok[c[a]] || not_ok[c[b]]) continue;
    if (i > 0 && e[i].val != e[i - 1].val) {
      flag = 0;
      roll_back();
    }
    if (!join(a, b)) {
      if (!flag) --ans;
      flag = 1;
    }
  }
  cout << ans;
  return 0;
}
