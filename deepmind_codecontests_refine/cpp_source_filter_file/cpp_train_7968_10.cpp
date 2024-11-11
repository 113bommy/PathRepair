#include <bits/stdc++.h>
using namespace std;
int main() {
  long n, k, m;
  cin >> n;
  if (n % 2 == 0) {
    k = pow(n, 2) / 4 + 1;
    m = k - 2;
  } else {
    k = (pow(n, 2) + 1) / 2;
    m = (pow(n, 2) - 1) / 2;
  }
  if (k > 0 && m > 0)
    cout << m << " " << k;
  else
    cout << -1;
}
