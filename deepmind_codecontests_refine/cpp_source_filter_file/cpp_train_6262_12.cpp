#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, a[5010], quant[5010], ant[5010];
long long fat[100010], inv[100010];
long long fast_exp(long long x, long long e) {
  if (e == 0) return 1;
  long long resp = fast_exp(x, e / 2);
  resp *= resp;
  resp %= mod;
  if (e % 2 == 1) resp *= x, resp %= mod;
  return resp;
}
void init() {
  fat[0] = fat[1] = 1;
  inv[0] = inv[1] = 1;
  for (long long i = 2; i <= 100000; i++) {
    fat[i] = fat[i - 1] * i;
    fat[i] %= mod;
    inv[i] = fast_exp(fat[i], mod - 2);
  }
}
long long escolhe(long long x, long long y) {
  long long resp = fat[x];
  resp *= inv[y];
  resp %= mod;
  resp *= inv[x - y];
  resp %= mod;
  return resp;
}
void solve() {
  init();
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    quant[a[i]]++;
  }
  long long P = 0, foram = 0;
  ant[0] = 1;
  for (long long i = 1; i <= n; i++) {
    if (quant[i] == 0) continue;
    if (quant[i] == 1) {
      for (long long j = foram + 1; j >= 1; j--) {
        ant[j] += ant[j - 1] * quant[j];
        ant[j] %= mod;
      }
      foram++;
      continue;
    }
    for (long long pos = 1; pos <= foram + 1; pos++) {
      long long vez = quant[i] * (quant[i] - 1);
      vez %= mod;
      vez *= ant[pos - 1];
      vez %= mod;
      vez *= fat[n - (pos + 1)];
      vez %= mod;
      P += vez;
      P %= mod;
    }
    for (long long j = foram + 1; j >= 1; j--) {
      ant[j] += ant[j - 1] * quant[j];
      ant[j] %= mod;
    }
    foram++;
  }
  P *= inv[n];
  P %= mod;
  cout << P;
}
signed main() { solve(); }
