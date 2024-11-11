#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    map<long long int, long long int> count;
    long long int n, ans;
    cin >> n;
    long long int a[n], latestIndex[n], currentIndex[n];
    memset(latestIndex, -1, sizeof(latestIndex));
    bool unique = true;
    for (long long int i = 0; i < n; i++) {
      cin >> a[i];
      count[a[i]]++;
      if (count[a[i]] > 1) unique = false;
    }
    if (unique) {
      cout << -1 << '\n';
      continue;
    }
    ans = 20000001;
    for (long long int i = 0; i < n; i++) {
      if (latestIndex[a[i]] == -1) {
        latestIndex[a[i]] = i;
        currentIndex[a[i]] = i;
      } else {
        currentIndex[a[i]] = i;
        ans = min(ans, currentIndex[a[i]] - latestIndex[a[i]] + 1);
        latestIndex[a[i]] = i;
      }
    }
    cout << ans << '\n';
  }
}
