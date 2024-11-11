#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = abs(abs(n) - abs(m));
  if (n + ans == m) {
    cout << ans << endl;
  } else if (-n + ans == m && -(n + ans) == m) {
    cout << ans + 1 << endl;
  } else {
    cout << ans + 2 << endl;
  }
}
