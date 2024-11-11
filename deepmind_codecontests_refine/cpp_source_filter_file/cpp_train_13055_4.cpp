#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << setprecision(32);
  int n, x;
  cin >> n;
  int a[5] = {0};
  for (int i = 0; i < n; i++) {
    cin >> x;
    a[x]++;
  }
  int ans = 0;
  int m = min(a[1], a[2]);
  ans += m;
  a[1] -= m;
  a[2] -= m;
  a[3] += m;
  if (a[1] > 0) {
    if (a[1] == 1) {
      if (a[3]) {
        ans++;
        a[1] = 0;
      } else if (a[4] >= 2) {
        ans += 2;
        a[1] = 0;
      }
    } else if (a[1] == 2) {
      if (a[4]) {
        ans += 2;
        a[1] = 0;
      } else if (a[3] >= 2) {
        ans += 2;
        a[1] = 0;
      }
    } else if (a[1] == 3) {
      ans += 2;
      a[1] = 0;
    } else if (a[1] == 4) {
      ans += 3;
      a[1] = 0;
    } else if (a[1] == 5) {
      if (a[3] || a[4]) {
        ans += 4;
        a[1] = 0;
      }
    } else if (a[1] % 3 == 0) {
      ans += 2 * (a[1] / 3);
      a[1] = 0;
    } else if (a[1] % 3 == 1) {
      ans += 2 * ((a[1] - 4) / 3);
      ans += 3;
      a[1] = 0;
    } else if (a[1] % 3 == 2) {
      ans += 2 * ((a[1] - 8) / 3);
      ans += 6;
      a[1] = 0;
    }
  } else {
    if (a[2] % 3 == 0) {
      ans += 2 * (a[2] / 3);
      a[2] = 0;
    } else if (a[2] % 3 == 2) {
      ans += 2 * (a[2] / 3);
      ans += 2;
      a[2] = 0;
    } else if (a[2] > 1) {
      if (a[4])
        ans += 1 + 2 * (a[2] / 3);
      else
        ans += 2 + 2 * (a[2] / 3);
      a[2] = 0;
    } else if (a[4]) {
      ans++;
      a[2] = 0;
    } else if (a[3] >= 2) {
      ans += 2;
      a[3] = 0;
    }
  }
  if (a[1] || a[2]) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
