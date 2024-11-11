#include <bits/stdc++.h>
using namespace std;
int n, m, t, x, cnt[130], P = 1000000007;
long long ans;
void dfs(int x, long long a, bitset<120> S) {
  if (x > m / 2) {
    (ans += a) %= P;
    return;
  }
  dfs(x + 1, a, S);
  if (cnt[x] && !S[x])
    dfs(x + 1, a * cnt[x] % P,
        S | (S << x) | (S >> x) | (S << (n - x)) | (S >> (n - x)));
}
int main() {
  scanf("%d%d%d", &n, &m, &t);
  for (int i = 0; i < t; i++) scanf("%d", &x), x %= m, cnt[min(x, m - x)]++;
  bitset<120> S;
  S[0] = 1;
  dfs(0, 1, S);
  printf("%I64d\n", ans);
}
