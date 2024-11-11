#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t, n, a, nech = 0;
  cin >> t;
  for (long long q = 0; q < t; q++) {
    cin >> n;
    for (long long i = 0; i < n; i++) {
      cin >> a;
      if (a & 1) nech++;
    }
    if (nech == 0 || (nech == n && n & 1)) {
      cout << "NO" << endl;
    } else
      cout << "YES" << endl;
    nech = 0;
  }
  return 0;
}
