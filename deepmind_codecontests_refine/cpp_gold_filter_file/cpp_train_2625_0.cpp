#include <bits/stdc++.h>
using namespace std;
long long int n, k, p;
long long int arr[200005], dp[200005];
long long int func(long long int curr, long long int coin, bool flag) {
  long long int ans = 0, temp = 0, left = coin, temp1, sum = 0;
  for (long long int i = 0; i < k; i++) {
    left = coin - sum;
    temp1 = 0;
    for (long long int j = i + k - 1; j < n; j += k) {
      if (left >= arr[j]) {
        temp1 += k;
        left -= arr[j];
      } else
        break;
      if (j + k >= n) {
        for (j = j + k; j < n; j++) {
          if (left >= arr[j]) {
            temp1++;
            left -= arr[j];
          }
        }
      }
    }
    sum += arr[i];
    ans = max(ans, temp + temp1);
    if (arr[i] <= coin)
      temp++;
    else
      break;
  }
  return ans;
}
void solve(long long int test) {
  cin >> n >> p >> k;
  for (long long int i = 0; i < n; i++) {
    dp[i] = -1;
    cin >> arr[i];
  }
  sort(arr, arr + n);
  cout << func(0, p, false) << endl;
}
int main() {
  long long int t = 1, test = 1;
  cin >> t;
  while (t--) {
    solve(test++);
  }
  return 0;
}
