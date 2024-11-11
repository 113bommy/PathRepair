#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
long long arr[505] = {0};
long long brr[505] = {0};
int main() {
  ios ::sync_with_stdio(false);
  cin.tie(0);
  long long n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    brr[i] = arr[i];
  }
  for (int i = 2; i <= n; i++) {
    if (brr[i] + brr[i - 1] < k) {
      brr[i] += (k - brr[i] - brr[i - 1]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += brr[i] - arr[i];
  }
  cout << ans << endl;
  for (int i = 1; i <= n; i++) {
    cout << brr[i] << " ";
  }
  cout << endl;
  return 0;
}
