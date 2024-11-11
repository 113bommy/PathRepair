#include <bits/stdc++.h>
using namespace std;
long long n, k;
int arr[100010];
long long ans = 0;
long long hun = 0, cop, total;
int main() {
  scanf("%d%d", &n, &k);
  cop = k;
  total = n * 100;
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    hun += arr[i];
    ans += (arr[i] / 10);
    arr[i] %= 10;
  }
  sort(arr, arr + n, greater<int>());
  for (int i = 0; i < n; i++) {
    if (k - (10 - arr[i]) >= 0) {
      ans++;
      k -= (10 - arr[i]);
    }
  }
  total -= (hun + cop - k);
  k = min(total, k);
  ans += (k / 10);
  cout << ans << endl;
  return 0;
}
