#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;
int T, n, m, p = 0, phi[100010], S[100010], pr[100010], ans[100010];
bool isnt[100010];
int& qmo(int& x) { return x += (x >> 31) & mod; }
int ksm(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % mod)
    if (k & 1) res = 1ll * res * a % mod;
  return res;
}
void init(int N) {
  phi[1] = S[1] = 1;
  for (int i = 2; i <= N; i++) {
    if (!isnt[i]) {
      pr[++p] = i;
      phi[i] = i - 1;
    }
    for (int j = 1; j <= p && pr[j] * i <= N; j++) {
      isnt[pr[j] * i] = 1;
      if (i % pr[j] == 0) {
        phi[pr[j] * i] = phi[i] * pr[j];
        break;
      } else
        phi[pr[j] * i] = phi[i] * phi[pr[j]];
    }
    qmo(S[i] = S[i - 1] + phi[i] - mod);
  }
}
int main() {
  scanf("%d%d", &n, &m), init(n);
  for (int i = 1; i < n; i++) {
    int t = (n + i - 1) / i;
    qmo(qmo(qmo(ans[i] += S[t] - mod) -= 1) += (n - i - 1) - mod);
    if (n % i) qmo(ans[t * i - n] -= phi[t]);
  }
  int res = 0;
  for (int i = 0, nw = 1; i <= n; i++)
    res = (res + 1ll * nw * ans[i]), nw = 1ll * nw * m % mod;
  res = 1ll * res * ksm(ksm(m, n), mod - 2) % mod;
  printf("%d\n", res);
}
