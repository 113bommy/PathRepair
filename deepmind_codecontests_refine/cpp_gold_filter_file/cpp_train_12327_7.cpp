#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  long long int arr[n], inv = 0;
  for (long long int i = 0; i < n; i++) cin >> arr[i];
  for (long long int i = 0; i < n; i++)
    for (long long int j = i + 1; j < n; j++)
      if (arr[j] < arr[i]) inv++;
  long long int ans[inv + 1];
  ans[0] = 0, ans[1] = 1, ans[2] = 4;
  for (long long int i = 3; i <= inv; i++) {
    ans[i] = 4 + ans[i - 2];
  }
  cout << ans[inv];
  return 0;
}
