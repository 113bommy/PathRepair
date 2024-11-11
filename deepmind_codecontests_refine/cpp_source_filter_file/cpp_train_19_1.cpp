#include <bits/stdc++.h>
using namespace std;
int test = 0;
const int MAXN = 300009;
const long long MOD = 119 << 23 | 1;
class {
 public:
  vector<int> V[MAXN];
  int fa[MAXN], cnt[MAXN];
  int n, m;
  int findfa(int x) {
    if (fa[x] == x) return x;
    return fa[x] = findfa(fa[x]);
  }
  void merge(int x, int y) {
    x = findfa(x);
    y = findfa(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    fa[y] = x;
    cnt[x] += cnt[y];
  }
  void solve() {
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 1; i <= m; ++i) {
      int c;
      cin >> c;
      for (int j = 0; j < c; ++j) {
        int v;
        cin >> v;
        V[v].push_back(i);
      }
      fa[i] = i;
      fa[i + m] = i + m;
      cnt[i + m] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      bool on = s[i - 1] == '1';
      if (V[i].size() == 1) {
        int p = V[i][0];
        if (on) {
          ans -= cost(p);
          merge(p + m, 0);
          ans += cost(p);
        } else {
          ans -= cost(p);
          merge(p, 0);
          ans += cost(p);
        }
      } else if (V[i].size() == 2) {
        int p0 = V[i][0], p1 = V[i][1];
        if (on) {
          if (findfa(p0) != findfa(p1)) {
            ans -= cost(p0);
            ans -= cost(p1);
            merge(p0, p1);
            merge(p0 + m, p1 + m);
            ans += cost(p0);
          } else {
            ;
          }
        } else {
          if (findfa(p0) != findfa(p1 + m)) {
            ans -= cost(p0);
            ans -= cost(p1);
            merge(p0, p1 + m);
            merge(p0 + m, p1);
            ans += cost(p0);
          } else {
            ;
          }
        }
      }
      cout << ans << '\n';
    }
  }
  int cost(int x) {
    int y;
    if (x <= m) {
      y = m + x;
    } else {
      y = x - m;
    }
    x = findfa(x);
    y = findfa(y);
    if (x == 0)
      return cnt[y];
    else if (y == 0)
      return cnt[x];
    return min(cnt[x], cnt[y]);
  }
} NSPACE;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}
