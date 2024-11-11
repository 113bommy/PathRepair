#include <bits/stdc++.h>
int arr[200005];
char ans[200005];
using namespace std;
int main() {
  int index = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int l = 0, r = n - 1;
  int k = 0, k1, k2;
  string res;
  while (l <= r) {
    k1 = arr[l] - k;
    k2 = arr[r] - k;
    if (k1 < k2 && k1 > 0) {
      k = arr[l];
      l++;
      res += 'L';
    } else if (k1 == k2) {
      string res2 = res;
      int k1 = k;
      while (arr[l] > k) {
        res += 'L';
        k = arr[l];
        l++;
      }
      while (arr[r] > k1) {
        k1 = arr[r];
        res2 += 'R';
        r--;
      }
      if (res.length() < res2.length()) {
        res = res2;
      }
      break;
    } else {
      if (k2 > 0) {
        k = arr[r];
        r--;
        res += 'R';
      } else if (k2 <= 0 && k1 > 0) {
        k = arr[l];
        l++;
        res += 'L';
      } else
        break;
    }
  }
  cout << res.size() << endl;
  cout << res << endl;
  cout << endl;
  return 0;
}
