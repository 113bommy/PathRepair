#include <bits/stdc++.h>
using namespace std;
int main() {
  long long arr[100009], lft[100009] = {0}, rgt[100009] = {0}, n, res = 0;
  cin >> n;
  arr[0] = -2;
  arr[n + 1] = 0x3f3f3f3f;
  for (int i = 1; i <= n; i++) cin >> arr[i], lft[i] = rgt[i] = 1;
  for (int i = 2; i <= n; i++) {
    if (arr[i] > arr[i - 1]) lft[i] += lft[i - 1];
  }
  for (int i = n - 1; i > 0; i--) {
    if (arr[i] < arr[i + 1]) rgt[i] += rgt[i + 1];
  }
  for (int i = 1; i <= n; i++) {
    res = max(res, lft[i] + 1);
    if (arr[i + 1] - arr[i - 1] > 1) {
      res = max(res, lft[i - 1] + rgt[i + 1] + 1);
    }
  }
  cout << res;
}
