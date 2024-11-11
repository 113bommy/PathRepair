#include <bits/stdc++.h>
using namespace std;
const int N = 120100;
long long tag[N * 4], mn[N * 4], tval[N * 4], val[N * 4];
int mn_cnt[N * 4];
int q1, q2;
long long q3;
void pd(int o) {
  if (tag[o]) {
    tag[o * 2] += tag[o];
    tag[o * 2 + 1] += tag[o];
    mn[o * 2] += tag[o];
    mn[o * 2 + 1] += tag[o];
    tag[o] = 0;
  }
  if (tval[o]) {
    if (mn[o * 2] == mn[o])
      tval[o * 2] += tval[o], val[o * 2] += tval[o] * mn_cnt[o * 2];
    if (mn[o * 2 + 1] == mn[o])
      tval[o * 2 + 1] += tval[o], val[o * 2 + 1] += tval[o] * mn_cnt[o * 2 + 1];
    tval[o] = 0;
  }
}
void ps(int o) {
  mn[o] = min(mn[o * 2], mn[o * 2 + 1]);
  mn_cnt[o] = 0;
  if (mn[o] == mn[o * 2]) mn_cnt[o] += mn_cnt[o * 2];
  if (mn[o] == mn[o * 2 + 1]) mn_cnt[o] += mn_cnt[o * 2 + 1];
  val[o] = val[o * 2] + val[o * 2 + 1];
}
void bt(int o, int l, int r) {
  if (l == r) {
    mn[o] = l;
    mn_cnt[o] = 1;
    return;
  }
  int mid = (l + r) / 2;
  bt(o * 2, l, mid);
  bt(o * 2 + 1, mid + 1, r);
  ps(o);
}
void mdf(int o, int l, int r) {
  if (q1 <= l && r <= q2) {
    tag[o] += q3;
    mn[o] += q3;
    return;
  }
  int mid = (l + r) / 2;
  pd(o);
  if (q1 <= mid) mdf(o * 2, l, mid);
  if (q2 > mid) mdf(o * 2 + 1, mid + 1, r);
  ps(o);
}
void qry(int o, int l, int r) {
  if (q1 <= l && r <= q2) {
    q3 += val[o];
    return;
  }
  int mid = (l + r) / 2;
  pd(o);
  if (q1 <= mid) qry(o * 2, l, mid);
  if (q2 > mid) qry(o * 2 + 1, mid + 1, r);
}
int n, q, a[N], s1[N], s2[N];
long long ans[N];
vector<pair<int, int> > vec[N];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int x, y;
    cin >> x >> y;
    vec[y].emplace_back(x, i);
  }
  bt(1, 1, n);
  for (int i = 1, j = 0, k = 0; i <= n; ++i) {
    q1 = 1;
    q2 = n;
    q3 = -1;
    mdf(1, 1, n);
    for (; j && a[i] > a[s1[j]]; --j) {
      q1 = s1[j - 1] + 1;
      q2 = s1[j];
      q3 = a[i] - a[s1[j]];
      mdf(1, 1, n);
    }
    for (; k && a[i] < a[s2[k]]; --k) {
      q1 = s2[k - 1] + 1;
      q2 = s2[k];
      q3 = a[s2[k]] - a[i];
      mdf(1, 1, n);
    }
    s1[++j] = s2[++k] = i;
    tval[1]++;
    val[1] += mn_cnt[1];
    for (auto t : vec[i]) {
      q1 = t.first;
      q2 = i;
      q3 = 0;
      qry(1, 1, n);
      ans[t.second] = q3;
    }
  }
  for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
  return 0;
}
