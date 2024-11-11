#include <bits/stdc++.h>
using namespace std;
long long i, j, n, m, k, t, x, y, d, s, a[100], b[100];
int main() {
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> k;
    a[k]++;
  }
  for (i = 1; i <= n; i++) {
    cin >> k;
    b[k]++;
  }
  for (i = 1; i <= 5; i++) {
    if ((a[i] + b[i]) % 2 != 0) {
      cout << -1;
      return 0;
    }
    t += abs(a[i] - b[i]) / 2;
  }
  cout << t / 2;
}
