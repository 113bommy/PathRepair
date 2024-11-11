#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long double PI = 4 * atan(1);
int n, k, d, a[500001], cur, dp[2000001], lo = 1;
int query(int l, int r, int p, int L, int R) {
  if (l > R || r < L) return 0;
  if (l >= L && r <= R) return dp[p];
  int mid = (l + r) / 2;
  return query(l, mid, 2 * p + 1, L, R) + query(mid + 1, r, 2 * p + 2, L, R);
}
int update(int l, int r, int p, int V, int P) {
  if (P < l || P > r) return dp[p];
  if (l == P && r == P) return dp[p] = V;
  int mid = (l + r) / 2;
  return dp[p] = update(l, mid, 2 * p + 1, V, P) +
                 update(mid + 1, r, 2 * p + 2, V, P);
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> k >> d;
  for (int i = 1; i < n + 1; i++) cin >> a[i];
  sort(a, a + n + 1);
  update(0, n, 0, 1, 0);
  for (int i = 1; i < n + 1; i++) {
    while (a[i] - a[lo] > d) lo++;
    int hi = i - k;
    if (lo - 1 > hi) continue;
    if (query(0, n, 0, lo - 1, hi)) {
      update(0, n, 0, 1, i);
    }
  }
  if (query(0, n, 0, n, n)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
