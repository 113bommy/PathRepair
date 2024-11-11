#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long double eps = 1e-7;
const int inf = 1000000010;
const long long INF = 10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG = 20;
int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN], B[MAXN];
map<int, int> mp;
int Get(int x, int len) {
  int r = upper_bound(A + 1, A + n + 1, x + len) - A - 1;
  int l = lower_bound(A + 1, A + n + 1, A[r] - (len - (A[r] - x))) - A;
  if (l == r) return A[l];
  len -= A[r] - x + A[r] - A[l];
  if ((len / (A[r] - A[l])) & 1)
    x = A[r];
  else
    x = A[l];
  return Get(x, len % (A[r] - A[l]));
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> A[i], mp[A[i]] = i, B[i] = A[i];
  sort(A + 1, A + n + 1);
  while (m--) {
    cin >> x >> y;
    cout << mp[Get(A[x], y)] << '\n';
  }
  return 0;
}
