#include <bits/stdc++.h>
const double PI = acos(-1);
using namespace std;
const int MAXA = 1000 * 1000 + 10, mod = 1e9 + 7, MAXN = 200 * 1000 + 10,
          MAXR = MAXN * 7;
int prime[MAXA], f[MAXA];
int A[MAXN], pref[MAXN], n;
int L[MAXN], R[MAXN], lst[MAXA], B[MAXR], prv[MAXR], N;
int BIT[MAXN];
int qL[MAXN], qR[MAXN], ans[MAXN], guess[MAXN];
int mul(int x, int y) { return (x * 1LL * y) % mod; }
int pow_mod(int x, int b) {
  if (!b) return x;
  int y = 1;
  for (; b > 1; b >>= 1) {
    if (b & 1) y = mul(x, y);
    x = mul(x, x);
  }
  return mul(x, y);
}
inline void update(int pos, int val) {
  for (pos++; pos <= n; pos += ((pos) & (-(pos))))
    BIT[pos] = mul(BIT[pos], val);
}
inline int get(int pos) {
  int ret = 1;
  for (pos++; pos; pos ^= ((pos) & (-(pos)))) ret = mul(ret, BIT[pos]);
  return ret;
}
void sieve() {
  f[1] = 1;
  int mx = 0;
  for (int i = 2; i < MAXA; i++) {
    if (!prime[i]) {
      prime[i] = i;
      for (long long j = i * 1LL * i; j < MAXA; j += i) prime[j] = i;
    }
    f[i] = mul(i - 1, pow_mod(i, mod - 2));
    int tmp = 0, x = i;
    while (x > 1) {
      tmp++;
      int p = prime[x];
      while (x % p == 0) x /= p;
    }
    if (i <= 1000 * 1000 && tmp == 6) mx++;
  }
}
int main() {
  sieve();
  scanf("%d", &n);
  for (int i = 0; i < (n); i++) {
    scanf("%d", A + i);
    int x = A[i];
    L[i] = N;
    while (x > 1) {
      int p = prime[x];
      B[N++] = p;
      while (x % p == 0) x /= p;
    }
    R[i] = N;
    pref[i] = mul(A[i], i ? pref[i - 1] : 1);
  }
  fill(lst, lst + MAXA, -1);
  for (int i = 0; i < (N); i++) {
    int p = B[i];
    prv[i] = lst[p];
    lst[p] = i;
  }
  int m;
  scanf("%d", &m);
  for (int i = 0; i < (m); i++) {
    scanf("%d %d", qL + i, qR + i);
    qL[i]--;
    qR[i]--;
    ans[i] = pref[qR[i]];
    if (qL[i]) ans[i] = mul(ans[i], pow_mod(pref[qL[i] - 1], mod - 2));
    guess[i] = ans[i];
    qL[i] = L[qL[i]];
    qR[i] = R[qR[i]];
  }
  vector<pair<pair<int, int>, int> > event;
  event.reserve(n + 2 * m);
  fill(BIT, BIT + n + 1, 1);
  for (int i = 0; i < (N); i++) event.push_back(make_pair(make_pair(i, 1), -1));
  for (int i = 0; i < (m); i++) {
    if (qL[i] == qR[i]) continue;
    event.push_back(make_pair(make_pair(qL[i], -1), i));
    event.push_back(make_pair(make_pair(qR[i], 0), i));
  }
  sort(event.begin(), event.end());
  for (auto e : event) {
    int pos = e.first.first, type = e.first.second, q = e.second;
    bool debug = q == 4;
    if (type == -1) {
      int tmp = get(qL[q]), rev = pow_mod(tmp, mod - 2);
      ans[q] = mul(ans[q], rev);
    } else if (type == 0) {
      ans[q] = mul(ans[q], get(qL[q]));
    } else if (type == 1) {
      update(prv[pos] + 1, f[B[pos]]);
    }
  }
  for (int i = 0; i < (m); i++) printf("%d\n", ans[i]);
  return 0;
}
