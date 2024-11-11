#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  int c = 0;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n - 1;
  while (l <= r) {
    if (a[l] <= k)
      c++, l++;
    else if (a[r] <= k)
      c++, k--;
    else
      break;
  }
  cout << c << endl;
  return 0;
}
