#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 7;
const long long maxn = 1e6 + 7;
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = a * a % M)
    if (b & 1) ret = 1ll * ret * a % M;
  return ret;
}
int n, m, q, i, j;
int t[maxn];
long long a[maxn], b[maxn], c[maxn], k;
vector<long long> H;
long long ans[maxn], now;
int cnt[maxn];
int L, R;
struct node {
  int l, r, id;
} Q[maxn];
int BLOCK[maxn];
int cmp(node a, node b) {
  if (BLOCK[a.l] == BLOCK[b.l]) return a.r < b.r;
  return BLOCK[a.l] < BLOCK[b.l];
}
const int DIV = 300;
inline int getid(long long x) {
  return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}
int main() {
  scanf("%d%I64d", &n, &k);
  n++;
  a[1] = 0;
  b[1] = -k;
  c[1] = k;
  H.push_back(0);
  H.push_back(k);
  H.push_back(-k);
  for (i = 2; i <= n; i++) scanf("%d", &t[i]);
  for (i = 1; i <= n; i++) BLOCK[i] = i / DIV;
  for (i = 2; i <= n; i++) {
    scanf("%I64d", &a[i]);
    if (t[i] == 2) a[i] = -a[i];
    a[i] += a[i - 1];
    b[i] = a[i] - k;
    c[i] = a[i] + k;
    H.push_back(a[i]);
    H.push_back(b[i]);
    H.push_back(c[i]);
  }
  sort(H.begin(), H.end());
  H.erase(unique(H.begin(), H.end()), H.end());
  for (i = 1; i <= n; i++)
    a[i] = getid(a[i]), b[i] = getid(b[i]), c[i] = getid(c[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++)
    scanf("%d%d", &Q[i].l, &Q[i].r), Q[i].id = i, Q[i].r++;
  sort(Q, Q + q, cmp);
  L = 1;
  R = 0;
  for (i = 0; i < q; i++) {
    while (R < Q[i].r) {
      R++;
      now += cnt[b[R]];
      cnt[a[R]]++;
    }
    while (L > Q[i].l) {
      L--;
      now += cnt[c[L]];
      cnt[a[L]]++;
    }
    while (R > Q[i].r) {
      cnt[a[R]]--;
      now -= cnt[b[R]];
      R--;
    }
    while (L < Q[i].l) {
      cnt[a[L]]--;
      now -= cnt[c[L]];
      L++;
    }
    ans[Q[i].id] = now;
  }
  for (i = 0; i < q; i++) printf("%I64d\n", ans[i]);
}
