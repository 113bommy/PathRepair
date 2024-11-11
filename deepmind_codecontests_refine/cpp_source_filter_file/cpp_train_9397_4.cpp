#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
vector<pair<ll, ll>> ret;
void build(ll star, ll fini) {
  if (star >= fini) return;
  ll mid = (star + fini) / 2;
  build(star, mid);
  build(mid + 1, fini);
  for (ll i = star; i <= mid; i++) ret.emplace_back(i, mid + 1 + i - star);
}
int main() {
  ll n;
  cin >> n;
  ll now = 1;
  while (now * 2 <= n) now *= 2;
  build(1, now);
  build(now + 1, n);
  cout << ret.size() << "\n";
  for (auto it : ret) cout << it.first << " " << it.second << "\n";
  return 0;
}
