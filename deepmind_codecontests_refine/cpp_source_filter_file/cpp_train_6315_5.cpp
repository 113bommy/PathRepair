#include <bits/stdc++.h>
using namespace std;
struct ex {
  long long s, d, c, idx;
  ex() {}
  ex(long long x, long long y, long long j, long long ii) {
    s = x;
    d = y;
    c = j;
    idx = ii;
  }
  bool operator<(const ex& p) const { return d > p.d; }
};
void solve() {
  long long n, m;
  cin >> n >> m;
  vector<ex> v(m);
  for (long long i = 0; i < m; i++) {
    cin >> v[i].s >> v[i].d >> v[i].c;
    v[i].idx = i + 1;
  }
  sort((v).begin(), (v).end());
  vector<long long> ans(n, 0);
  for (long long i = 0; i < m; i++) {
    ans[v[i].d - 1] = m + 1;
  }
  bool ok = 1;
  for (long long i = 0; ok && i < m; i++) {
    long long wh = 0;
    for (long long j = v[i].s - 1; j < v[i].d - 1; j++)
      if (ans[j] == 0) wh++;
    if (wh >= v[i].c) {
      for (long long j = v[i].s - 1, kk = 0; kk < v[i].c && j < v[i].d - 1; j++)
        if (ans[j] == 0) {
          ans[j] = v[i].idx;
          kk++;
        }
    } else
      ok = 0;
  }
  if (ok) {
    for (auto X : ans) cout << X << " ";
    cout << "\n";
  } else
    cout << "-1\n";
}
int32_t main() {
  ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long T = 1;
  while (T--) solve();
  return 0;
}
