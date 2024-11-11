#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, ans;
  cin >> n >> k;
  if (k >= 3 * n) {
    ans = 0;
  } else {
    ans = 3 * n - k;
  }
  cout << ans << endl;
  return 0;
}
