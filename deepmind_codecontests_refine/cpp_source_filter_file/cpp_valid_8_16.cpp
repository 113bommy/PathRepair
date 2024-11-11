#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  unsigned int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    if (n % 3 == 0)
      cout << n / 3 << " " << n / 3 << endl;
    else if (n % 3 == 0)
      cout << n / 3 + 1 << " " << n / 3 << endl;
    else
      cout << n / 3 << " " << n / 3 + 1 << endl;
  }
}
