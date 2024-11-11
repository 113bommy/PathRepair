#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  long long a[n], ans = n;
  for (int i = (0); i < (n); i++) cin >> a[i];
  int len = 1;
  for (int i = (1); i < (n); i++) {
    if (a[i] == a[i - 1]) {
      len++;
      if (i == n - 1) {
        ans += (len * (len - 1)) / 2;
      }
    } else {
      ans += (len * (len - 1)) / 2;
      len = 1;
    }
  }
  cout << ans;
  return 0;
}
