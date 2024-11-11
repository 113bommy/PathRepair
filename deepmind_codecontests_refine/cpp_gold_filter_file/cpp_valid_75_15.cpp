#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
  return x * f;
}
vector<int> v[MAXN];
int n;
int ent[MAXN];
struct node {
  long long l, r, k;
  bool operator<(node b) const {
    if (l != b.l) return l < b.l;
    return r < b.r;
  }
};
void solve() {
  cin >> n;
  vector<node> vv;
  for (int i = 1; i <= n; ++i) {
    int k;
    cin >> k;
    node tmp;
    tmp.l = tmp.r = 0;
    for (int j = 1; j <= k; ++j) {
      long long x;
      cin >> x;
      tmp.l = max(tmp.l, x - j + 2);
    }
    tmp.r = tmp.l + k;
    tmp.k = k;
    vv.push_back(tmp);
  }
  sort(vv.begin(), vv.end());
  int ans = vv[0].l;
  int len = vv.size();
  int now = vv[0].l + vv[0].k;
  for (int i = 1; i < len; i++) {
    if (now >= vv[i].l)
      now += vv[i].k;
    else {
      ans += vv[i].l - now;
      now = vv[i].r;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
  return 0;
}
