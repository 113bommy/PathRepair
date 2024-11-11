#include <bits/stdc++.h>
using namespace std;
const int MX = 1e5 + 3, mod = 1e9 + 7;
int n, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 2; i < n; i++) {
    int a = i * 2;
    while (a <= n) {
      ans += a / i;
      a += i;
    }
  }
  cout << ans * 4 << endl;
  return 0;
}
