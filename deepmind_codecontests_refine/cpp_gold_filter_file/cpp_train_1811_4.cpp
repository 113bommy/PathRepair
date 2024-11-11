#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,tune=native")
using namespace std;
const int N = 5005;
const int A = (int)1e6 + 1;
int S[A];
vector<pair<int, int> > add[A];
int a[N];
int p[A];
int sz[A];
int n, k;
int find_set(int v) { return v == p[v] ? v : p[v] = find_set(p[v]); }
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> k;
  for (auto i = (0); i < (n); i++) cin >> a[i];
  sort(a, a + n);
  for (auto i = (0); i < (n); i++) {
    for (auto j = (i + 1); j < (n); j++) {
      int m = a[j] - a[i];
      ++S[m];
    }
  }
  fill(sz, sz + A, 1);
  iota(p, p + A, 0);
  for (auto x = (1); x < (A); x++) {
    int kek = 0;
#pragma GCC ivdep
    for (int y = x; y < A; y += x) kek += S[y];
    if (kek > k * (k + 1) / 2) continue;
    kek = 0;
    for (int i = 0; i < n; i++) {
      if (p[a[i] % x] == x) ++kek;
      if (kek > k) break;
      p[a[i] % x] = x;
    }
    if (kek <= k) {
      cout << x;
      return 0;
    }
  }
  return 0;
}
