#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, x, a[N], pre[N], suf[N], mn[N], mx[N];
pair<int, int> seg[5 * N + 5];
void update(int node, int st, int en, int idx, pair<long long, long long> pr) {
  if (st == en) {
    seg[node] = pr;
  } else {
    int mid = (st + en) / 2;
    if (idx >= st && idx <= mid)
      update(2 * node, st, mid, idx, pr);
    else
      update(2 * node + 1, mid + 1, en, idx, pr);
    seg[node] = {min(seg[2 * node].first, seg[2 * node + 1].first),
                 max(seg[2 * node].second, seg[2 * node + 1].second)};
  }
}
pair<int, int> query(int node, int st, int en, int l, int r) {
  if (st > r || en < l) {
    return {1061109567, 0};
  }
  if (l <= st && en <= r) return seg[node];
  int mid = (st + en) / 2;
  pair<int, int> lf = query(2 * node, st, mid, l, r),
                 rt = query(2 * node + 1, mid + 1, en, l, r);
  return {min(lf.first, rt.first), max(lf.second, rt.second)};
}
bool check(int l, int r) {
  if (pre[l - 1] && suf[r + 1] &&
      query(1, 0, x + 1, 0, l - 1).second <=
          query(1, 0, x + 1, r + 1, x + 1).first)
    return 1;
  return 0;
}
void Put(int i) { update(1, 0, x + 1, i, {mn[i], mx[i]}); }
void Sheel(int i) { update(1, 0, x + 1, i, {1061109567, 0}); }
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> x;
  memset(mn, '?', sizeof(mn));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    mx[a[i]] = max(mx[a[i]], i);
    mn[a[i]] = min(mn[a[i]], i);
  }
  pre[0] = suf[x + 1] = 1;
  int mxx = 0;
  for (int i = 1; i <= x; i++) {
    if (mn[i] > mxx)
      pre[i] = 1;
    else
      break;
    mxx = max(mxx, mx[i]);
  }
  int mnn = 1e9;
  for (int i = x; i > 0; i--) {
    if (mx[i] < mnn)
      suf[i] = 1;
    else
      break;
    mnn = min(mnn, mn[i]);
  }
  int j = 1;
  long long ans = 0;
  Sheel(0);
  Sheel(x + 1);
  for (int i = 2; i <= x; i++) {
    Put(i);
  }
  for (int i = 1; i <= x; i++) {
    while (!check(i, j) && j <= x) {
      Sheel(j);
      j++;
    }
    ans += (x - j + 1);
    Put(i);
    j = max(j, i + 1);
  }
  cout << ans << '\n';
  return 0;
}
