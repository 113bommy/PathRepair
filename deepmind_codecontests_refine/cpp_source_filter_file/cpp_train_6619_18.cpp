#include <bits/stdc++.h>
using namespace std;
int n, bal, ans, a;
bool u[100050];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    if (!u[a]) {
      u[a] = 1;
      bal++;
    } else {
      u[a] = 0;
      bal--;
    }
    ans = max(ans, bal);
  }
  cout << ans;
  return 0;
}
