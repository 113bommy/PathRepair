#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;
const int P = 1000000007;
int add(int a, int b) { return a + b < P ? a + b : a + b - P; }
int sub(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
int mul(int a, int b) { return 1LL * a * b % P; }
int qpow(int a, int k = P - 2) {
  int res = 1;
  while (k) {
    if (k & 1) res = mul(res, a);
    a = mul(a, a);
    k >>= 1;
  }
  return res;
}
int k, n, m;
pair<int, int> a[N], b[N];
vector<int> l[2][N];
struct Tree {
  int a[N << 2], lazy[N << 2];
  void Push_down(int o) {
    if (lazy[o]) {
      lazy[o << 1] = lazy[o << 1 | 1] = lazy[o];
      a[o << 1] = a[o << 1 | 1] = 0;
      lazy[o] = 0;
    }
  }
  void Update2(int o, int L, int R, int l, int r) {
    if (l > r) return;
    if (l <= L && R <= r) {
      a[o] = 0;
      lazy[o] = 1;
      return;
    }
    Push_down(o);
    int M = (L + R) >> 1;
    if (l <= M) Update2(o << 1, L, M, l, r);
    if (r > M) Update2(o << 1 | 1, M + 1, R, l, r);
    a[o] = add(a[o << 1], a[o << 1 | 1]);
  }
  void Update(int o, int L, int R, int pos, int v) {
    if (L == R) {
      a[o] = add(a[o], v);
      return;
    }
    Push_down(o);
    int M = (L + R) >> 1;
    if (pos <= M)
      Update(o << 1, L, M, pos, v);
    else
      Update(o << 1 | 1, M + 1, R, pos, v);
    a[o] = add(a[o << 1], a[o << 1 | 1]);
  }
  int Query(int o, int L, int R, int l, int r) {
    if (l <= L && R <= r) return a[o];
    Push_down(o);
    int M = (L + R) >> 1, res = 0;
    if (l <= M) res = add(res, Query(o << 1, L, M, l, r));
    if (r > M) res = add(res, Query(o << 1 | 1, M + 1, R, l, r));
    a[o] = add(a[o << 1], a[o << 1 | 1]);
    return res;
  }
} tr[2];
int main() {
  scanf("%d %d %d", &k, &n, &m);
  vector<int> hs;
  for (int i = 1; i <= n; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    a[i] = make_pair(l, r);
    hs.push_back(l);
    hs.push_back(r);
  }
  for (int i = 1; i <= m; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    l--;
    b[i] = make_pair(l, r);
    hs.push_back(l);
    hs.push_back(r);
  }
  hs.push_back(1);
  hs.push_back(k);
  sort(hs.begin(), hs.end());
  hs.erase(unique(hs.begin(), hs.end()), hs.end());
  int len = hs.size();
  for (int i = 1; i <= n; i++) {
    a[i].first = lower_bound(hs.begin(), hs.end(), a[i].first) - hs.begin() + 1;
    a[i].second =
        lower_bound(hs.begin(), hs.end(), a[i].second) - hs.begin() + 1;
    l[0][a[i].second].push_back(a[i].first);
  }
  for (int i = 1; i <= m; i++) {
    b[i].first = lower_bound(hs.begin(), hs.end(), b[i].first) - hs.begin() + 1;
    b[i].second =
        lower_bound(hs.begin(), hs.end(), b[i].second) - hs.begin() + 1;
    l[1][b[i].second].push_back(b[i].first);
  }
  tr[0].Update(1, 1, len, 1, 1);
  tr[1].Update(1, 1, len, 1, 1);
  for (int i = 1; i < len; i++) {
    int sum0 = tr[0].a[1], sum1 = tr[1].a[1],
        times = sub(qpow(2, hs[i] - hs[i - 1] - 1), 1);
    tr[0].Update(1, 1, len, i + 1, mul(sum0, times));
    tr[1].Update(1, 1, len, i, sum0);
    tr[1].Update(1, 1, len, i + 1, mul(sum0, times));
    tr[0].Update(1, 1, len, i, sum1);
    tr[0].Update(1, 1, len, i + 1, mul(sum1, times));
    tr[1].Update(1, 1, len, i + 1, mul(sum1, times));
    for (auto pos : l[0][i + 1]) tr[1].Update2(1, 1, len, 1, pos);
    for (auto pos : l[1][i + 1]) tr[0].Update2(1, 1, len, 1, pos);
  }
  printf("%d\n", mul(add(tr[0].a[1], tr[1].a[1]), qpow(2)));
  return 0;
}
