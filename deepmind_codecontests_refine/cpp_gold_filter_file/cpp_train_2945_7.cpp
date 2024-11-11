#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[105][105];
bool b[200005];
void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      a[i][j] = 1;
    }
  }
  int num = 0;
  for (int j = 0; j <= 200000; j++) {
    if (!b[j + n - 1] && b[j]) {
      num = j;
      break;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i][i] = num;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf(j == n ? "%d\n" : "%d ", a[i][j]);
    }
  }
  return;
}
int main() {
  b[0] = true;
  b[1] = true;
  for (int i = 2; i <= 200000; i++) {
    if (!b[i]) {
      for (int j = i * 2; j <= 200000; j += i) {
        b[j] = true;
      }
    }
  }
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
