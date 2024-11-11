#include <bits/stdc++.h>
const long long mod = (long long)1e9 + 7;
const int maxn = (int)2e5 + 2;
long long inf = 1LL << 60;
const double eps = 1e-9;
double pi = 3.14159265359;
using namespace std;
template <class N>
inline void read(N &n) {
  N x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = 10 * x + ch - '0';
    ch = getchar();
  }
  n = x * f;
}
int t[4 * maxn];
void modify(int v, int L, int R, int pos) {
  if (pos < L || pos >= R) return;
  if (L == R - 1) {
    t[v] = 1;
    return;
  }
  int m = (L + R) >> 1;
  modify(v * 2, L, m, pos);
  modify(v * 2 + 1, m, R, pos);
  t[v] = t[v * 2] + t[v * 2 + 1];
}
int get(int v, int L, int R, int l, int r) {
  if (R <= l || L >= r) return 0;
  if (l <= L && r >= R) return t[v];
  int m = (L + R) >> 1;
  return get(v * 2, L, m, l, r) + get(v * 2, m, R, l, r);
}
struct str {
  int l, r, id;
};
int ans[maxn];
pair<int, pair<int, int> > a[maxn];
int p[maxn];
int main() {
  int n;
  cin >> n;
  set<int> q;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    a[i] = {l, {r, i}};
    p[i] = r;
  }
  sort(p, p + n);
  sort(a, a + n);
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    int pos = lower_bound(p, p + n, a[i].second.first) - p;
    ans[a[i].second.second] = get(1, 0, n, 0, pos);
    modify(1, 0, n, pos);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << endl;
  return 0;
}
