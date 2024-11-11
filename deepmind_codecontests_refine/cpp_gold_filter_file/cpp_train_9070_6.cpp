#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  cout << w1 + w2 + 4 + 2 * (h1 + h2) + w1 - w2;
  return 0;
}
