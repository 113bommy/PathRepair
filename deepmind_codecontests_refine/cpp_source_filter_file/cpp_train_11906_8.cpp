#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)6e5 + 228;
const char nxtl = '\n';
const int mod = (int)1e9 + 7;
const double eps = (double)1e-9;
template <typename T>
inline bool updmin(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool updmax(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
int n, m;
bool res[MAXN];
char s[555][555];
struct query {
  int asdfg, gfdsa, trewq, id;
  query(int _x1, int _x2, int _y2, int _id) {
    asdfg = _x1, gfdsa = _x2, trewq = _y2, id = _id;
  }
};
vector<query> v[555];
bitset<555> dp1[511][511], dp2[511][511];
void solve(int l = 1, int r = m) {
  if (l == r) {
    vector<int> tp(n + 2, 0);
    tp[n] = n + 1;
    for (int i = n - 1; i >= 1; --i) {
      if (s[i][r] == '#')
        tp[i] = i;
      else
        tp[i] = tp[i + 1];
    }
    for (auto &to : v[r]) {
      if (to.trewq == r && tp[to.gfdsa] > to.asdfg) {
        res[to.id] = 1;
      }
    }
    return;
  }
  int mid = l + r >> 1;
  solve(l, mid);
  solve(mid + 1, r);
  for (int i = mid; i >= l; --i) {
    for (int j = n; j >= 1; --j) {
      dp1[j][i] = 0;
      if (s[j][i] == '#') continue;
      if (i == mid) dp1[j][i].set(j, 1);
      if (j + 1 <= n) dp1[j][i] |= dp1[j + 1][i];
      if (i + 1 <= mid) dp1[j][i] |= dp1[j][i + 1];
    }
  }
  for (int i = mid; i <= r; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp2[j][i] = 0;
      if (s[j][i] == '#') continue;
      if (i == mid) dp2[j][i].set(j, 1);
      if (j - 1 > 0) dp2[j][i] |= dp2[j - 1][i];
      if (i - 1 > 0) dp2[j][i] |= dp2[j][i - 1];
    }
  }
  for (int i = mid + 1; i <= r; ++i) {
    for (auto &to : v[i]) {
      if (to.trewq <= mid && to.trewq >= l) {
        res[to.id] |=
            ((dp1[to.gfdsa][to.trewq] & dp2[to.asdfg][i]).count() > 0);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) cin >> s[i][j];
  }
  int q;
  cin >> q;
  for (int i = 1; i <= q; ++i) {
    int asdfg, qwert, gfdsa, trewq;
    cin >> asdfg >> qwert >> gfdsa >> trewq;
    v[trewq].push_back(query(gfdsa, asdfg, qwert, i));
  }
  solve();
  for (int i = 1; i <= q; ++i) {
    if (res[i])
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
