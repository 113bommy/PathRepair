#include <bits/stdc++.h>
using namespace std;
int n, k;
pair<int, int> s[200005];
int leaf[200005];
const int mod = 1e9 + 7;
long long fra[200005];
long long Pow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long a) { return Pow(a, mod - 2); }
long long C(int x) {
  if (x < k) return 0;
  return fra[x] * inv(fra[k]) % mod * inv(fra[x - k]) % mod;
}
long long ans = 0;
int N;
struct SegmentTree {
  int Tree[200005 << 4];
  SegmentTree() { memset(Tree, 0, sizeof(Tree)); }
  void update(int L, int R, int x, int l = 1, int r = N, int v = 1) {
    if (L <= l && r <= R) {
      Tree[v] += x;
      return;
    }
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, x, l, m, v << 1);
    if (R > m) update(L, R, x, m + 1, r, v << 1 | 1);
  }
  void GetAns(int l = 1, int r = N, int v = 1) {
    if (l == r) {
      ans = (ans + (long long)leaf[l] * C(Tree[v]) % mod) % mod;
      return;
    }
    Tree[v << 1] += Tree[v];
    Tree[v << 1 | 1] += Tree[v];
    Tree[v] = 0;
    int m = (l + r) >> 1;
    GetAns(l, m, v << 1);
    GetAns(m + 1, r, v << 1 | 1);
  }
} seg;
vector<int> v;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &s[i].first, &s[i].second);
    v.push_back(s[i].first);
    v.push_back(s[i].second + 1);
  }
  fra[0] = 1;
  for (int i = 1; i <= n; i++) fra[i] = i * fra[i - 1] % mod;
  sort(v.begin(), v.end());
  auto it = unique(v.begin(), v.end());
  v.resize(distance(v.begin(), it));
  for (int i = 0; i < v.size() - 1; i++) leaf[i + 1] = v[i + 1] - v[i];
  N = v.size();
  for (int i = 1; i <= n; i++) {
    s[i].first = lower_bound(v.begin(), v.end(), s[i].first) - v.begin() + 1;
    s[i].second = lower_bound(v.begin(), v.end(), s[i].second + 1) - v.begin();
  }
  for (int i = 1; i <= n; i++) seg.update(s[i].first, s[i].second, 1);
  seg.GetAns();
  printf("%I64d\n", ans);
  return 0;
}
