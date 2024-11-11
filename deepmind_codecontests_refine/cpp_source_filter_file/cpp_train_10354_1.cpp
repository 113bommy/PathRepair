#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int main() {
  int n, i, num = 0, temp, ans = 0;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (temp = 1; temp <= n; temp++) {
    if (arr[temp] != 0) break;
  }
  ans = arr[temp];
  for (i = temp; i < n; i++) {
    if ((num + (arr[i] - arr[i + 1])) < 0) {
      ans = ans - (num + (arr[i] - arr[i + 1]));
      num = 0;
    } else
      num += (arr[i + 1] - arr[i + 1]);
  }
  cout << ans << endl;
  return 0;
}
