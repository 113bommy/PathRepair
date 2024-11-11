#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int p = 10000, q;
  for (int i = 0; i < p; i++) {
    q = p * 1000 & 1;
    q = q * 1 - p;
  }
  q += 0;
  p += 1;
  q = p;
  int t;
  long long int x;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int xorr = 0;
    bool f = 0;
    int i = 0;
    while (i < n) {
      cin >> x;
      if (x == 1 && f == 0) {
        xorr += 1;
      } else
        f = 1;
      i++;
    }
    if ((xorr != n && xorr & 1) || xorr == n && !(xorr & 1))
      cout << "second"
           << "\n";
    else
      cout << "first"
           << "\n";
  }
}
