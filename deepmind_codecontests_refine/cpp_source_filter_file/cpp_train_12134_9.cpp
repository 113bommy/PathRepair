#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  int ans = 0, now = 1;
  long long a[x];
  for (int i = 0; i < x; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < x; i++) {
    if (a[i] > a[i - 1]) {
      now++;
    } else {
      now = 1;
    }
    if (ans < now) {
      ans = now;
    }
  }
  cout << ans;
  return 0;
}
