#include <bits/stdc++.h>
using namespace std;
int ans;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  if (a[0] == 1) {
    int x = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] != i + 1) break;
      x++;
    }
    ans = max(ans, x);
  }
  if (a[n - 1] == 1000) {
    int x = 0;
    for (int i = n - 2; i >= 0; --i) {
      if (a[i] != 1000 - n + i + 1) break;
      x++;
    }
    ans = max(ans, x);
  }
  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (int j = i; j < n - 1; ++j) {
      if (a[j + 1] != a[j] + 1) {
        i = j;
        break;
      }
      x++;
    }
    ans = max(ans, x - 1);
  }
  cout << ans;
}
