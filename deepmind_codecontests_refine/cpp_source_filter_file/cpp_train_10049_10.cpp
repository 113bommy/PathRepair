#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < k && n > 2; i++) {
    ans += n - 1 + n - 2;
    n -= 2;
  }
  cout << ans;
}
