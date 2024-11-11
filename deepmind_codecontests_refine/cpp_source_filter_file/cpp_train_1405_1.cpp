#include <bits/stdc++.h>
using namespace std;
int n;
int down(int a, int b) {
  if (a > b) {
    return a - b;
  } else
    return a + 1 + (n - 1) - b;
}
int up(int a, int b) {
  if (a > b) {
    return n - 1 - a + b + 1;
  } else
    return b - a;
}
int main() {
  cin >> n;
  int i;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  int flag = 1;
  int ans;
  ans = up(a[0], 0);
  for (i = 1; i < n; i++) {
    if (i % 2 != 0) {
      if (down(a[i], i) != ans) {
        flag = 0;
        goto out;
      }
    } else {
      if (up(a[i], i) != ans) {
        flag = 0;
        goto out;
      }
    }
  }
out:
  if (flag) {
    cout << "Yes";
  } else
    cout << "No";
  return 0;
}
