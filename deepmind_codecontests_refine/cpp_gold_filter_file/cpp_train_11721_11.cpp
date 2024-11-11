#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e15;
const long long max_n = (1 << 17);
long long sum[2 * max_n];
void upd(long long id, long long v = 1, long long l = 0,
         long long r = max_n - 1, long long num = 0) {
  if (l > id || r < id) return;
  if (l == id && r == id) {
    sum[v] = num;
    return;
  }
  long long m = (l + r) / 2;
  upd(id, v * 2, l, m, num);
  upd(id, v * 2 + 1, m + 1, r, num);
  sum[v] = sum[v * 2] + sum[v * 2 + 1];
}
void build(vector<long long> a) {
  for (long long i = 0; i < (long long)(a.size()); i++) {
    upd(i, 1, 0, max_n - 1, a[i]);
  }
}
long long get(long long left, long long &cnt, long long v = 1, long long l = 0,
              long long r = max_n - 1) {
  if (r < left) return -1;
  long long num = r - l + 1 - sum[v];
  if (l >= left && num <= cnt) {
    cnt -= num;
    return r;
  }
  if (l == r) {
    cnt -= num;
    return -1;
  }
  long long m = (l + r) / 2;
  long long r1, r2 = -1;
  r1 = get(left, cnt, v * 2, l, m);
  if (cnt >= 0) r2 = get(left, cnt, v * 2 + 1, m + 1, r);
  return max(r1, r2);
}
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  vector<long long> last(n + 1, inf);
  vector<long long> nxt(n);
  vector<long long> temp(n);
  for (long long i = n - 1; i >= 0; i--) {
    nxt[i] = last[a[i]];
    last[a[i]] = i;
  }
  for (long long i = 0; i < n; i++) {
    if (nxt[i] < n) temp[nxt[i]] = 1;
  }
  build(temp);
  vector<deque<pair<long long, long long>>> req(n + 1);
  for (long long i = n; i >= 1; i--) req[0].emplace_back(i, 0);
  for (long long i = 0; i < n; i++) {
    while ((long long)(req[i].size())) {
      pair<long long, long long> v = req[i].back();
      req[i].pop_back();
      v.second++;
      long long cnt = v.first;
      long long temp = get(i, cnt) + 1;
      req[min(n, temp)].emplace_back(v);
    }
    if (nxt[i] < n) upd(nxt[i]);
  }
  vector<long long> res(n);
  for (auto i : req[n]) {
    res[i.first - 1] = i.second;
  }
  for (long long i : res) cout << i << " ";
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
}
