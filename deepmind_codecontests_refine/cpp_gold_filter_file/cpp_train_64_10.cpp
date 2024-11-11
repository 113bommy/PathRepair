#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  int n;
  cin >> n;
  arr[0] = 1;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  arr[n + 1] = 1000000;
  int ans = 999999;
  for (int i = 0; i <= (n); i++) {
    ans = min(ans, max(arr[i] - 1, 1000000 - arr[i + 1]));
  }
  cout << ans;
}
