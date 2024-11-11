#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const long long INF = 8e18;
const int maxn = 2e5 + 5;
set<pair<int, int> > st[maxn];
struct node {
  int l, r, ans, pos;
} nd[maxn];
int n;
int f[maxn][20], lg[maxn], ans[maxn];
bool cmp(node a, node b) { return a.ans < b.ans; }
bool cmp2(node a, node b) { return a.pos < b.pos; }
inline void init() {
  lg[1] = 0, lg[2] = 1;
  for (int i = 3; i <= maxn - 5; ++i) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i <= n; ++i) f[i][0] = nd[i].l;
  for (int j = 1; j <= 18; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      f[i][j] = min(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
    }
  }
}
inline int Q(int l, int r) {
  int len = r - l + 1;
  len = lg[len];
  return min(f[l][len], f[r - (1 << len) + 1][len]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int x, y;
    cin >> x >> y;
    nd[i] = {x, y, 0, i};
    st[x].insert({y, i});
  }
  set<pair<int, int> > cur;
  for (int i = 1; i <= n; ++i) {
    for (auto &x : st[i]) cur.insert(x);
    auto x = *cur.begin();
    nd[x.second].ans = i;
    cur.erase(cur.begin());
  }
  sort(nd + 1, nd + 1 + n, cmp);
  init();
  int ok = -1;
  for (int i = 1; i <= n; ++i) {
    int l = nd[i].ans + 1, r = nd[i].r;
    if (l > r) continue;
    if (nd[i].ans >= Q(l, r)) {
      ok = nd[i].pos;
      break;
    }
  }
  sort(nd + 1, nd + 1 + n, cmp2);
  if (ok == -1) {
    cout << "YES" << '\n';
    for (int i = 1; i <= n; ++i) cout << nd[i].ans << ' ';
    return 0;
  }
  cout << "NO" << '\n';
  for (int i = 1; i <= n; ++i) cout << nd[i].ans << ' ';
  cout << '\n';
  int l = nd[ok].ans + 1, r = nd[ok].r;
  for (int j = 1; j <= n; ++j) {
    if (j == ok) continue;
    if (nd[j].ans >= l && nd[j].ans <= r && nd[ok].ans >= nd[j].l) {
      swap(nd[ok], nd[j]);
      break;
    }
  }
  for (int i = 1; i <= n; ++i) cout << nd[i].ans << ' ';
  cout << '\n';
  return 0;
}
