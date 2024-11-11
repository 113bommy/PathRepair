#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  int ans = 0, a;
  for (i = 0; i < n; i++) {
    cin >> a;
    ans += a * a;
  }
  cout << ans;
  return 0;
}
