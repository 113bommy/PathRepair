#include <bits/stdc++.h>
template <class T>
bool chmax(T &val, T nv) {
  return val < nv ? (val = nv, true) : false;
}
template <class T>
bool chmin(T &val, T nv) {
  return nv < val ? (val = nv, true) : false;
}
using namespace std;
using ll = long long;
const int MAX_N = 200010, MAX_K = MAX_N;
int n, a[MAX_N], cnt[MAX_K], *pos = new int[MAX_N << 1] + MAX_N;
int cal(int x, int y) {
  int sum = 0, res = 0;
  0;
  fill(pos - n, pos + n, n);
  for (int i = 0; i <= n; ++i) {
    if (a[i] == x) ++sum;
    if (a[i] == y) --sum;
    0;
    chmax(res, i - pos[sum]);
    chmin(pos[sum], i);
  }
  0;
  return res;
}
int solve() {
  int p = max_element(cnt, cnt + MAX_K) - cnt, mx = cnt[p];
  int cntmx = 0;
  for (int i = 1; i < MAX_K; ++i) cntmx += mx == cnt[i];
  if (cntmx > 1) return n;
  int res = 0;
  int sec = 0, o = 0;
  for (int i = 1; i < MAX_K; ++i)
    if (mx != cnt[i] && chmax(sec, cnt[i])) o = i;
  vector<int> cand;
  for (int i = 1; i <= n; ++i)
    if (i != p) cand.emplace_back(i);
  sort(begin(cand), end(cand), [&](int a, int b) { return cnt[a] > cnt[b]; });
  int holan = 10;
  for (int o : cand) {
    if (holan-- < 0) break;
    chmax(res, cal(o, p));
  }
  return res;
}
int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];
  cout << solve() << '\n';
}
