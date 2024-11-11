#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5;
long long par[MAXN], r[MAXN];
void make_set(long long n) {
  iota(par, par + n, 0);
  fill(r, r + n, 1);
}
long long find_fn(long long i) {
  if (par[i] == i) return i;
  return par[i] = find_fn(par[i]);
}
void union_fn(long long x, long long y) {
  long long s1 = find_fn(x);
  long long s2 = find_fn(y);
  if (r[s1] < r[s2]) {
    swap(s1, s2);
  }
  if (s1 != s2) {
    par[s2] = s1, r[s1] += r[s2];
  }
  return;
}
void solve() {
  long long n, i, a;
  cin >> n;
  make_set(n);
  for (long long i = 0; i < n; i++) cin >> a, a--, union_fn(i, a);
  for (long long i = 0; i < n; i++) {
    cout << r[find_fn(i)];
  }
}
int32_t main() {
  long long n, m, i, flag = 0, j, sum = 0, x, y, r, ans = 0, a, b, c, z, s = 1,
                     e, mid, mx = INT_MIN;
  long long t;
  cin >> t;
  while (t--) {
    solve();
    cout << '\n';
  }
  return 0;
}
