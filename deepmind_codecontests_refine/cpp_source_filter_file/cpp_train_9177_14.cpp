#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, x = 0, ans = 1;
  cin >> n;
  long long arr[n];
  for (i = 0; i < n; i++) cin >> arr[i];
  for (i = 0; i < n; i++) {
    if (arr[i] >= 0) arr[i] = -arr[i] - 1;
  }
  if (n % 2 == 1) {
    int ct = INT_MIN, index = -1;
    for (i = 0; i < n; i++)
      if (arr[i] > ct && arr[i] != -1) {
        ct = arr[i];
        index = i;
      }
    if (index != -1) {
      arr[index] = -arr[index] - 1;
    } else
      arr[0] = 0;
  }
  for (i = 0; i < n; i++) cout << arr[i] << " ";
  cout << endl;
  return 0;
}
