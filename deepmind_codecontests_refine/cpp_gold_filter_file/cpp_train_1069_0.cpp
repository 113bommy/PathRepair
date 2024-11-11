#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
long long f(long long l, long long p) {
  long long fl = l / p;
  return fl * fl * (p - l % p) + (fl + 1) * (fl + 1) * (l % p);
}
int a[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) cin >> a[i];
  multiset<array<long long, 3>> pq;
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += f(a[i], 1);
    if (a[i] > 1) pq.insert({f(a[i], 2) - f(a[i], 1), a[i], 1});
  }
  k -= n;
  while (k > 0 && !pq.empty()) {
    auto now = *pq.begin();
    pq.erase(pq.begin());
    ans += now[0];
    if (now[1] > now[2] + 1) {
      pq.insert(
          {f(now[1], now[2] + 2) - f(now[1], now[2] + 1), now[1], now[2] + 1});
    }
    k--;
  }
  cout << ans << '\n';
}
