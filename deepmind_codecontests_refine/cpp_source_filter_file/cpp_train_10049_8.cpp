#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
const long long N = 1e6 + 7;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, k;
  cin >> n >> k;
  long long c = n - (2 * k);
  if (k < n)
    cout << n * (n - 1) / 2 - c * (c - 1) / 2;
  else
    cout << n * (n - 1) / 2;
}
