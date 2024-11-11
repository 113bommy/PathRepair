#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int n, k, ans;
  cin >> n >> k;
  if (k >= n / 2) {
    ans = ((n - 1) * n) / 2;
  } else {
    ans = (n * (n - 1)) / 2;
    ans = ans - ((n - 2 * k - 1) * (n - 2 * k)) / 2;
  }
  if (ans <= 0) {
    ans = 0;
  }
  cout << ans << endl;
  return 0;
}
