#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, i, j, ans, count;
  vector<long long> v;
  cin >> n;
  int arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  ans = 1;
  count = 1;
  for (i = 0; i < n; i++) {
    if (arr[i + 1] <= 2 * arr[i])
      count++;
    else {
      ans = max(count, ans);
      count = 1;
    }
  }
  ans = max(count, ans);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  solve();
  return 0;
}
