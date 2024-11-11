#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int inf = 1e9;
const long long mod = 1000000007;
long long f[maxn], w[maxn];
long long a1[maxn], a2[maxn];
int cur[maxn];
long long sm[maxn][40], mi[maxn][40], nxt[maxn][40];
int main() {
  long long n, k;
  scanf("%I64d%I64d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%I64d", &f[i]);
  for (int i = 0; i < n; i++) scanf("%I64d", &w[i]);
  for (int i = 0; i < n; i++) {
    sm[i][0] = w[i];
    mi[i][0] = w[i];
    nxt[i][0] = f[i];
    cur[i] = i;
  }
  memset(a1, 0, sizeof(a1));
  memset(a2, 0x3f, sizeof(a2));
  for (long long _ = 1;; _++) {
    for (int i = 0; i < n; i++) {
      if (k & 1) {
        a1[i] += sm[cur[i]][_ - 1];
        a2[i] = min(a2[i], mi[cur[i]][_ - 1]);
        cur[i] = nxt[cur[i]][_ - 1];
      }
      int la = nxt[i][_ - 1];
      sm[i][_] = sm[i][_ - 1] + sm[la][_ - 1];
      mi[i][_] = min(mi[i][_ - 1], mi[la][_ - 1]);
      nxt[i][_] = nxt[la][_ - 1];
    }
    k >>= (long long)1;
    if (!k) break;
  }
  for (int i = 0; i < n; i++) cout << a1[i] << ' ' << a2[i] << endl;
  return 0;
}
