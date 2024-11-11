#include <bits/stdc++.h>
using namespace std;
const int N = 1e7 + 100;
int gi() {
  int w = 0;
  bool q = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && c != '-') c = getchar();
  if (c == '-') q = 0, c = getchar();
  while (c >= '0' && c <= '9') w = w * 10 + c - '0', c = getchar();
  return q ? w : -w;
}
int pri[N];
int sum[N], phi[N], low[N];
int main() {
  int n = gi(), i, j, len = 0, t, tot = 0;
  long long ans = 0, s = 0;
  for (i = 2; i <= n; i++) {
    if (!pri[i]) pri[++len] = i, low[i] = i, phi[i] = i - 1;
    for (j = 1; j <= len && (t = i * pri[j]) <= n; j++) {
      pri[t] = 1;
      low[t] = pri[j];
      if (i % pri[j])
        phi[t] = phi[i] * phi[pri[j]];
      else {
        phi[t] = phi[i] * pri[j];
        break;
      }
    }
  }
  for (i = 2; i <= n; i++) sum[low[i]]++;
  for (i = 2; i <= n; i++) sum[i] += sum[i - 1];
  for (i = 2; i <= n; i++)
    if (low[i] <= n / 2) {
      ans += tot++ * 3;
      ans -= i - 1 - phi[i];
      s += sum[n / low[i]] - (1LL * low[i] * low[i] <= n);
    }
  ans -= s / 2;
  cout << ans << endl;
  return 0;
}
