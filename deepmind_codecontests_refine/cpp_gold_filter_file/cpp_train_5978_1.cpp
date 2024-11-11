#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void maximize(T &x, U y) {
  if (x < y) x = y;
}
template <class T, class U>
void minimize(T &x, U y) {
  if (x > y) x = y;
}
template <class T>
T Abs(T x) {
  return (x < 0 ? -x : x);
}
template <class T>
T safe_sqrt(T x) {
  return sqrt(max(x, (T)0));
}
template <class T, class U, class V>
T addmod(T x, U k, V MOD) {
  return ((x + k) % MOD + MOD) % MOD;
}
template <class T, class U, class V>
T submod(T x, U k, V MOD) {
  return ((x - k) % MOD + MOD) % MOD;
}
template <class T, class U, class V>
T mul(T x, U y, V MOD) {
  return (long long)x * y % MOD;
}
namespace taskE {
const int N = 3e5 + 5;
const int maxSeg = 1e6 + 6;
vector<pair<int, int> > q[maxSeg + 6];
vector<int> a[maxSeg + 6];
int ans[N];
int n, m;
struct fenwickTree {
  vector<int> ft;
  fenwickTree() { ft.resize(maxSeg + 66, 0); }
  void update(int node) {
    for (; node <= maxSeg; node += node & (-node)) ft[node]++;
  }
  int rsq(int node) {
    int res = 0;
    for (; node > 0; node -= node & (-node)) res += ft[node];
    return res;
  }
  int rsq(int l, int r) {
    if (l > r) return 0;
    return rsq(r) - rsq(l - 1);
  }
} fen;
void solve() {
  scanf("%d%d", &n, &m);
  for (int l, r, i = 1; i <= n; i++) {
    scanf("%d%d", &l, &r);
    a[r].push_back(l);
  }
  for (int t, i = 1; i <= m; i++) {
    int l = 0;
    scanf("%d", &t);
    for (int r; t; --t) {
      scanf("%d", &r);
      if (l + 1 <= r - 1) q[r - 1].push_back(make_pair(l + 1, i));
      l = r;
    }
    q[maxSeg].push_back(make_pair(l + 1, i));
  }
  for (int i = 0; i <= maxSeg; i++) {
    for (__typeof((a[i]).begin()) it = (a[i]).begin(); it != (a[i]).end(); it++)
      fen.update(*it);
    for (__typeof((q[i]).begin()) it = (q[i]).begin(); it != (q[i]).end(); it++)
      ans[it->second] += fen.rsq(it->first, i);
  }
  for (int i = 1; i <= m; i++) printf("%d\n", n - ans[i]);
}
}  // namespace taskE
int main(void) { taskE::solve(); }
