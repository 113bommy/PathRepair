#include <bits/stdc++.h>
using namespace std;
const int M = 2e5 + 10;
const long long MOD = 1e9 + 7;
int n, Q;
long long A[M], W[M];
struct bit_tree {
  long long bit[M], Mod;
  void init(long long mod) { Mod = mod; }
  void Add(long long &a, long long b) {
    a += b;
    if (Mod != -1) {
      a %= Mod;
      if (a < 0) a += Mod;
    }
  }
  void add(int a, long long v) {
    if (!a) a = 1;
    for (; a <= n; a += ((a) & (-(a)))) Add(bit[a], v);
  }
  long long query(int a) {
    long long res = 0;
    for (; a > 0; a -= ((a) & (-(a)))) Add(res, bit[a]);
    return res;
  }
} b1, b2;
void change_pos(long long p, long long v) {
  long long res = v - W[p];
  b1.add(p, res);
  b2.add(p, A[p] * res % MOD);
  W[p] += res;
}
void solve_area(long long le, long long ri) {
  long long sum = b1.query(le - 1);
  sum += ((b1.query(ri) - sum + 1) >> 1);
  int l = le, r = ri, mid;
  while (l < r) {
    mid = l + r >> 1;
    if (b1.query(mid) >= sum)
      r = mid;
    else
      l = mid + 1;
  }
  long long all = b2.query(ri) + b2.query(le - 1) - (2ll * b2.query(l) % MOD);
  all %= MOD;
  if (all < 0) all += MOD;
  sum = b1.query(l);
  long long bef = (sum - b1.query(le - 1)) % MOD + sum - b1.query(ri);
  bef %= MOD;
  if (bef < 0) bef += MOD;
  printf("%I64d\n", (all + bef * A[l] % MOD) % MOD);
}
long long a, b;
int main() {
  b1.init(-1);
  b2.init(MOD);
  scanf("%d%d", &n, &Q);
  for (int i = 1; i <= n; i++) {
    scanf("%I64d", &A[i]);
    A[i] -= i;
  }
  for (int i = 1; i <= n; i++) scanf("%I64d", &W[i]);
  for (int i = 1; i <= n; i++) b1.add(i, W[i]), b2.add(i, A[i] * W[i] % MOD);
  while (Q--) {
    scanf("%I64d%I64d", &a, &b);
    if (a < 0)
      change_pos(-a, b);
    else
      solve_area(a, b);
  }
  return 0;
}
