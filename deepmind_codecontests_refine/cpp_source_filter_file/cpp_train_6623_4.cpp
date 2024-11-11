#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, x, a, sum = 0, i;
  cin >> n >> k >> x;
  for (i = 1; i <= n - k; i++) {
    cin >> a;
    if (i <= n - k)
      sum = sum + a;
    else
      sum = sum + x;
  }
  cout << sum << endl;
  return 0;
}
