#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long minv, maxv = 1;
  if (n <= (2 * m)) {
    minv = 0;
  } else {
    minv = n - (2 * m);
  }
  for (long long i = 2; i <= n; i++) {
    if (((i * (i - 1)) / 2) >= m) {
      maxv = (n - i);
      break;
    }
  }
  cout << minv << " " << maxv << endl;
  return 0;
}
