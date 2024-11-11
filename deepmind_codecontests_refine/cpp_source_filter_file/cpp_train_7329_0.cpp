#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 9];
  for (int i = 0; i <= n - 1; i++) cin >> arr[i];
  string str;
  cin >> str;
  int DP[n + 9];
  int prev = arr[0];
  DP[0] = (str[0] - '1') * arr[0];
  for (int i = 1; i <= n - 1; i++) {
    if (str[i] == '1') {
      DP[i] = max(DP[i - 1] + arr[i], prev);
      prev += arr[i];
    } else {
      DP[i] = DP[i - 1];
      prev += arr[i];
    }
  }
  cout << DP[n - 1];
  return 0;
}
