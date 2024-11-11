#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 3000005;
int a[N], b[N], c[N];
const int M = 1000000007;
int inv[N], f[N], g[N];
void init() {
  int i;
  inv[1] = 1;
  for (i = 2; i < N; i++) inv[i] = 1LL * inv[M % i] * (M - M / i) % M;
  f[0] = g[0] = 1;
  for (i = 1; i < N; i++) {
    f[i] = 1LL * f[i - 1] * i % M;
    g[i] = 1LL * g[i - 1] * inv[i] % M;
  }
}
inline int C(int n, int k) {
  if (k < 0 || k > n) return 0;
  return 1LL * f[n] * g[k] % M * g[n - k] % M;
}
int n, q;
int d[N];
int main() {
  ios_base::sync_with_stdio(0);
  init();
  cin >> n >> q;
  for (int i = 3; i <= 3 * n; i += 3) (a[1] += C(i, 1)) %= M;
  for (int i = 1; i <= 3 * n; i += 3) (b[1] += C(i, 1)) %= M;
  for (int i = 2; i <= 3 * n; i += 3) (c[1] += C(i, 1)) %= M;
  int pw = inv[3];
  for (int i = 2; i <= 3 * n + 1; i++) d[i] = C(3 * n + 1, i);
  for (int x = 2; x <= 3 * n; x++) {
    c[x] = 1LL * ((b[x - 1] + M - c[x - 1]) % M + d[x + 1]) % M * pw % M;
    a[x] = (c[x - 1] + c[x]) % M;
    b[x] = ((a[x] + a[x - 1]) % M + M - d[x]) % M;
  }
  while (q--) {
    int x;
    cin >> x;
    cout << a[x] << endl;
  }
  return 0;
}
