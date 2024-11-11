#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, second;
  cin >> n >> second;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    ans = max(ans, a + b);
  }
  cout << ans;
  return 0;
}
