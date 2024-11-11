#include <bits/stdc++.h>
using namespace std;
long long f[1010], g[1010], s[1010];
int p[1010];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  f[1] = 1;
  g[1] = 1;
  s[1] = 1;
  for (int i = 2; i <= n; i++) {
    long long x = (s[i - 1] - s[p[i] - 1] + 1000000007) % 1000000007;
    g[i] = (x + 1 + (i - p[i])) % 1000000007;
    f[i] = (g[i] + f[i - 1] + 1) % 1000000007;
    s[i] = (s[i - 1] + g[i]) % 1000000007;
  }
  long long ans = (f[n] + 1) % 1000000007;
  cout << ans << endl;
}
