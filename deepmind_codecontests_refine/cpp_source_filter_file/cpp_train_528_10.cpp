#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, m, k, t, z;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    if (n > k || m > k)
      cout << "-1";
    else {
      z = k - ((k - n) % 2 + (k - m) % 2);
      cout << z << endl;
    }
  }
  return 0;
}
