#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int mid = ((int)pow(10, 6)) / 2;
  int l = 1, r = 1000000;
  for (int i = 0; i < n; i++) {
    if (a[i] <= mid)
      l = a[i];
    else
      break;
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] > mid)
      r = a[i];
    else
      break;
  }
  l -= 1;
  r = 1000000 - r;
  cout << max(l, r);
}
