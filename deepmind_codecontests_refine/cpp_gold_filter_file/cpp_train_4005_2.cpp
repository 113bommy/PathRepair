#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  long long int n, m;
  long long int b = 1;
  while (t--) {
    cin >> m >> n;
    while (true) {
      if ((m | b) <= n)
        m = m | b;
      else
        break;
      b <<= 1;
    }
    cout << m << "\n";
    b = 1;
  }
}
