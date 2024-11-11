#include <bits/stdc++.h>
using ll = long long;
const ll maxn = 1234;
const ll inf = 1e9 + 7;
int main(int argc, char *argv[]) {
  ll n, m, a[maxn];
  std::cin >> n >> m;
  ll cur = 0, maxx = 0, minn = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    cur += a[i];
    maxx = std::max(maxx, cur);
    minn = std::min(minn, cur);
  }
  ll ans = maxx - minn;
  if (maxx - minn > m) {
    std::cout << 0;
  } else {
    std::cout << m - (maxx - minn) + 1;
  }
}
