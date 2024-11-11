#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 7;
bitset<N> a[60];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, m;
  cin >> m >> n;
  for (int i = 0, t; i < m; i++) {
    cin >> t;
    for (int j = 0, x; j < t; j++) cin >> x, a[i].set(x);
    for (int j = 0; j < i; j++)
      if ((a[i] | (~a[j])) == a[i]) return cout << "impossible" << endl, 0;
  }
  cout << "possible\n";
  return 0;
}
