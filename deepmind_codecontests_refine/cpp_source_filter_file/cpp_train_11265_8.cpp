#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, sum = 0, j, maxi, k;
  cin >> n;
  int a[n + 1];
  for (i = 1; i <= n; i++) cin >> a[i];
  vector<int> l(n + 1, 1);
  vector<int> r(n + 1, 1);
  for (i = n - 1; i >= 1; i--) {
    if (a[i] < a[i - 1]) {
      r[i] = r[i - 1] + 1;
    }
  }
  for (i = 2; i <= n; i++) {
    if (a[i] > a[i - 1]) {
      l[i] = l[i - 1] + 1;
    }
  }
  maxi = *max_element(l.begin(), l.end());
  for (i = 2; i < n; i++) {
    if (a[i - 1] < a[i + 1]) {
      maxi = max(maxi, l[i - 1] + r[i + 1]);
    }
  }
  cout << maxi;
  return 0;
}
