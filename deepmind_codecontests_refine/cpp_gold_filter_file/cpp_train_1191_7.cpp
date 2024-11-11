#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<long long> arr(n);
  vector<long long> brr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    brr[i] = arr[i];
  }
  sort(brr.begin(), brr.end());
  map<long long, int> m;
  for (int i = 0; i < n; i++) {
    m[brr[i]] = i;
  }
  for (int i = 0; i < n; i++) {
    arr[i] = m[arr[i]];
  }
  int l = -1, r = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] != i) {
      l = i;
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (arr[i] != i) {
      r = i;
      break;
    }
  }
  if (l == -1 || r == -1) {
    cout << "yes" << endl;
    cout << 1 << " " << 1 << endl;
  } else {
    reverse(arr.begin() + l, arr.begin() + r + 1);
    int ok = true;
    for (int i = 0; i < n; i++) {
      if (arr[i] != i) {
        ok = false;
      }
    }
    if (ok) {
      cout << "yes" << endl;
      cout << l + 1 << " " << r + 1 << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
