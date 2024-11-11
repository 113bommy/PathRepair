#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, r, a, b, k;
  cin >> n >> a >> b;
  if (min(a, b) == 0) {
    long long res = max(a, b) * (n - 1);
    cout << res << "\n";
    return 0;
  }
  map<long long, long long> mp;
  mp[0] = 1;
  n--;
  while (n) {
    long long cost = mp.begin()->first;
    long long cnt = mp.begin()->second;
    if (cnt <= n)
      mp.erase(mp.begin());
    else
      mp[cost] -= n;
    int erased = min((long long)n, cnt);
    mp[a + cost] += erased;
    mp[b + cost] += erased;
    n -= erased;
  }
  long long ans = 0;
  for (auto it : mp) ans += it.first * it.second;
  cout << ans;
  return 0;
}
