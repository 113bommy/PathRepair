#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long powMod(long long a, long long b, long long mo) {
  if (b == 0)
    return 1;
  else {
    long long tmp = powMod(a, b / 2, mo);
    if (b % 2 == 0)
      return tmp * tmp % mo;
    else
      return tmp * tmp % mo * a % mo;
  }
}
long long rev2;
long long db(int id1, int id2) {
  int gs = id2 - id1 + 1;
  assert(gs >= 0);
  return powMod(3, id1, MOD) * (powMod(3, gs, MOD) - 1) % MOD * rev2 % MOD;
}
long long subcal(int l, int r) {
  if (l > r) return 0;
  int ko, eo, kj, ej;
  if (l % 2 == 0)
    ko = l, kj = l + 1;
  else
    ko = l + 1, kj = l;
  if (r % 2 == 0)
    eo = r, ej = r - 1;
  else
    eo = r - 1, ej = r;
  int b1, b2, c1, c2;
  long long ans = 0;
  if (ko <= eo) {
    b1 = ko / 2 - 1, b2 = eo / 2 - 1;
    c1 = (ko - 1) / 2 - 1, c2 = (eo - 1) / 2 - 1;
    long long tmp = (4 * db(b1, b2) + 12 * db(c1, c2)) % MOD;
    ans = (ans + tmp) % MOD;
  }
  if (kj <= ej) {
    b1 = kj / 2 - 1, b2 = ej / 2 - 1;
    c1 = (kj - 1) / 2 - 1, c2 = (ej - 1) / 2 - 1;
    long long tmp = (8 * db(b1, b2) + 6 * db(c1, c2)) % MOD;
    ans = (ans + tmp) % MOD;
  }
  return ans;
}
long long sol(int r) {
  if (r < 1)
    return 0;
  else if (r == 1)
    return 4;
  else if (r == 2)
    return 12;
  else {
    long long ans = 12;
    long long t1 = subcal(3, r);
    int lj = r % 2 == 1 ? r : r - 1;
    lj = (1 + lj) / 2;
    long long t2 = 8;
    t2 = t2 + subcal(3, lj);
    ans = (ans + t1 * rev2 + t2 * rev2) % MOD;
    return ans;
  }
}
int l, r;
int main() {
  rev2 = powMod(2, MOD - 2, MOD);
  scanf("%d %d", &l, &r);
  long long t1 = sol(r), t2 = sol(l - 1);
  printf("%lld\b", ((t1 - t2) % MOD + MOD) % MOD);
  return 0;
}
