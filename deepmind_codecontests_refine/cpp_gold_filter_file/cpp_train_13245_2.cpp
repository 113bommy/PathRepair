#include <bits/stdc++.h>
using namespace std;
long long int n, x;
long long int arr[500000];
long long int brr[500000];
long long int c[500000];
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      brr[i] = arr[i];
    }
    int x = *max_element(arr, arr + n);
    bool check1 = true;
    bool check2 = true;
    sort(arr, arr + x);
    sort(arr + x, arr + n);
    for (int i = 0; i < x; i++) {
      if (arr[i] != i + 1) {
        check1 = false;
        break;
      }
    }
    for (int i = x; i < n; i++) {
      if (arr[i] != i + 1 - x) {
        check2 = false;
        break;
      }
    }
    if (check1 == true && check2 == true) {
      res.push_back(x);
    }
    check1 = true;
    check2 = true;
    sort(brr, brr + n - x);
    sort(brr + n - x, brr + n);
    for (int i = 0; i < n - x; i++) {
      if (brr[i] != i + 1) {
        check1 = false;
        break;
      }
    }
    for (int i = n - x; i < n; i++) {
      if (brr[i] != i + 1 - n + x) {
        check2 = false;
        break;
      }
    }
    if (check1 == true && check2 == true) {
      res.push_back(n - x);
    }
    if (res.size() == 2 && res[0] == res[1]) {
      res.pop_back();
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
      cout << res[i] << " " << n - res[i] << "\n";
    }
  }
  return 0;
}
