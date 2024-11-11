#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a, nxt, last, t, res;
vector<vector<int> > q;
int getK(int k) {
  if (t[1] < k) return n;
  int i = 1;
  while (i < t.size() >> 1) {
    if (t[i << 1] >= k)
      i <<= 1;
    else
      k -= t[i << 1], i = i << 1 | 1;
  }
  return i - (t.size() >> 1);
}
void update(int i, int v) {
  for (t[i += (t.size() >> 1)] += v; i > 1; i >>= 1)
    t[i >> 1] = t[i] + t[i ^ 1];
}
void solve() {
  for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
  for (int i = n - 1; i >= 0; i--) {
    if (last[a[i]] != -1) nxt[i] = last[a[i]];
    last[a[i]] = i;
  }
  for (int x = 1; x <= n; x++) q[0].push_back(x);
  for (int j = 0; j < n; j++)
    if (last[j] != -1) update(last[j], 1);
  for (int i = 0; i < n; i++) {
    for (int x : q[i]) {
      int tnxt = getK(x + 1);
      res[x]++;
      q[tnxt].push_back(x);
    }
    update(i, -1);
    if (nxt[i] != -1) update(nxt[i], 1);
  }
  for (int x = 1; x <= n; x++) cout << res[x] << ' ';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  a.resize(n);
  q.resize(n + 1);
  res.resize(n + 1);
  t.resize(1 << 18);
  nxt.assign(n, -1);
  last.assign(n, -1);
  solve();
}
