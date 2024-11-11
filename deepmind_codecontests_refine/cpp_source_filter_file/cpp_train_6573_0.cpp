#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int arr[n];
  long long int cnt[k];
  memset(cnt, 0, sizeof(cnt));
  for (long long int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (long long int i = 0; i < n; i++) {
    cnt[arr[i] % k]++;
  }
  long long int ans = 0;
  for (long long int i = 0; i <= k / 2; i++) {
    if (i == 0) {
      ans += cnt[i] / 2;
    } else {
      long long int a = cnt[i];
      long long int b = cnt[n - i];
      long long int val = min(a, b);
      if (i != k - i) {
        ans += val;
      } else {
        ans += val / 2;
      }
    }
  }
  cout << ans * 2 << "\n";
}
