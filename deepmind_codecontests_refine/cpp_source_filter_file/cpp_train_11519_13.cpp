#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, k;
  cin >> n >> m >> k;
  if (n == 1) {
    long long a;
    cin >> a;
    cout << min(m, a);
    return 0;
  }
  if ((n & 1) == 0) {
    cout << 0;
    return 0;
  }
  long long mn = 10000000;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    if ((i & 1) == 0) mn = min(a, mn);
  }
  long long need = (n / 2) + 1;
  if (m < need) {
    cout << 0;
    return 0;
  }
  long long cntof = m / need;
  cout << min(k * cntof, mn);
}
