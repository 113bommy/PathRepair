#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t, k;
  t = 1;
  while (t--) {
    long long a, b, r;
    cin >> a >> b >> r;
    if (a / (2 * r) + b / (2 * r) <= 1)
      cout << "Second";
    else
      cout << "First";
  }
}
