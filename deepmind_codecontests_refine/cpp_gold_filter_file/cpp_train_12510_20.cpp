#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, ans = 0, sum = 0, k, ev = 0, rem = 0, root = 0;
  cin >> n >> k;
  sum = 9 + (4 * 2 * (n + k));
  root = sqrt(sum);
  ans = n - ((root - 3) / 2);
  cout << ans << endl;
  return 0;
}
