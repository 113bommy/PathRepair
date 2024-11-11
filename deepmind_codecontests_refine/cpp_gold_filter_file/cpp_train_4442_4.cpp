#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[200005], b[200005], k = 0, m1 = 0;
  map<long long, long long> x;
  long long sum = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
    if (b[i] == 0) m1++;
    sum += b[i];
  }
  m -= m1;
  long long ans = 0, ans1 = 1e18, startpos = 0;
  for (int i = 0; i < n; i++) {
    x[a[i]]++;
    ans++;
    if (x[a[i]] == b[a[i]]) k++;
    if (k >= m) {
      while (x[a[startpos]] > b[a[startpos]]) {
        x[a[startpos]]--;
        ans--;
        startpos++;
      }
      ans1 = min(ans1, ans);
    }
  }
  if (ans1 == 1e18)
    cout << -1;
  else
    cout << ans1 - sum;
  return 0;
}
