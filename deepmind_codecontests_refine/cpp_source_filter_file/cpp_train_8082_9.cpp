#include <bits/stdc++.h>
using namespace std;
int main() {
  int a = 0;
  int b = 0;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (k % 2 == 0) {
      a++;
    } else {
      b++;
    }
  }
  int ans = max(a, b);
  a -= ans;
  b -= ans;
  if (b >= 3) {
    ans += b / 3;
  }
  cout << ans;
  return 0;
}
