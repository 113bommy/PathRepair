#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long n, T;
  cin >> n >> T;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  for (long long i = 0; i < n; i++) arr[i] -= (i + 1);
  long long ans = 1;
  multiset<long long> S;
  S.insert(-102345667812323);
  for (long long i = 0; i < min(T - 1, n); i++) {
    long long limit = T - i - 1;
    long long x = arr[i];
    auto it = S.lower_bound(x);
    if (it == S.end())
      S.insert(arr[i]);
    else
      S.insert(*it);
    while (true) {
      auto L = S.end();
      L--;
      if (*L < limit) break;
      S.erase(L);
    }
    long long res = S.size();
    ans = max(ans, res);
  }
  cout << ans - 1;
}
