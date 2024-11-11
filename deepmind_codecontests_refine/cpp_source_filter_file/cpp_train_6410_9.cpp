#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long n, m, k, x, y;
  cin >> n >> m >> k >> x >> y;
  x--;
  y--;
  if (n == 1) {
    cout << (k % m == 0 ? k / m : k / m + 1) << " " << k / m << " "
         << (k % m > y ? k / m + 1 : k / m);
    return 0;
  }
  if (n == 2) {
    cout << (k % (2 * m) == 0 ? k / (2 * m) : k / (2 * m) + 1) << " "
         << k / (2 * m) << " "
         << (k % (2 * m) > y + x * m ? k / (2 * m) + 1 : k / (2 * m));
    return 0;
  }
  long long cycleLength = 2 * (n - 1) * m;
  long long runs = k / cycleLength;
  k %= cycleLength;
  if (k < m) {
    cout << (runs != 0 ? 2 * runs : 1);
  } else if (k <= n * m) {
    cout << 2 * runs + 1;
  } else {
    cout << 2 * runs + 2;
  }
  cout << " ";
  if (k < n * m) {
    cout << runs;
  } else {
    cout << runs + 1;
  }
  cout << " ";
  if (x == 0) {
    cout << runs + (y < k);
  } else if (x == n - 1) {
    cout << runs + (y + x * m < k);
  } else {
    long long ans = 2 * runs;
    if (k > y + x * m) ans++;
    if (k > y + (x + 2 * (n - x)) * m) ans++;
    cout << ans;
  }
  cout << endl;
  return 0;
}
