#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if ((n + k) % 2 == 0 && k * k <= n)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
