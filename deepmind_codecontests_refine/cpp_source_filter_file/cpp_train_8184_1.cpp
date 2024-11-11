#include <bits/stdc++.h>
using namespace std;
long long n, m, k;
long long dim = 0x7fffffffffffffff;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    cout << "0\n";
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    long long t;
    cin >> t;
    if (i & 1) continue;
    dim = min(dim, t);
  }
  cout << min(dim, k * (m / (n - 1))) << "\n";
  return 0;
}
