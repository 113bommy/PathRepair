#include <bits/stdc++.h>
using namespace std;
int t[111];
int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int sum = 0;
  for (int i = 0; i < k; i++) {
    cin >> t[i];
    sum += t[i];
  }
  sort(t, t + k);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    int time = m - sum * i;
    if (time <= 0) break;
    int cnt = (k + 1) * i;
    for (int j = 0; j < k; j++) {
      for (int q = 0; q < (n - i); q++) {
        if (time - t[j] >= 0) {
          cnt++;
          time -= t[j];
        }
      }
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}
