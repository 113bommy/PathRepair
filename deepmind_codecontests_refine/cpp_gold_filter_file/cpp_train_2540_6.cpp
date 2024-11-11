#include <bits/stdc++.h>
using namespace std;
const int N = 2020, mod = 1e9 + 7;
int n;
int livre[N], a[N], fat[N], inv[N];
int mult(int a, int b) {
  long long c = 1ll * a * 1ll * b;
  c %= mod;
  return c;
}
int menos(int a, int b) {
  int c = a - b;
  if (c < 0) c += mod;
  return c;
}
int mais(int a, int b) {
  int c = a + b;
  if (c >= mod) c -= mod;
  return c;
}
int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mult(r, a);
    b /= 2;
    a = mult(a, a);
  }
  return r;
}
int comb(int a, int b) {
  if (a < b) return 0;
  return mult(fat[a], mult(inv[b], inv[a - b]));
}
int main() {
  fat[0] = 1;
  inv[0] = 1;
  for (int i = 1; i < N; i++)
    fat[i] = mult(fat[i - 1], i), inv[i] = pw(fat[i], mod - 2);
  for (int(i) = (0); (i) < (N); (i)++) livre[i] = 1;
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n;
  int sob = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    cin >> a[i];
    a[i]--;
    if (a[i] < 0) sob++;
    if (a[i] >= 0) livre[a[i]] = 0;
  }
  int qtd = 0;
  for (int(i) = (0); (i) < (n); (i)++) {
    if (livre[i] && a[i] < 0) qtd++;
  }
  int ans = fat[sob];
  int signal = 0;
  for (int(i) = (1); (i) < (qtd + 1); (i)++) {
    if (signal)
      ans = mais(ans, mult(comb(qtd, i), fat[sob - i]));
    else
      ans = menos(ans, mult(comb(qtd, i), fat[sob - i]));
    signal ^= 1;
  }
  cout << ans << endl;
}
