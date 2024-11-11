#include <bits/stdc++.h>
using namespace std;
int n, p[1000], k;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    if (p[i] <= k)
      ans++;
    else
      ans += 2;
  }
  cout << ans;
  return 0;
}
