#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const double eps = 1e-8;
const int INF32 = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const unsigned long long mod2 = 1;
const int N = 5e3 + 5;
const int sz = (1 << 20);
int num[N], ans[N], cnt;
void dfs(int dpt, int fa) {
  ans[++cnt] = fa;
  int u = cnt;
  if (num[dpt]) {
    --num[dpt];
    dfs(dpt + 1, u);
  }
  if (num[dpt]) {
    --num[dpt];
    dfs(dpt + 1, u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  while (q--) {
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; ++i) {
      num[i] = 1;
      d -= i;
    }
    int l = 1, r = n - 1;
    while (d) {
      if (l - r < d) {
        ++l;
      } else {
        d += r - l;
        ++num[l];
        --num[r];
        --r;
        if (num[l] == (1 << min(l, 20))) ++l;
      }
      if (l >= r) break;
    }
    if (l == r && d) {
      cout << "NO" << '\n';
      continue;
    }
    cout << "YES" << '\n';
    cnt = 0;
    dfs(1, 0);
    for (int i = 2; i <= n; ++i) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
