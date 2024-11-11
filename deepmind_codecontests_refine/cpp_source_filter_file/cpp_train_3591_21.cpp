#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int l, u, n, d = 0, i = 0, m = 0, c = 0, x, y, j = 0, k = 0,
                         sum = 0, s = 0, w = 1;
  cin >> n;
  cin >> k;
  s = n - k;
  c = k - 1;
  if (n == 1 && k == 1) {
    cout << k;
  } else if (s >= c) {
    cout << k + 1;
  } else
    cout << k - 1;
  return 0;
}
