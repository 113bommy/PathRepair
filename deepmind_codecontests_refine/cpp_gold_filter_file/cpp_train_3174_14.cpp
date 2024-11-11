#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 9;
const long long mod = 1e9 + 7;
const int inf = 1e9 + 10;
stack<pair<long long, int> > st;
long long x[maxn], d[maxn], lft[maxn], rgt[maxn], f1[maxn], f2[maxn];
long long seg1[maxn * 4], seg2[maxn * 4];
void build1(int l = 0, int r = maxn, int id = 1) {
  if (r - l == 1) {
    seg1[id] = rgt[l];
    return;
  }
  int mid = (l + r) >> 1;
  build1(l, mid, id * 2);
  build1(mid, r, id * 2 + 1);
  seg1[id] = max(seg1[id * 2], seg1[id * 2 + 1]);
}
void build2(int l = 0, int r = maxn, int id = 1) {
  if (r - l == 1) {
    seg2[id] = lft[l];
    return;
  }
  int mid = (l + r) >> 1;
  build2(l, mid, id * 2);
  build2(mid, r, id * 2 + 1);
  seg2[id] = min(seg2[id * 2], seg2[id * 2 + 1]);
}
int get1(int st, int en, long long val, int l = 0, int r = maxn, int id = 1) {
  if (st >= r || en <= l || seg1[id] < val) return -1;
  int mid = (l + r) >> 1;
  if (st <= l && en >= r) {
    if (r - l == 1) return l;
    if (seg1[id * 2 + 1] >= val) return get1(st, en, val, mid, r, id * 2 + 1);
    return get1(st, en, val, l, mid, id * 2);
  } else
    return max(get1(st, en, val, l, mid, id * 2),
               get1(st, en, val, mid, r, id * 2 + 1));
}
int get2(int st, int en, long long val, int l = 0, int r = maxn, int id = 1) {
  if (st >= r || en <= l || seg2[id] > val) return 1e9;
  int mid = (l + r) >> 1;
  if (st <= l && en >= r) {
    if (r - l == 1) return l;
    if (seg2[id * 2] <= val) return get2(st, en, val, l, mid, id * 2);
    return get2(st, en, val, mid, r, id * 2 + 1);
  } else
    return min(get2(st, en, val, l, mid, id * 2),
               get2(st, en, val, mid, r, id * 2 + 1));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i <= n + 1; i++) cin >> x[i];
  for (int i = 1; i <= n; i++) cin >> d[i];
  fill(lft, lft + maxn, inf);
  fill(rgt, rgt + maxn, -1);
  st.push(make_pair(-1, n + 1));
  for (int i = n; i >= 1; i--) {
    while (st.top().second != n + 1 && st.top().first > x[i]) st.pop();
    long long cur = 2 * d[i] - (x[st.top().second] - x[i]);
    if (cur <= 0)
      lft[i] = inf;
    else {
      lft[i] = x[i] - cur;
      f1[i] = cur;
      st.push(make_pair(lft[i], i));
    }
  }
  while (st.top().second != n + 1 && st.top().first > x[0]) st.pop();
  if (st.size() > 1) return cout << 0 << "\n", 0;
  while (st.size()) st.pop();
  st.push(make_pair(-1, 0));
  for (int i = 1; i <= n; i++) {
    while (st.top().second != 0 && st.top().first < x[i]) st.pop();
    long long cur = 2 * d[i] - (x[i] - x[st.top().second]);
    if (cur <= 0)
      rgt[i] = -1;
    else {
      rgt[i] = x[i] + cur;
      f2[i] = cur;
      st.push(make_pair(rgt[i], i));
    }
  }
  rgt[0] = 1e9;
  lft[n + 1] = -1e9;
  build1();
  build2();
  double ans = (x[n + 1] - x[0]) / 2.0;
  for (int i = 1; i <= n; i++) {
    if (lft[i] == inf) continue;
    int id = get1(0, i, lft[i]);
    ans = min(ans, (x[i] - x[id]) / 2.0);
    if (lft[i] + 1 && rgt[i] + 1) ans = min(ans, (f1[i] + f2[i]) / 2.0);
  }
  for (int i = 1; i <= n; i++) {
    if (rgt[i] == -1) continue;
    int id = get2(i + 1, n + 2, rgt[i]);
    ans = min(ans, (x[id] - x[i]) / 2.0);
  }
  cout << fixed << setprecision(10) << ans << "\n";
}
