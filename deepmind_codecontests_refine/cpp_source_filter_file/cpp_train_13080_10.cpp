#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n + 1], s, f, sum = 0, tz = 1, sol, l, r, ans;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> s >> f;
  for (int i = s; i < f; i++) {
    sum = sum + a[i];
  }
  ans = sum, l = s;
  r = f - 1;
  for (int i = 1; i < n; i++) {
    sum = sum - a[r];
    l--;
    r--;
    if (l == 0) {
      l = n;
    }
    if (r == 0) {
      r = n;
    }
    sum = sum + a[l];
    tz++;
    if (ans < sum) {
      ans = sum;
      sol = tz;
    }
  }
  cout << sol;
  return 0;
}
