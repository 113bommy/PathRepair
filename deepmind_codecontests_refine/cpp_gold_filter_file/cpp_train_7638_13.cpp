#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n, m, d;
  cin >> n >> m >> d;
  n *= m;
  int ar[n];
  for (int ctr1 = 0; ctr1 < n; ctr1++) cin >> ar[ctr1];
  int mo = ar[0] % d;
  for (int ctr1 = 0; ctr1 < n; ctr1++) {
    if (ar[ctr1] % d != mo) {
      cout << -1;
      return 0;
    }
    ar[ctr1] /= d;
  }
  long long rez = 1e9;
  for (int ctr2 = 0; ctr2 <= 10000; ctr2++) {
    long long cur = 0;
    for (int ctr1 = 0; ctr1 < n; ctr1++) {
      cur += abs(ar[ctr1] - ctr2);
    }
    rez = min(rez, cur);
  }
  cout << rez;
  return 0;
}
