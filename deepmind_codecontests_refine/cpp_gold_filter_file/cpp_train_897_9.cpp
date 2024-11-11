#include <bits/stdc++.h>
using namespace std;
int arr[100005], temp[100005];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  for (int i = 1; i <= n; i++) {
    temp[i] = max(temp[i - 1], arr[i] + 1);
  }
  for (int i = n; i > 1; i--) {
    if (temp[i] - temp[i - 1] > 1) {
      temp[i - 1] += temp[i] - temp[i - 1] - 1;
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += temp[i] - arr[i] - 1;
  }
  cout << ans;
  return 0;
}
