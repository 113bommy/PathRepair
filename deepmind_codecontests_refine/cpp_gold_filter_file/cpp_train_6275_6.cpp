#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int minn = 1e9 + 10;
    if (n == 1)
      minn = 0;
    else {
      for (int i = 1; i <= 63244 and i <= n; ++i)
        minn = min(minn, i + (n - i - 1) / i);
    }
    cout << minn << '\n';
  }
  return 0;
}
