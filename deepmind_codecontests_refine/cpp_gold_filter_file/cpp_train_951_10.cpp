#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ;
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n - 1, last = INT_MIN;
  string s;
  while (l <= r) {
    if (a[l] != a[r]) {
      if (a[l] < a[r] && last < a[l]) {
        s += 'L';
        last = a[l];
        l++;
      } else if (a[l] > a[r] && last < a[r]) {
        s += 'R';
        last = a[r];
        r--;
      } else if (last < a[l]) {
        last = a[l];
        l++;
        s += 'L';
      } else if (last < a[r]) {
        last = a[r];
        r--;
        s += 'R';
      } else {
        l++;
        r--;
        break;
      }
    } else {
      if (a[l] <= last) {
        l++;
        r--;
        break;
      }
      int len1 = 0, len2 = 0;
      for (int j = l + 1; j < r; j++) {
        if (a[j] > a[j - 1])
          len1++;
        else
          break;
      }
      for (int j = r - 1; j > l; j--) {
        if (a[j] > a[j + 1])
          len2++;
        else
          break;
      }
      last = a[l];
      if (len1 > len2) {
        l++;
        s += 'L';
      } else {
        r--;
        s += 'R';
      }
    }
  }
  cout << s.length() << endl;
  cout << s << endl;
  return 0;
}
