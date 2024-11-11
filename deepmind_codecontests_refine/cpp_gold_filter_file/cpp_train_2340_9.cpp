#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000;
vector<pair<int, int> > out[MAXN];
int outl[MAXN], outr[MAXN];
int ma[MAXN];
int to[MAXN];
vector<int> ans;
bool _do(int v, int l, int r) {
  if (l > r) {
    ans.push_back(v);
    return 1;
  }
  int _ma = max(v, outl[v]);
  if (_ma > v) {
    for (int j = v + 1; j <= _ma; j = to[j] + 1) _ma = max(to[j], _ma);
  }
  if (_ma >= outr[v]) return 0;
  bool _ans = 1;
  if (_ma >= l) _ans &= _do(l, l + 1, _ma);
  ans.push_back(v);
  if (_ans && _ma < r) _ans &= _do(_ma + 1, _ma + 2, r);
  return _ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) outr[i] = n + 1;
  for (int i = 0; i < c; i++) {
    int a, b;
    string _t;
    cin >> a >> b >> _t;
    int t = (_t == "RIGHT");
    a--, b--;
    out[a].push_back(make_pair(b, t));
    if (b <= a) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    if (t) outr[a] = min(outr[a], b);
    if (!t) outl[a] = max(outl[a], b);
    ma[a] = max(ma[a], b);
    ma[b] = max(ma[b], a);
  }
  to[n - 1] = n - 1;
  for (int i = n - 2; i > 0; i--) {
    to[i] = i;
    for (int j = to[i] + 1; j <= ma[i]; j = to[i] + 1)
      to[i] = max(to[i], to[j]);
  }
  if (!_do(0, 1, n - 1))
    cout << "IMPOSSIBLE";
  else
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
  return 0;
}
