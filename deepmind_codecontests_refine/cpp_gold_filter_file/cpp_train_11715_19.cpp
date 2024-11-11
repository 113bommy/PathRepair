#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5, K = 30, Mod = 1e9 + 7;
const long long INF = ~0ull >> 1;
int n, m, k;
char s[N];
int f[N], pre[N], pos[K];
void Init() { scanf("%d%d%s", &n, &k, s + 1); }
int main() {
  Init();
  f[0] = pre[0] = 1;
  for (m = 1; s[m]; m++) {
    if (pos[s[m] - 'a'])
      f[m] = (pre[m - 1] - pre[pos[s[m] - 'a'] - 1]) % Mod;
    else
      f[m] = pre[m - 1];
    pre[m] = (pre[m - 1] + f[m]) % Mod;
    pos[s[m] - 'a'] = m;
  }
  m--;
  for (int i = m + 1; i <= n + m; i++) {
    int mn = N, t;
    for (int j = 0; j < k; j++) {
      if (pos[j] < mn) mn = pos[j], t = j;
    }
    if (mn)
      f[i] = (pre[i - 1] - pre[mn - 1]) % Mod;
    else
      f[i] = pre[i - 1];
    pre[i] = (pre[i - 1] + f[i]) % Mod;
    pos[t] = i;
  }
  if (pre[n + m] < 0) pre[n + m] += Mod;
  printf("%d\n", (int)pre[n + m]);
  return 0;
}
