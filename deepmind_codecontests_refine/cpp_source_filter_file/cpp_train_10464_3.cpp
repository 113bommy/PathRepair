#include <bits/stdc++.h>
using namespace std;
int n, p[200009], t, q, w, ww, a[200009], qq, mod = 1000000007;
bool v[200009];
int z(int a, int b) {
  int q = 1, w = a;
  while (b) {
    if (b % 2) q = (long long)q * w % mod;
    w = (long long)w * w % mod;
    b >>= 1;
  }
  return q;
}
int main() {
  for (int i = 2; i <= 200000; i++) {
    if (!v[i]) {
      p[t++] = i;
      for (int j = i + i; j <= 200000; j += i) {
        v[j] = 1;
      }
    }
  }
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &q);
    a[lower_bound(p, p + t, q) - p]++;
  }
  q = w = 1;
  for (int i = 0; i < t; i++) {
    if (a[i]) {
      qq = q;
      ww = 1;
      for (int j = 0; j < a[i]; j++) {
        ww = (long long)ww * p[i] % mod;
        qq = (long long)qq * q % mod;
        qq = (long long)qq * z(ww, w) % mod;
      }
      w = (long long)w * (a[i] + 1) % mod;
      q = qq;
    }
  }
  printf("%d\n", q);
  return 0;
}
