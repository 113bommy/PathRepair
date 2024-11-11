#include <bits/stdc++.h>
using namespace std;
long long n, m, k, s[1020001], pv[1020001], a[1020001], vs[1020001];
long long es(long long x) { return a[x] * (n / x + (n % x == 0 ? 0 : 1)); }
long long cp(long long x) {
  long long c = 0, i = 0, res = 0;
  while (c < n) {
    c += x, res++;
    while (i < m && s[i] < c) i++;
    if (i < m && s[i] == c) c = pv[i];
    (0);
  }
  (0);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) cin >> s[i];
  for (int i = 1; i <= k; i++) cin >> a[i];
  if (m > 0 && s[0] == 0) {
    return cout << "-1\n", 0;
  }
  long long lg = m > 0 ? 1 : 0;
  pv[0] = s[0] - 1;
  for (long long i = 1, gs = 1; i < m; i++) {
    if (s[i] == s[i - 1] + 1)
      gs++, lg = max(gs, lg);
    else
      gs = 1;
    pv[i] = s[i] - gs;
  }
  long long mk = lg + 1;
  if (mk > k) return cout << "-1\n", 0;
  for (long long i = mk; i <= k; i++) vs[i - mk] = i;
  sort(vs, vs + k - mk + 1,
       [&](long long x, long long y) { return es(x) < es(y); });
  long long bs = 100000000000000000;
  for (long long i = 0; i < k - mk + 1; i++) {
    (0);
    if (bs < es(vs[i])) break;
    bs = min(bs, a[vs[i]] * cp(vs[i]));
  }
  cout << bs << '\n';
}
