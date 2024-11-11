#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 2000000000;
const long long BIG = 1446803456761533460LL;
const int maxn = 100010;
const int maxnlg = 20;
int n, m, k;
vector<pair<int, int> > seg[maxn * 2];
void build() {
  for (int i = n; i < n + n; ++i) {
    sort((seg[i]).begin(), (seg[i]).end());
    for (int j = 1; j < seg[i].size(); ++j) {
      seg[i][j].second = max(seg[i][j].second, (seg[i][j - 1].second));
    }
  }
  for (int i = (n)-1; i >= 1; --i) {
    int n1 = seg[i << 1].size(), n2 = seg[i << 1 | 1].size();
    int p1 = 0, p2 = 0, p3 = 0, a = INF, b = INF;
    seg[i].resize(n1 + n2);
    while (p1 < n1 && p2 < n2) {
      if (seg[i << 1][p1].first < seg[i << 1 | 1][p2].first) {
        a = seg[i << 1][p1].second;
        seg[i][p3++] = {seg[i << 1][p1++].first, min(a, b)};
      } else {
        b = seg[i << 1 | 1][p2].second;
        seg[i][p3++] = {seg[i << 1 | 1][p2++].first, min(a, b)};
      }
    }
    while (p1 < n1) {
      a = seg[i << 1][p1].second;
      seg[i][p3++] = {seg[i << 1][p1++].first, min(a, b)};
    }
    while (p2 < n2) {
      b = seg[i << 1 | 1][p2].second;
      seg[i][p3++] = {seg[i << 1 | 1][p2++].first, min(a, b)};
    }
  }
}
bool check(int li, int ri, int ls, int rs) {
  for (li += n, ri += n; li < ri; li >>= 1, ri >>= 1) {
    if (li & 1) {
      int id =
          upper_bound((seg[li]).begin(), (seg[li]).end(), make_pair(rs, INF)) -
          seg[li].begin() - 1;
      if (id == -1 || seg[li][id].second < ls) return false;
      ++li;
    }
    if (ri & 1) {
      --ri;
      int id =
          upper_bound((seg[ri]).begin(), (seg[ri]).end(), make_pair(rs, INF)) -
          seg[ri].begin() - 1;
      if (id == -1 || seg[ri][id].second < ls) return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < k; ++i) {
    int l, r, c;
    cin >> l >> r >> c;
    --c;
    seg[n + c].emplace_back(r, l);
  }
  build();
  for (int i = 0; i < m; ++i) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    --a;
    bool ans = check(a, b, x, y);
    cout << (ans ? "yes\n" : "no\n");
    cout.flush();
  }
}
