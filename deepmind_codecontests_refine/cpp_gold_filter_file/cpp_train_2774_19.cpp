#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
int main() {
  long long mi = 0, mix = 1, mixn = 0, n, k, i, tmp;
  cin >> n >> k;
  for (i = 1; i <= k; i++) {
    cin >> tmp;
    if (n / tmp * tmp > mi) mi = n / tmp * tmp, mix = i, mixn = n / tmp;
  }
  cout << mix << " " << mixn << "\n";
}
