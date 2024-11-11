#include <bits/stdc++.h>
using namespace std;
long int n, m, i, j, a, b, ans;
int move(long int l, long int x) {
  if (l == 0 && x == 0) return 0;
  if (l % a != 0 || x % b != 0) return 1000000007;
  l /= a;
  x /= b;
  if ((l == 0 && n <= a && x > 0) || (x == 0 && m <= b && l > 0))
    return 1000000007;
  if (l % 2 == x % 2) {
    return max(l, x);
  }
  return 1000000007;
}
int main() {
  cin >> n >> m >> i >> j >> a >> b;
  ans = min(min(move(n - i, j - 1), move(n - i, m - j)),
            min(move(i - 1, m - j), move(i - 1, j - 1)));
  if (ans != 1000000007)
    cout << ans;
  else
    cout << "Poor Inna and pony!";
  return 0;
}
