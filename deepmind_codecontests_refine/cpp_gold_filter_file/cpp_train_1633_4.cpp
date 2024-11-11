#include <bits/stdc++.h>
using namespace std;
int main() {
  unsigned long long int n, m, a, b;
  cin >> n >> m >> a >> b;
  if (n % m == 0) {
    cout << "0";
    return 0;
  } else if (n > m) {
    unsigned long long int p = (n / m) + 1;
    unsigned long long int c = (m * p - n) * a;
    unsigned long long int d = (n % m) * b;
    cout << min(c, d) << endl;
    return 0;
  } else if (m > n) {
    unsigned long long int c = (m - n) * a;
    unsigned long long int d = n * b;
    cout << min(c, d) << endl;
    return 0;
  }
}
