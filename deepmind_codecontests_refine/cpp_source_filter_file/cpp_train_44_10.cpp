#include <bits/stdc++.h>
using namespace std;
int N, T, M, K;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i <= a; i++) {
    for (int j = 0; j <= b; j++) {
      double sum = (double)n - (0.5) * (double)i - (1.0) * (double)j;
      if (floor(sum) == ceil(sum)) {
        if (sum > 0 && (int)sum % 2 == 0 && sum / 2 <= c) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
