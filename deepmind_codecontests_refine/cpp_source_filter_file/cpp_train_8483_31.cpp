#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, sum;
  cin >> n >> m;
  if (n > m) {
    n = n - m;
    cout << m << " ";
    sum = n / 2;
  } else {
    m = m - n;
    cout << n << " ";
    sum = n - m / 2;
  }
  cout << sum;
  return 0;
}
