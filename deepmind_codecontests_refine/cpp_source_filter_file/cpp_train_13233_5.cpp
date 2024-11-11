#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n];
  int brr[n];
  vector<int> b;
  long long s = 0;
  int flag = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    brr[i] = arr[i];
    s = s + arr[i];
  }
  sort(brr, brr + n);
  for (int i = 0; i < n; i++) {
    flag = 0;
    if ((s - arr[i]) % 2 == 0) {
      int l = 0;
      int h = n - 1;
      int mid = (l + h) / 2;
      int p = (s - arr[i]) / 2;
      while (l <= h) {
        mid = l + (h - l) / 2;
        if (brr[mid] > p) {
          h = mid - 1;
        }
        if (brr[mid] < p) {
          l = mid + 1;
        }
        if (brr[mid] == p) {
          if (p == arr[i]) {
            if (brr[mid + 1] == p || brr[mid - 1] == p) {
              flag = 1;
              break;
            } else {
              flag = 0;
              break;
            }
          } else {
            flag = 1;
            break;
          }
        }
      }
      if (flag == 1) {
        b.push_back(i + 1);
      }
    }
  }
  if (b.size() == 0) {
    cout << 0 << "\n";
  }
  if (b.size() != 0) {
    cout << b.size() << "\n";
    for (int i = 0; i < b.size(); i++) {
      cout << b[i] << "\t";
    }
  }
}
