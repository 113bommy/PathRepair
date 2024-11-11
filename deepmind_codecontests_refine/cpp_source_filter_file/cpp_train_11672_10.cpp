#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k, l;
  cin >> n >> m >> k >> l;
  if (m >= n) {
    cout << -1;
  } else {
    n = n / m;
    m = (m + k + l - 1) / m;
    if (n >= m) {
      cout << m;
    } else {
      cout << -1;
    }
  }
  return 0;
}
