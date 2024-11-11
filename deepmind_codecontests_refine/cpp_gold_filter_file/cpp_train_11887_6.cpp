#include <bits/stdc++.h>
using namespace std;
void CyBerForCe() {
  long long n;
  cin >> n;
  long long k = 1;
  vector<long long> v(2 * n, 0);
  for (long long i = 0; i < 2 * n;) {
    v[i] = k;
    if (v[(i + n) % (2 * n)] != 0)
      i++;
    else
      i = (i + n) % (2 * n);
    k++;
  }
  if (n % 2 != 0) {
    cout << "YES\n";
    for (auto i : v) cout << i << " ";
  } else
    cout << "NO\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  CyBerForCe();
  return 0;
}
