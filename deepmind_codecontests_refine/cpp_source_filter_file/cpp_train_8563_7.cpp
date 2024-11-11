#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, r, j = 0, sum = 0, k, m;
  cin >> n;
  vector<long long> a;
  for (i = 2; i < n; i++) {
    r = n;
    while (r) {
      k = r % i;
      a.push_back(k);
      j++;
      r = r / i;
    }
  }
  m = n - 2;
  for (i = 0; i < j; i++) sum += a[i];
  for (i = 2; i < n; i++) {
    if (sum % i == 0 && m % i == 0) {
      sum = sum / i;
      m = m / i;
    }
  }
  cout << sum << "/" << m;
}
