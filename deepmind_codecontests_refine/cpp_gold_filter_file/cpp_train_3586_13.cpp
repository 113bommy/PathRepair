#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, i, ls;
  cin >> n >> m >> k;
  long long lo = 1, hi = n * m, mid;
  while (hi - lo > 1) {
    mid = (lo + hi) / 2;
    ls = 0;
    for (i = 1; i <= n; i++) ls += min((mid - 1) / i, m);
    if (ls < k)
      lo = mid;
    else
      hi = mid - 1;
  }
  ls = 0;
  for (i = 1; i <= n; i++) ls += min((hi - 1) / i, m);
  if (ls < k)
    cout << hi << endl;
  else
    cout << lo << endl;
  return 0;
}
