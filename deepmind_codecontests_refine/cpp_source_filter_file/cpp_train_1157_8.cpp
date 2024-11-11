#include <bits/stdc++.h>
using namespace std;
int que;
int n, ans;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> que;
    ans += 4 * que * (i - 1);
  }
  cout << ans << endl;
  return 0;
}
