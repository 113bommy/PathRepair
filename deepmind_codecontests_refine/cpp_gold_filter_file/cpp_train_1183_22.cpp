#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, m;
  while (cin >> n >> m) {
    long i, a[1000] = {0}, k;
    map<long, long> mp;
    for (i = 0; i < n; i++) {
      cin >> a[i];
      mp[a[i]] = 1;
    }
    sort(a, a + n);
    if (n < m)
      cout << -1 << endl;
    else {
      k = a[n - m];
      cout << k << " 0\n";
    }
  }
  return 0;
}
