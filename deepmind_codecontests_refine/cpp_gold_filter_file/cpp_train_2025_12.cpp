#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100005] = {0}, i, j, ans = 0, start = INT_MAX, n, found = 0;
  bool asc = 1;
  cin >> n;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    if (i > 1)
      if (a[i] < a[i - 1]) asc = 0;
  }
  if (asc == 1) {
    cout << "0";
    return 0;
  } else {
    for (i = 1; i < n; i++) {
      if (a[i] > a[i + 1]) {
        start = i + 1;
        break;
      }
    }
    if (start > n) start = n;
    ans = start;
    for (i = 1; i < n; i++) {
      start++;
      if (start > n) start = 1;
      if (start == 1) {
        if (a[1] < a[n]) found = 1;
      } else {
        if (a[start] < a[start - 1]) found = 1;
      }
    }
  }
  if (found == 0)
    cout << n - ans + 1;
  else
    cout << "-1";
  return 0;
}
