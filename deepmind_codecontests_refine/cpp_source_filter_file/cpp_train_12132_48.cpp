#include <bits/stdc++.h>
using namespace std;
int main() {
  long long tem, n, m, ans;
  while (cin >> n) {
    if (n > 31)
      ans = pow(2, n) - (pow(2, 24) * 25);
    else
      ans = pow(2, n);
    cout << ans << "\n";
  }
}
