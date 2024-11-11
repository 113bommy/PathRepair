#include <bits/stdc++.h>
const int INF = 1 << 29;
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  ;
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;
  cout << min({k * l / nl, c * d, p / np}) / n;
  return 0;
}
