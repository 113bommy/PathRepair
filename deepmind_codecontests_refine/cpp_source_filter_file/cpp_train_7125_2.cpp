#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int arr[N + 5];
int L[N + 5], R[N + 5];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  L[2] = 1;
  for (int i = 3; i < n; i++) {
    if (arr[i - 2] < arr[i - 1])
      L[i] = 1 + L[i - 1];
    else
      L[i] = 1;
  }
  R[n - 1] = 1;
  for (int i = n - 2; i > 0; i--) {
    if (arr[i + 1] < arr[i + 2])
      R[i] = 1 + R[i + 1];
    else
      R[i] = 1;
  }
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = max({ans, L[i] + 1, R[i] + 1});
    if (arr[i + 1] - arr[i - 1] >= 2) ans = max(ans, L[i] + R[i] + 1);
  }
  cout << ans << '\n';
  return 0;
}
