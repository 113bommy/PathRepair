#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long BIG = 2e9;
int n, q;
long long A[200003], W[200003];
long long ft[200003];
long long sum(int a) { return (a) ? ft[a] + sum(a - (a & -a)) : 0; }
long long sum(int a, int b) { return (a > b) ? 0 : sum(b) - sum(a - 1); }
void update(int a, long long val) {
  for (; a <= n; a += (a & -a)) ft[a] += val;
}
long long ftk[20003][2];
long long sumk(int a, int tipe) {
  return (a) ? (ftk[a][tipe] + sumk(a - (a & -a), tipe)) % MOD : 0;
}
long long sumk(int a, int b, int tipe) {
  return (a > b) ? 0 : sumk(b, tipe) - sumk(a - 1, tipe);
}
void updatek(int a, long long val, int tipe) {
  for (; a <= n; a += (a & -a)) ftk[a][tipe] = (ftk[a][tipe] + val) % MOD;
}
int binser(int l, int r, int x) {
  int iki = l, ika = r;
  while (iki < ika) {
    int imi = (1 + iki + ika) / 2;
    if (A[imi] > x)
      ika = imi - 1;
    else
      iki = imi;
  }
  return iki;
}
bool cek(int l, int r, int x) {
  int idx = binser(l, r, x);
  return sum(l, idx) <= sum(idx + 1, r);
}
int main() {
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) scanf("%lld", &A[i]);
  for (int i = 1; i <= n; i++) scanf("%lld", &W[i]);
  for (int i = 1; i <= n; i++) {
    update(i, W[i]);
    updatek(i, ((A[i] - i) * W[i]) % MOD, 0);
    updatek(i, ((-A[i] + i + BIG) * W[i]) % MOD, 1);
  }
  while (q--) {
    int l, r;
    scanf("%d %d", &l, &r);
    if (l < 0) {
      l = -l;
      update(l, -W[l]);
      updatek(l, -((A[l] - l) * W[l]) % MOD, 0);
      updatek(l, -((-A[l] + l + BIG) * W[l]) % MOD, 1);
      W[l] = r;
      update(l, W[l]);
      updatek(l, ((A[l] - l) * W[l]) % MOD, 0);
      updatek(l, ((-A[l] + l + BIG) * W[l]) % MOD, 1);
    } else {
      long long kir = A[l], kan = A[r];
      while (kir < kan) {
        long long mid = (1 + kir + kan) / 2;
        if (!cek(l, r, mid))
          kan = mid - 1;
        else
          kir = mid;
      }
      int idx = binser(l, r, kir);
      long long res = 0;
      res +=
          (sumk(l, idx, 1) - ((BIG + idx - kir) * (sum(l, idx) % MOD)) % MOD) %
          MOD;
      res += (sumk(idx + 1, r, 0) -
              ((kir - idx) * (sum(idx + 1, r) % MOD)) % MOD) %
             MOD;
      res %= MOD;
      printf("%lld\n", (res % MOD + MOD) % MOD);
    }
  }
}
