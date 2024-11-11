#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  int ans = 1;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      cnt++;
    } else {
      ans = max(ans, cnt);
      cnt = 1;
    }
  }
  cout << max(ans, cnt);
}
