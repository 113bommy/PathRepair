#include <bits/stdc++.h>
using namespace std;
const long long M = 1048576;
long long tg[2222222], mx[2222222];
void pd(long long x) {
  if (!tg[x]) return;
  mx[x] += tg[x];
  if (x <= M) tg[x + x] += tg[x], tg[x + x + 1] += tg[x];
  tg[x] = 0;
}
void upd(int x) {
  pd(x + x);
  pd(x + x + 1);
  mx[x] = max(mx[x + x], mx[x + x + 1]);
}
void add(int x, int l, int r, int ql, int qr, int v) {
  if (r < ql || qr < l) return;
  if (ql <= l && r <= qr) {
    tg[x] += v;
    return;
  }
  int m = (l + r) >> 1;
  add(x + x, l, m, ql, qr, v);
  add(x + x + 1, m + 1, r, ql, qr, v);
  upd(x);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, r;
  cin >> n >> r;
  map<long long, vector<pair<long long, pair<long long, long long> > > > mp;
  vector<long long> com;
  r = 2 * r;
  pair<long long, long long> pr[n + 1];
  for (long long i = 1; i <= n; i++) {
    long long x, y;
    cin >> x >> y;
    long long xx = x, yy = y;
    x = xx + yy;
    y = xx - yy;
    pr[i].first = x;
    pr[i].second = y;
    com.push_back(y);
    com.push_back(y + r);
  }
  sort(com.begin(), com.end());
  for (long long i = 1; i <= n; i++) {
    long long st = lower_bound(com.begin(), com.end(), pr[i].second) -
                   com.begin(),
              en = lower_bound(com.begin(), com.end(), pr[i].second + r) -
                   com.begin();
    mp[pr[i].first].push_back({1, {st, en}});
    mp[pr[i].first + r + 1].push_back({-1, {st, en}});
  }
  long long ans = 0;
  for (auto i : mp) {
    for (auto j : i.second) {
      add(1, 0, M - 1, j.second.first, j.second.second, j.first);
    }
    ans = max(ans, mx[1]);
  }
  cout << ans << endl;
  return 0;
}
