#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += (m + i) / 5 - i / 5;
  }
  cout << ans;
  return 0;
}
