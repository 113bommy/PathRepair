#include <bits/stdc++.h>
using namespace std;
int n, K[110], w[110];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> K[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int sum = 15 * K[i];
    for (int j = 1; j <= K[i]; j++) {
      cin >> w[j];
      sum += 5 * w[j];
    }
    ans = max(ans, sum);
  }
  cout << ans;
  return 0;
}
