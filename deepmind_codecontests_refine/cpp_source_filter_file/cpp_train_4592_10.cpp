#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int i, j, n, m, t;
  cin >> t;
  while (t--) {
    cin >> m >> n;
    if (m - n > 1)
      cout << "NO" << endl;
    else {
      long long int s = m + n;
      if (s < 2)
        cout << "NO" << endl;
      else {
        long long int f = 1;
        for (i = 2; i * i < s; i++)
          if (s % i == 0) {
            cout << "NO" << endl;
            f = 0;
            break;
          }
        if (f) cout << "YES" << endl;
      }
    }
  }
}
