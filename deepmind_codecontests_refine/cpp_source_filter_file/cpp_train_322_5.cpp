#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void add(long long &a, long long b) { a = (a + mod + b) % mod; }
long long mult(long long a, long long b) { return (a * b) % mod; }
long long combos[6010][105];
int p, s, r;
long long sbars(int nstars, int places) {
  if (places == 0) {
    if (nstars == 0) return 1LL;
    return 0LL;
  }
  if (nstars == 0) return 1LL;
  int tt = nstars + places - 1;
  return combos[tt][places - 1];
}
void createcombos() {
  combos[0][0] = 1LL;
  combos[1][0] = 1;
  combos[1][1] = 1;
  for (int i = 2; i < 6010; i++) {
    combos[i][0] = 1;
    for (int j = 1; j < 105; j++) {
      combos[i][j] = combos[i - 1][j - 1];
      add(combos[i][j], combos[i - 1][j]);
    }
  }
}
long long modpow(long long u, int p) {
  if (p == 0) return 1LL;
  if (p % 2 == 0) {
    long long tmp = modpow(u, p / 2);
    return (tmp * tmp) % mod;
  }
  long long tmp = modpow(u, p - 1);
  return (tmp * u) % mod;
}
long long inv(long long u) { return modpow(u, mod - 2); }
long long iv[5010];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> p >> s >> r;
  createcombos();
  for (int i = 1; i <= 5000; i++) {
    iv[i] = inv(i);
  }
  int numleft = 0;
  long long tp = 0LL;
  long long bt = 0LL;
  long long csum = 0LL;
  for (int i = r; i <= s; i++) {
    numleft = s - i;
    bt += sbars(numleft, p - 1);
    for (int j = 0; j <= p - 1; j++) {
      long long cv = 0LL;
      numleft = s - i - j * i;
      if (numleft < 0) continue;
      cv = sbars(numleft, p - j - 1);
      cv = mult(cv, combos[p - 1][j]);
      for (int k = 1; k <= p - j - 1; k++) {
        long long sv = 0LL;
        numleft = s - i - j * i - k * i;
        if (numleft < 0) continue;
        sv = sbars(numleft, p - j - 1);
        sv = mult(sv, combos[p - j - 1][k]);
        sv = mult(sv, combos[p - 1][j]);
        if (k % 2 == 1) {
          add(cv, 0 - sv);
        } else
          add(cv, sv);
      }
      add(csum, cv);
      add(tp, mult(cv, iv[j + 1]));
    }
  }
  long long ans = mult(tp, inv(bt));
  cout << ans << endl;
}
