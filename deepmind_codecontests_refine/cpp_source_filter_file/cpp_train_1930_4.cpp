#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6;
const long long mod = 1000000007;
int h[MAXN + 5];
long long S[MAXN + 5];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
  h[0] = ((int)1e9 + 10);
  h[n + 1] = ((int)1e9 + 10);
  long long res1 = 0;
  for (int i = 1; i <= n; i++) res1 = (res1 + h[i] - 1) % mod;
  for (int r = 1; r < n; r++) {
    S[r + 1] = S[r] * min(h[r - 1] - 1, min(h[r] - 1, h[r + 1] - 1)) +
               min(h[r] - 1, h[r + 1] - 1);
    S[r + 1] %= mod;
  }
  long long res2 = 0;
  for (int r = 2; r <= n; r++) {
    long long a = S[r] * min(h[r - 1] - 1, h[r] - 1);
    res2 += a;
    res2 %= mod;
  }
  printf("%d\n", (int)res1 + res2);
}
