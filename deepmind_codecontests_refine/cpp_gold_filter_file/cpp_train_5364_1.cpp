#include <bits/stdc++.h>
using namespace std;
string second[44];
int main() {
  ios_base::sync_with_stdio(0);
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) cin >> second[i];
  long long k = 1;
  long long ans = 1ll * p / 2;
  for (int i = n - 2; i >= 0; i--) {
    if (second[i] == "halfplus") {
      k = k * 2 + 1;
      ans += 1ll * p / 2 * k;
    } else {
      k = k * 2;
      ans += 1ll * p / 2 * k;
    }
  }
  cout << ans;
  return 0;
}
