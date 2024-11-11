#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 1;
const int MN = 200000;
int t[MN * 4];
int ar[MN];
void build(int v, int l, int r) {
  if (l + 1 == r) {
    t[v] = 1;
    return;
  }
  int m = (l + r) / 2;
  build(v * 2, l, m);
  build(v * 2 + 1, m, r);
  t[v] = t[v * 2] + t[v * 2 + 1];
}
void st(int v, int l, int r, int lf, int rf) {
  if (lf >= r || rf <= l) return;
  if (lf <= l && r <= rf) {
    t[v] = 0;
    return;
  }
  int m = (l + r) / 2;
  st(v * 2, l, m, lf, rf);
  st(v * 2 + 1, m, r, lf, rf);
  t[v] = t[v * 2] + t[v * 2 + 1];
}
int gt(int v, int l, int r, int x) {
  if (t[v] < x) {
    return -1;
  }
  if (l + 1 == r) {
    return l;
  }
  int m = (l + r) / 2;
  auto ans = gt(v * 2, l, m, x);
  if (ans == -1) return gt(v * 2 + 1, m, r, x - t[v * 2]);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  set<pair<int, int>> s;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    s.insert({ar[i], -i});
  }
  int m;
  cin >> m;
  vector<tuple<int, int, int>> v;
  for (int i = 0; i < m; i++) {
    int k, p;
    cin >> k >> p;
    v.emplace_back(k - 1, p - 1, i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int ans[m];
  int last = n - 1;
  build(1, 0, n);
  for (auto [k, p, i] : v) {
    while (k < last) {
      auto t = *s.begin();
      s.erase(t);
      st(1, 0, n, -t.second, -t.second + 1);
      last--;
    }
    ans[i] = gt(1, 0, n, p + 1);
  }
  for (int i = 0; i < m; i++) {
    cout << ar[ans[i]] << '\n';
  }
}
