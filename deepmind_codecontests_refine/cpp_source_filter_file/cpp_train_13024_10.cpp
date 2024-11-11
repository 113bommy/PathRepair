#include <bits/stdc++.h>
using namespace std;
const int32_t INFint = 1e9;
const long long INFll = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long n, k;
  cin >> n >> k;
  if (n % k == 0)
    cout << k / n << '\n';
  else
    cout << k / n + 1 << '\n';
}
