#include <bits/stdc++.h>
using namespace std;
int dp[100][100];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << -1;
    return 0;
  }
  int m = INT_MAX;
  int mi = -1;
  int a[n];
  int m2 = INT_MIN;
  int mi2 = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (m > a[i]) {
      m = a[i];
      mi = i;
    }
    if (m == a[i] && i != 0 && i != n - 1) {
      mi = i;
    }
    if (m2 < a[i]) {
      m2 = a[i];
      mi2 = i;
    }
    if (m2 == a[i] && i != 0 && i != n - 1) {
      mi2 = i;
    }
  }
  if (mi != mi2) {
    int t = a[mi2];
    a[mi2] = a[mi];
    a[mi] = t;
    int flag = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] >= a[i + 1]) {
      } else {
        flag = 1;
      }
    }
    if (flag) {
      int flag2 = 0;
      for (int i = 0; i < n - 1; i++) {
        if (a[i] <= a[i + 1]) {
        } else {
          flag2 = 1;
        }
      }
      if (flag2) {
        cout << mi + 1 << " " << mi2 + 1;
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
