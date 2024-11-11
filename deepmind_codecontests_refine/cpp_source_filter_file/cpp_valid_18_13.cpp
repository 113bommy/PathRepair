#include <bits/stdc++.h>
using namespace std;
int readint() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int N = 1e5 + 5;
const int INF = 1e9 + 7;
const int MOD = 998244353;
bool cmp(int a, int b) { return a < b; }
bool cmpPii(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n & 1)
    return (a * binpow(a, n - 1)) % MOD;
  else {
    long long b = binpow(a, n >> 1);
    return (b * b) % MOD;
  }
}
inline bool cross(pair<int, int> l1, pair<int, int> l2) {
  pair<int, int> tl1 =
      make_pair(min(l1.first, l1.second), max(l1.first, l1.second));
  pair<int, int> tl2 =
      make_pair(min(l2.first, l2.second), max(l2.first, l2.second));
  if (tl1.first > tl2.first) swap(tl1, tl2);
  return (tl2.first < tl1.second) && (tl1.second < tl2.second);
}
inline void solve() {
  int n, k;
  int used[N];
  vector<pair<int, int> > bc, rc;
  scanf("%d%d", &n, &k);
  memset(used, 0, 2 * n * sizeof(int));
  for (int i = 0; i < k; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a > b) swap(a, b);
    bc.push_back(make_pair(a, b));
    used[a] = 1;
    used[b] = 1;
  }
  vector<int> rp;
  for (int i = 1; i <= 2 * n; ++i) {
    if (!used[i]) rp.push_back(i);
  }
  for (int i = 0; i < n - k; ++i) rc.push_back(make_pair(rp[i], rp[i + n - k]));
  for (int i = 0; i < bc.size(); ++i) rc.push_back(bc[i]);
  int ans = 0;
  for (int i = 0; i < rc.size(); ++i)
    for (int j = i + 1; j < rc.size(); ++j) ans += cross(rc[i], rc[j]);
  printf("%d\n", ans);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T;
  scanf("%d", &T);
  ++T;
  while (--T) solve();
  return 0;
}
