#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
const int mxN = 250010;
const int mxM = 20050000;
const int mxK = 30;
const long long MOD = 998244353;
const long long P1 = 1000000007, P2 = 10000000009;
const long long INF = 8000000000000000001;
int cnt;
long long ipow(long long x, long long y) {
  if (y == 0) return 1;
  if (y == 1) return x;
  long long ret = ipow(x, y / 2);
  ret = ret * ret % MOD;
  if (y % 2 == 1) ret = ret * x % MOD;
  cnt++;
  return ret;
}
void fft(vector<long long> &a, bool inv) {
  int n = a.size(), j = 0;
  vector<long long> roots(n / 2);
  for (int i = 1; i < n; i++) {
    int bit = (n >> 1);
    while (j >= bit) {
      j -= bit;
      bit >>= 1;
    }
    j += bit;
    if (i < j) swap(a[i], a[j]);
  }
  int prr = 3;
  int ang = ipow(prr, (MOD - 1) / n);
  if (inv) ang = ipow(ang, MOD - 2);
  for (int i = 0; i < n / 2; i++)
    roots[i] = (i ? (1ll * roots[i - 1] * ang % MOD) : 1);
  for (int i = 2; i <= n; i <<= 1) {
    int step = n / i;
    for (int j = 0; j < n; j += i) {
      for (int k = 0; k < i / 2; k++) {
        long long u = a[j + k], v = a[j + k + i / 2] * roots[step * k] % MOD;
        a[j + k] = (u + v > MOD ? u + v - MOD : u + v);
        a[j + k + i / 2] = (u > v ? u - v : u - v + MOD);
      }
    }
  }
  if (inv) {
    long long ninv = ipow(n, MOD - 2);
    for (int i = 0; i < n; i++) a[i] = a[i] * ninv % MOD;
  }
}
vector<long long> multiply(vector<long long> &v, vector<long long> &w) {
  vector<long long> fv(v.begin(), v.end()), fw(w.begin(), w.end());
  int n = 2;
  while (n < v.size() + w.size()) n <<= 1;
  fv.resize(n);
  fw.resize(n);
  fft(fv, 0);
  fft(fw, 0);
  for (int i = 0; i < n; i++) fv[i] = fv[i] * fw[i] % MOD;
  fft(fv, 1);
  return fv;
}
int N;
int deg[mxN];
vector<long long> v[mxN];
long long fact[mxN];
long long ans;
void dnc() {
  int npow = 1;
  v[1] = {deg[1], 1};
  for (int i = 2; i <= N; i++) v[i] = {deg[i] - 1, 1};
  while (npow + 1 <= N) {
    for (int i = 1; i + npow <= N; i += 2 * npow) {
      v[i] = multiply(v[i], v[i + npow]);
    }
    npow *= 2;
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    deg[a]++;
    deg[b]++;
  }
  dnc();
  fact[0] = 1;
  for (int i = 1; i <= N; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= MOD;
  }
  for (int i = 0; i <= N; i++) {
    if (i % 2 == N % 2)
      ans += fact[i] * v[1][i];
    else
      ans -= fact[i] * v[1][i];
    ans = (ans % MOD + MOD) % MOD;
  }
  cout << ans;
}
