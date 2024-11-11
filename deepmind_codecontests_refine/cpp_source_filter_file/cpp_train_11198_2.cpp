#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a, b;
  cin >> n >> m;
  int ans = 100005;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    ans = min(ans, b - a + 1);
  }
  cout << ans << endl;
  for (int i = 0; i < m; i++) cout << i % ans << endl;
  return 0;
}
