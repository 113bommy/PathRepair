#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000 * 1000;
vector<pair<int, int> > in[MAXN], out[MAXN];
int ma[MAXN];
vector<int> ans;
bool _do(int v, int l, int r) {
  if (l > r) {
    ans.push_back(v);
    return 1;
  }
  int _ma = v;
  for (pair<int, int> to : out[v]) {
    if (to.second == 0) _ma = max(_ma, to.first);
  }
  for (int i = v + 1; i < _ma; i++) _ma = max(_ma, ma[i]);
  for (pair<int, int> to : out[v])
    if (to.second == 1 && to.first <= _ma) return 0;
  bool _ans = 1;
  if (_ma >= l) _ans &= _do(l, l + 1, _ma);
  ans.push_back(v);
  if (_ma < r) _ans &= _do(_ma + 1, _ma + 2, r);
  return _ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < c; i++) {
    int a, b;
    string _t;
    cin >> a >> b >> _t;
    int t = (_t == "RIGHT");
    a--, b--;
    in[b].push_back(make_pair(a, t));
    out[a].push_back(make_pair(b, t));
    if (b <= a) {
      cout << "IMPOSSIBLE";
      return 0;
    }
    ma[a] = max(ma[a], b);
    ma[b] = max(ma[b], a);
  }
  if (!_do(0, 1, n - 1))
    cout << "IMPOSSIBLE";
  else
    for (int i = 0; i < n; i++) cout << ans[i] + 1 << " ";
  return 0;
}
