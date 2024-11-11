#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int arr[n], sum = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
    ans = max(ans, arr[i]);
  }
  int mine = 0;
  for (int i = 0; i < n; i++) {
    mine += (ans - arr[i]);
  }
  while (mine <= sum) {
    ans++;
    mine += n;
  }
  cout << ans << '\n';
  return 0;
}
