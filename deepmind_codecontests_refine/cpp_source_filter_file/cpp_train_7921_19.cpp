#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n <= 2 && m <= 2) {
    cout << 0 << endl;
  } else {
    if (n == 1) {
      if (m <= 3)
        printf("%lld\n", m - m % 6);
      else
        printf("%lld", m - (6 - m % 6));
    } else if (n == 2) {
      long long tot = n * m;
      if (m == 3 || m == 7) tot -= 2;
      printf("%lld\n", tot);
    } else if (n % 2 && m % 2) {
      printf("%lld\n", n * m - 1);
    } else
      printf("%lld\n", n * m);
  }
}
