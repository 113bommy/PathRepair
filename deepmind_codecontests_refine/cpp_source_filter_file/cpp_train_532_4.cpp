#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int p[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  int s[n + 1];
  for (int i = 1; i < n; i++) {
    cin >> s[i];
  }
  int ans = 0;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    for (int j = 1; j <= n; j++) {
      if (s[j] == s[x]) {
        if (p[j] > p[x]) {
          ans++;
          break;
        }
      }
    }
  }
  cout << ans;
}
