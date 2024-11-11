#include <bits/stdc++.h>
using namespace std;
unsigned long long ans, s[201000], n, pre[201000], last[201000], other[201000],
    p, q, tot;
void add(unsigned long long p, unsigned long long q) {
  pre[++tot] = last[p];
  last[p] = tot;
  other[tot] = q;
}
void dfs(unsigned long long x, unsigned long long f) {
  s[x] = 1LL;
  unsigned long long t = 0LL;
  for (unsigned long long j = last[x]; j; j = pre[j]) {
    unsigned long long k = other[j];
    if (k == f) continue;
    dfs(k, x);
    t += s[x] * s[k];
    s[x] += s[k];
  }
  ans -= t * (t + 2LL * s[x] * (n - s[x]));
}
int main() {
  cin >> n;
  ans = (n * (n - 1LL) / 2LL) * (n * (n - 1LL) / 2LL);
  for (unsigned long long i = 1; i < n; i++) {
    cin >> p >> q;
    add(p, q), add(q, p);
  }
  dfs(1, 0);
  cout << ans << endl;
}
