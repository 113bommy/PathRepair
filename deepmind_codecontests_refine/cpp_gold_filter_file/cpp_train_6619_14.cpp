#include <bits/stdc++.h>
using namespace std;
bool use[200000];
int main() {
  int n, i, ans = 0, k = 0, a;
  cin >> n;
  for (i = 0; i < 2 * n; i++) {
    cin >> a;
    a--;
    if (!use[a]) {
      use[a] = 1;
      k++;
    } else {
      use[a] = 0;
      k--;
    }
    ans = max(ans, k);
  }
  cout << ans;
  return 0;
}
