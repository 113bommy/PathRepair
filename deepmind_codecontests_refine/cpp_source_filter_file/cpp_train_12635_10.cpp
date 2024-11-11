#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0, k, a, minn = 100000000;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (a < 0 && k > 0)
      sum -= a, k--;
    else
      sum += a;
    if (abs(a) < minn) minn = a;
  }
  if (k & 1) sum -= (minn * 2);
  cout << sum << endl;
  return 0;
}
