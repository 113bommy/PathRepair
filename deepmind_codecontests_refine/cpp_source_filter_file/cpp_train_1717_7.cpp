#include <bits/stdc++.h>
using namespace std;
int mod, l;
struct mat {
  long long int p, q, m, n;
};
mat osn;
mat pomn(mat w, mat a) {
  mat o;
  o.p = (w.p * a.p + a.m * w.q) % mod;
  o.q = (w.p * a.q + w.q * a.n) % mod;
  o.m = (a.p * w.m + a.m * w.n) % mod;
  o.n = (w.m * a.q + a.n * w.n) % mod;
  return o;
}
long long int nna(int a, long long int st) {
  if (st == 1) return a;
  long long int r = nna(a, st / 2);
  r *= r;
  r = r % mod;
  if (st % 2 == 0) return r;
  r *= a;
  r = r % mod;
  return r;
}
mat na(mat a, long long int k) {
  if (k == 1) return a;
  mat w = na(a, k / 2), o = pomn(w, w);
  if (k % 2 == 0) return o;
  mat y = pomn(o, osn);
  return y;
}
long long int n, k;
long long int radi() {
  long long int q = 1, uk = 1, wer = k, br = 0;
  while (wer > 1) {
    br++;
    wer /= 2;
  }
  if (br >= l && br != 0)
    return 0;
  else {
    q = 1;
    for (int i = 0; i < l; i++) {
      long long int n11 = n + 1;
      mat w = na(osn, n11);
      int e = w.p, zz = nna(2, n) - e;
      if (zz < 0) zz += mod;
      if ((q | k) == k)
        uk *= zz;
      else
        uk *= e;
      uk = uk % mod;
      q *= 2;
    }
  }
  uk = uk % mod;
  return uk;
}
int main() {
  osn.p = 1;
  osn.q = 1;
  osn.m = 1;
  osn.n = 0;
  cin >> n >> k >> l >> mod;
  cout << radi() << "\n";
  return 0;
}
