#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (m == 0) {
    cout << n << " " << n << endl;
    return 0;
  }
  long long le = m - (n >> 1);
  if (le < 0) {
    le = (-le) << 1;
    le += n & 1;
  } else if (le == 0 && n & 1) {
    --le;
    if (le < 0) le = 1;
  } else
    le = 0;
  int ma;
  for (int i = 1; i <= n; ++i) {
    long long che = (i * (i - 1)) >> 1;
    if (che >= m) {
      ma = i;
      break;
    }
  }
  cout << le << " " << n - ma << endl;
  return 0;
}
