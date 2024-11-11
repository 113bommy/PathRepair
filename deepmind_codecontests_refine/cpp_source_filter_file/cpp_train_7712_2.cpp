#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, a[200000], l, r, s1 = 0, s2 = 0, smax = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  l = 0;
  r = n - 1;
  while (l <= r) {
    if (s1 + a[l] <= a[r]) {
      s1 = s1 + a[l];
      l++;
    } else if (s2 + a[r] <= a[l]) {
      s2 = s2 + a[r];
      r--;
    } else if (s1 + a[l] <= s2 + a[r]) {
      s1 = s1 + a[l];
      l++;
    } else if (s2 + a[r] <= s1 + a[l]) {
      s2 = s2 + a[r];
      r--;
    }
    if (s1 == s2 && s1 > smax) smax = s1;
  }
  cout << smax;
  return 0;
}
