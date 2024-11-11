#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t, s, q, k = 1;
  cin >> t >> s >> q;
  while (q * s < t) {
    k++;
    s = s * 2;
  }
  cout << k;
}
