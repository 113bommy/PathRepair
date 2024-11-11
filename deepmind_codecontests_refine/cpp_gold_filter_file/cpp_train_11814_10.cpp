#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, ans;
  cin >> m >> n;
  if (m % 2 && n % 2) {
    ans = ((m - 1) * n) / 2;
    ans += n / 2;
    cout << ans;
    return 0;
  } else {
    cout << (m * n) / 2;
    return 0;
  }
}
