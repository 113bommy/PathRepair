#include <bits/stdc++.h>
using namespace std;
int n, a[15], t = 100;
int32_t main() {
  ios_base ::sync_with_stdio(0);
  cin.tie();
  cout.tie();
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i], t = min(t, a[i]);
  cout << (2 + (a[3] ^ t));
}
