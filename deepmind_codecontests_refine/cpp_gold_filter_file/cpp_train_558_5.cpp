#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int a[105] = {};
  bool f[105] = {};
  cin >> n;
  int ans = 0;
  int r0 = 0, r1 = 0, r11 = 0, r10 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0 || a[i] == 100) continue;
    if (a[i] % 10 == 0) {
      r10++;
    } else if (a[i] < 10)
      r1++;
    else
      r11++;
  }
  int a0 = 0, a1 = 0, a11 = 0, a10 = 0;
  int A[105] = {};
  for (int i = 0; i < n; i++) {
    if (a[i] == 0 || a[i] == 100) {
      A[ans] = a[i];
      ans++;
    } else if (a[i] % 10 == 0) {
      if (!a10) {
        A[ans] = a[i];
        ans++;
      }
      a10++;
    } else if (a[i] < 10) {
      if (!a1) {
        A[ans] = a[i];
        ans++;
      }
      a1++;
    } else {
      if (!r1 && !a11 && !r10) {
        A[ans] = a[i];
        ans++;
      }
      a11++;
    }
  }
  int x = 0;
  cout << ans << endl;
  for (int i = 0; i < ans; i++) {
    cout << A[i] << " ";
  }
  return 0;
}
