#include <bits/stdc++.h>
using namespace std;
long long int vis[2000001];
long long int yo[2000002];
long long int ar[200001];
int main() {
  std::ios::sync_with_stdio(false);
  long long int n;
  cin >> n;
  for (long long int i = 0; i < n; i++) {
    long long int t;
    cin >> t;
    ar[i] = t;
    yo[t] = t;
  }
  for (long long int i = 1; i <= 2000001; i++) {
    yo[i] = max(yo[i], yo[i - 1]);
  }
  long long int ans = 0;
  for (long long int i = 0; i < n; i++) {
    if (vis[ar[i]] == 0) {
      vis[ar[i]] = 1;
      for (long long int j = 2 * ar[i]; j <= 2000001; j += ar[i]) {
        ans = max(ans, yo[j] % ar[i]);
      }
    }
  }
  cout << ans;
  return 0;
}
