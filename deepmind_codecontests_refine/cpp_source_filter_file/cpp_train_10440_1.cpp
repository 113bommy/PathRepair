#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
  cin >> n >> m;
  if (n > m) swap(n, m);
  if (n == 1) {
    cout << m << endl;
    return 0;
  } else if (n == 2) {
    cout << 2 * (m / 4 + min(2, m % 4)) << endl;
    return 0;
  }
  if ((n * m) % 2 == 1) {
    int tp1 = n * (m - 1) / 2 + (n + 1) / 2,
        tp2 = m * (n - 1) / 2 + (m + 1) / 2;
    cout << max(tp1, tp2) << endl;
  } else {
    int ans = 0;
    if (m % 2 == 0 && n % 2 == 0) {
      ans = (n * m) / 2;
    } else if (m % 2 == 1) {
      ans = (m - 1) * n / 2;
      ans += n / 2;
    } else {
      ans = m * (n - 1) / 2;
      ans += m / 2;
    }
    cout << max(ans, n * m / 2) << endl;
  }
}
