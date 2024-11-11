#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int res, ans = 0;
  for (int i = 0; i < n; i++) {
    res = 0;
    for (int j = i; j < n; j++) {
      res = res ^ a[j];
      ans = max(ans, res);
    }
  }
  cout << ans;
}
