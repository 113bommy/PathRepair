#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 99999999;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a = 0;
    cin >> a;
    ans = min(a, ans);
  }
  if (ans == 1) {
    cout << "-1";
  } else {
    cout << ans - 1;
  }
  return 0;
}
