#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, ans;
  cin >> n >> k;
  if (k == 1)
    ans = 1;
  else if (k == 2)
    ans = 1 + n * (n - 1) / 2;
  else if (k == 3)
    ans = 1 + n * (n - 1) / 2 + 2 * n * (n - 1) * (n - 2) / 6;
  else if (k == 4)
    ans = 1 + n * (n - 1) / 2 + 2 * n * (n - 1) * (n - 2) / 6 +
          9 * n * (n - 1) * (n - 2) * (n - 3) / 24;
  cout << ans << endl;
}
