#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, ans[3] = {0, 0, 0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    ans[k % 3]++;
  }
  int cnt = ans[0] / 2 + min(ans[1], ans[2]);
  cout << ans << endl;
  return 0;
}
