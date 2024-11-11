#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 35;
const int MAXM = 0;
long long a[MAXN], b[MAXN], r, u, n, i, j;
long long k[MAXN];
long long p[MAXN];
long long ans = 0;
void rec(int last, int moves) {
  if (moves == u || (u - moves) % 2 == 0) {
    long long ret = 0;
    for (i = 0; i < n; i++) ret += a[i] * k[i];
    ans = max(ret, ans);
    if (moves == u) return;
  }
  long long tmp1[MAXN], tmp2[MAXN], i;
  for (i = 0; i < n; i++) {
    tmp1[i] = a[p[i]] + r;
    tmp2[i] = a[i];
  }
  for (i = 0; i < n; i++) a[i] = tmp1[i];
  rec(0, moves + 1);
  for (i = 0; i < n; i++) a[i] = tmp2[i];
  if (last) return;
  for (i = 0; i < n; i++) a[i] ^= b[i];
  rec(1, moves + 1);
  for (i = 0; i < n; i++) a[i] ^= b[i];
}
int main() {
  cin >> n >> u >> r;
  for (i = 0; i < n; i++) cin >> a[i];
  for (i = 0; i < n; i++) cin >> b[i];
  for (i = 0; i < n; i++) cin >> k[i];
  for (i = 0; i < n; i++) {
    cin >> p[i];
    p[i]--;
  }
  rec(0, 0);
  cout << ans << endl;
  return 0;
}
