#include <bits/stdc++.h>
using namespace std;
int cnt[3000007];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  int mx = INT_MIN;
  for (int i = 1; i <= n; i++) {
    int t;
    cin >> t;
    cnt[t]++;
    mx = max(mx, t);
  }
  for (int i = 1; i <= 2 * mx; i++) {
    cnt[i] += cnt[i - 1];
  }
  int ans = INT_MIN;
  for (int i = 2; i <= mx; i++) {
    int temp = 0;
    for (int j = i; j <= mx; j += i) {
      int last = min(j + i - 1, j + k);
      temp += (cnt[last] - cnt[j - 1]);
    }
    if (temp == n) ans = max(ans, i);
  }
  cout << ans << endl;
  return 0;
}
