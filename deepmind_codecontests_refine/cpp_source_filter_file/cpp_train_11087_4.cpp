#include <bits/stdc++.h>
using namespace std;
long long n, i, a[100005], r[100005], m;
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  r[n] = 0;
  for (i = n - 1; i >= 1; i--) {
    m = max(m, a[i + 1]);
    r[i] = m;
  }
  for (i = 1; i <= n; i++) {
    if (r[i] > a[i]) {
      cout << r[i] - a[i] + 1 << " ";
    } else {
      cout << "0 ";
    }
  }
  return 0;
}
