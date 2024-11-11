#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, ans = 1, temp = 1;
  cin >> n;
  string arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n);
  for (i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1])
      temp++;
    else {
      if (ans < temp) ans = temp;
      temp = 1;
    }
  }
  if (temp > ans) ans = temp;
  cout << ans << endl;
}
