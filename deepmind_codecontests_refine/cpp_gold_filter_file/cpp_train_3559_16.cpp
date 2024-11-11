#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
const int INF = 2000000;
long long n, m = 0, t, x, y, min1 = INF, max1 = 0, k, c, d, p;
set<long long> used;
long long check(long long k) {
  t = n - k * p;
  if (t <= 0 || k > t) {
    return -1;
  }
  long long ans = 0;
  while (t != 1) {
    if (t % 2 == 1) {
      ans++;
      t--;
      t /= 2;
    } else {
      t /= 2;
    }
  }
  return ans + 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> p;
  for (int i = 1; i <= 1000; i++) {
    if (i >= check(i) && i <= n - i * p) {
      cout << i;
      return 0;
    }
  }
  cout << -1;
  return 0;
}
