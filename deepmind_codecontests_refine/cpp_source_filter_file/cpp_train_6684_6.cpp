#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int pw(int a, int b) {
  int sol = 1;
  for (int i = 1; i <= b; i <<= 1) {
    if (b & i) sol = (1LL * sol * a) % mod;
    a = (1LL * a * a) % mod;
  }
  return sol;
}
int p[200010], prod[200010], sum[200010], ans;
set<int> q;
set<int>::iterator it;
void upd(int i, int j, int k) {
  int p1 = sum[j - 1] - sum[i - 1];
  if (p1 < 0) p1 += mod;
  p1 = (1LL * p1 * pw(prod[i - 1], mod - 2)) % mod;
  p1++;
  int p2 = (1LL * prod[j] * pw(prod[i - 1], mod - 2)) % mod;
  int val = (1LL * p1 * pw(p2, mod - 2)) % mod;
  if (k == -1) {
    ans -= val;
    if (ans < 0) ans += mod;
  } else {
    ans += val;
    if (ans >= mod) ans -= mod;
  }
}
int main() {
  int n, q1, x;
  scanf("%d%d", &n, &q1);
  prod[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
    p[i] = (1LL * p[i] * pw(100, mod - 2)) % mod;
    prod[i] = (1LL * prod[i - 1] * p[i]) % mod;
    sum[i] = (sum[i - 1] + prod[i]) % mod;
  }
  ans = (1LL * (1 + sum[n - 1]) * pw(prod[n], mod - 2)) % mod;
  q.insert(1);
  q.insert(n + 1);
  for (int i = 1; i <= q1; i++) {
    scanf("%d", &x);
    it = q.lower_bound(x);
    if (*it == x) {
      int a = *(--it);
      it++;
      int b = *(++it);
      upd(a, x - 1, -1);
      upd(x, b - 1, -1);
      upd(a, b - 1, 1);
      q.erase(it);
    } else {
      int b = *it;
      int a = *(--it);
      upd(a, b - 1, -1);
      upd(a, x - 1, 1);
      upd(x, b - 1, 1);
      q.insert(x);
    }
    printf("%d\n", ans);
  }
  return 0;
}
