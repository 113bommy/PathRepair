#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 0, k = 0, i = 0;
  cin >> n >> k;
  int arr[108];
  for (i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x <= k)
      arr[i] = 1;
    else
      arr[i] = 0;
  }
  int res = 0;
  for (i = 0; i < n; i++) {
    if (arr[i] == 1)
      res++;
    else
      break;
  }
  if (i == n) {
    cout << res;
    return 0;
  }
  for (i = n - 1; i >= 0; i++) {
    if (arr[i] == 1)
      res++;
    else
      break;
  }
  cout << res;
  return 0;
}
