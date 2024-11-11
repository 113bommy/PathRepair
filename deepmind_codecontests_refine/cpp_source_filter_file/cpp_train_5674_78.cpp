#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, a, maxp, maxi;
  cin >> n >> m;
  vector<long long> f(n, 0);
  while (m--) {
    maxp = -1;
    for (long long i = 0; i < n; i++) {
      cin >> a;
      if (a > maxp) {
        maxp = a;
        maxi = i;
      }
    }
    f[maxi]++;
  }
  long long maxra = -1;
  for (long long i = 0; i < n; i++) {
    if (f[i] > maxra) {
      maxra = a;
      maxi = i;
    }
  }
  cout << maxi + 1 << endl;
  return 0;
}
