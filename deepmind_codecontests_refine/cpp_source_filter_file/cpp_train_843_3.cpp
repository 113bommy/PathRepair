#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
char s[MAXN], t[MAXN];
int pi[MAXN], cnt[MAXN];
int getnxt(int i, char c) {
  if (t[i + 1] == c) return i + 1;
  return pi[i] ? getnxt(pi[i], c) : 0;
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  for (int i = 2; i <= m; i++) pi[i] = getnxt(pi[i - 1], t[i]);
  for (int i = 1, j = 0; i <= n; i++) {
    j = getnxt(j, s[i]);
    if (j == m) j = pi[j];
    cnt[j < i ? j : pi[j]]++;
  }
  for (int i = m; i >= 1; i--) cnt[pi[i]] += cnt[i];
  long long ans = 1ll * n * m;
  for (int i = 1; i <= m; i++)
    if (pi[i]) ans -= cnt[i - pi[i]];
  printf("%lld\n", ans);
  return 0;
}
