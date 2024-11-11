#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7, maxn = 2e6 + 10;
long long int ans, n, m, k, x, y, q, cnt[maxn], ps[maxn];
long long int ask(long long int j, long long int i) {
  long long int t = (y / x);
  long long int ansask;
  if (t >= i - 1) {
    ansask = ((j * (cnt[j] - cnt[j - i])) - (ps[j] - ps[j - i])) * x;
  } else {
    long long int u = j - t - 1;
    ansask = ((j * (cnt[j] - cnt[j - u])) - (ps[j] - ps[j - u])) * x;
    ansask += ((cnt[u] - cnt[j - i]) * y);
  }
  return ansask;
}
int32_t main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> y >> x;
  long long int a[n];
  for (long long int i = 0; i < n; i += 1) {
    cin >> a[i];
    cnt[a[i]]++;
    ps[a[i]] += a[i];
    m = max(a[i], m);
  }
  for (long long int i = 1; i < maxn; i += 1) {
    cnt[i] += cnt[i - 1];
    ps[i] += ps[i - 1];
  }
  ans = 1e18;
  for (long long int i = 2; i < m * 2 + 5; i += 1) {
    k = 0;
    for (long long int j = i; j < m * 2 + 5; j += i) {
      k += ask(j, i);
    }
    ans = min(ans, k);
  }
  cout << ans << endl;
  return 0;
}
