#include <bits/stdc++.h>
using namespace std;
const int imax = numeric_limits<int>::max(), imin = numeric_limits<int>::min();
const long long lmax = numeric_limits<long long>::max(),
                lmin = numeric_limits<long long>::min();
bool Svd = 0;
void solve() {
  Svd = 1;
  int n, m, k;
  cin >> n >> m >> k;
  cout << (n <= m and n <= k ? "YES" : "NO") << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  if (!Svd) cout << "solve() function blm dipanggil!" << endl;
  return 0;
}
