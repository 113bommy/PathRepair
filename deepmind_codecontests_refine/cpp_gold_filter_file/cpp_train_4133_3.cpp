#include <bits/stdc++.h>
using namespace std;
const int maxn = 1.2e5 + 5;
int val[maxn];
int num[maxn << 2], tot[maxn << 2], tag[maxn << 2], tt[maxn << 2];
long long sum[maxn << 2];
void up(int t) {
  num[t] = min(num[t << 1], num[t << 1 | 1]);
  tot[t] = 0;
  if (num[t] == num[t << 1]) tot[t] += tot[t << 1];
  if (num[t] == num[t << 1 | 1]) tot[t] += tot[t << 1 | 1];
  sum[t] = sum[t << 1] + sum[t << 1 | 1];
  return;
}
void down(int t) {
  if (tag[t]) {
    num[t << 1] += tag[t], num[t << 1 | 1] += tag[t];
    tag[t << 1] += tag[t], tag[t << 1 | 1] += tag[t];
    tag[t] = 0;
  }
  if (tt[t]) {
    if (num[t << 1] == num[t])
      sum[t << 1] += 1ll * tot[t << 1] * tt[t], tt[t << 1] += tt[t];
    if (num[t << 1 | 1] == num[t])
      sum[t << 1 | 1] += 1ll * tot[t << 1 | 1] * tt[t], tt[t << 1 | 1] += tt[t];
    tt[t] = 0;
  }
}
void build(int l, int r, int t) {
  if (l == r) {
    num[t] = tot[t] = 1;
    return;
  }
  int mid = (l + r) >> 1;
  build(l, mid, t << 1);
  build(mid + 1, r, t << 1 | 1);
  up(t);
  return;
}
void update(int ll, int rr, int l, int r, int nu, int t) {
  if (ll <= l && r <= rr) {
    tag[t] += nu;
    num[t] += nu;
    return;
  }
  int mid = (l + r) >> 1;
  down(t);
  if (ll <= mid) update(ll, rr, l, mid, nu, t << 1);
  if (rr > mid) update(ll, rr, mid + 1, r, nu, t << 1 | 1);
  up(t);
  return;
}
long long query(int ll, int rr, int l, int r, int t) {
  if (ll <= l && r <= rr) {
    return sum[t];
  }
  int mid = (l + r) >> 1;
  down(t);
  long long tmp = 0;
  if (ll <= mid) tmp += query(ll, rr, l, mid, t << 1);
  if (rr > mid) tmp += query(ll, rr, mid + 1, r, t << 1 | 1);
  return tmp;
}
stack<pair<int, int> > mn, mx;
long long ans[maxn];
vector<pair<int, int> > opt[maxn];
int owo[maxn];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int b;
    cin >> b;
    val[i] = b;
  }
  int Q;
  cin >> Q;
  for (int i = 1; i <= Q; ++i) {
    int l, r;
    cin >> l >> r;
    opt[r].emplace_back(l, i);
  }
  mx.emplace(0, 2e9), mn.emplace(0, 0);
  build(1, n, 1);
  for (int i = 1; i <= n; ++i) {
    int p, q;
    while ((!mx.empty()) && mx.top().second <= val[i]) {
      tie(p, q) = mx.top();
      mx.pop();
      update(mx.top().first + 1, p, 1, n, val[i] - q, 1);
    }
    mx.emplace(i, val[i]);
    while ((!mn.empty()) && mn.top().second >= val[i]) {
      tie(p, q) = mn.top();
      mn.pop();
      update(mn.top().first + 1, p, 1, n, q - val[i], 1);
    }
    mn.emplace(i, val[i]);
    update(1, i, 1, n, -1, 1);
    ++tt[1], sum[1] += tot[1];
    for (auto x : opt[i]) {
      tie(p, q) = x;
      ans[q] += query(p, i, 1, n, 1);
    }
  }
  for (int i = 1; i <= Q; ++i) cout << ans[i] << '\n';
  return 0;
}
