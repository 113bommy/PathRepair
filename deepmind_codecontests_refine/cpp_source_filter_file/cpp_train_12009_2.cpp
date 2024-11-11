#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (arr[i] < arr[i - 1]) ans += arr[i - 1] - arr[i];
  }
  cout << ans << endl;
}
