#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
const int MAX = 100005;
int a[MAX], par[MAX], rev[MAX];
int main() {
  ios::sync_with_stdio(false);
  int n, l, r, Ql, Qr;
  cin >> n >> l >> r >> Ql >> Qr;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) par[i] = par[i - 1] + a[i];
  for (int i = n; i >= 1; i--) rev[i] = rev[i + 1] + a[i];
  int ans = INF;
  for (int i = 1; i <= n; i++) {
    int m = par[i] * l + rev[i + 1] * r;
    if (n - i > i) m += (n - i - i - 1) * Qr;
    if (n - i < i) m += (i - n + i - 1) * Ql;
    ans = min(ans, m);
  }
  cout << ans;
  return 0;
}
