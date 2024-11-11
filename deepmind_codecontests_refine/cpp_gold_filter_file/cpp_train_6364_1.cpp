#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  int ans = a[n / 2];
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < ans) {
      s = s + ans - a[i] - 1;
    }
    if (a[i] > ans) {
      s = s + a[i] - ans - 1;
    }
  }
  if (n % 2 == 0 || n % 2 == 1) {
    int ans1 = a[n / 2] + 1;
    int s1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < ans1) {
        s1 = s1 + ans1 - a[i] - 1;
      }
      if (a[i] > ans1) {
        s1 = s1 + a[i] - ans1 - 1;
      }
    }
    if (s1 < s) {
      ans = ans1;
      s = s1;
    }
  }
  if (n % 2 == 0 || n % 2 == 1) {
    int ans1 = a[n / 2] - 1;
    int s1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < ans1) {
        s1 = s1 + ans1 - a[i] - 1;
      }
      if (a[i] > ans1) {
        s1 = s1 + a[i] - ans1 - 1;
      }
    }
    if (s1 < s) {
      ans = ans1;
      s = s1;
      cout << ans1 << " " << s1;
      return 0;
    } else {
      cout << ans << " " << s;
      return 0;
    }
  }
  return 0;
}
