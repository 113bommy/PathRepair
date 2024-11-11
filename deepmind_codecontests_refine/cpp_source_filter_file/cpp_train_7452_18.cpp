#include <bits/stdc++.h>
using namespace std;
int main() {
  long long m, k, n, t;
  cin >> n >> m >> k;
  if (n % 2 == 0) {
    cout << "Marsel" << endl;
    return 0;
  } else {
    long long square_root = (long long)sqrt(m) + 1;
    for (long long i = 2; i < square_root; i++) {
      if (m % i == 0) {
        if ((i >= k && i < m) || (m / i >= k && m / i < m)) {
          cout << "Timur" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Marsel" << endl;
  return 0;
}
