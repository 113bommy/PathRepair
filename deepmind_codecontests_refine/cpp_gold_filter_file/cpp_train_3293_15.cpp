#include <bits/stdc++.h>
using namespace std;
long long n, L, R, k, t, ans;
long long a[210000], s[210000], v[210000], c[210000], l[210000], r[210000];
priority_queue<pair<long long, long long> > q;
signed main() {
  cin >> n;
  for (long long i = n; i >= 1; i--) scanf("%lld", &a[i]);
  for (long long i = 1; i <= n; i++) {
    if (a[i] == a[i - 1])
      s[t]++;
    else
      c[++t] = a[i], s[t] = 1;
  }
  for (long long i = 1; i <= t; i++)
    l[i] = i - 1, r[i] = i + 1, q.push(make_pair(s[i], i));
  while (!q.empty()) {
    long long k = q.top().second;
    q.pop();
    if (v[k]) continue;
    long long L = l[k], R = r[k];
    l[R] = L, r[L] = R, v[k] = 1;
    if (L && c[L] == c[R])
      l[r[R]] = L, r[L] = r[R], v[R] = 1, q.push(make_pair(s[L] += s[R], L));
    ans++;
  }
  cout << ans;
  return 0;
}
