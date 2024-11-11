#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    unsigned long long m, n;
    cin >> m >> n;
    long long max = -1;
    long long diff = n - m;
    long long a = n / 2;
    if (m < (n / 2)) {
      cout << n % (a + 1);
    } else {
      cout << n % m;
    }
    cout << endl;
  }
  return 0;
}
