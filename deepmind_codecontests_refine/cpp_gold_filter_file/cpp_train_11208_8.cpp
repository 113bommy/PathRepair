#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  char cha[n];
  int ct = 0;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> cha[i];
    if (cha[i] == 'x') {
      ct++;
    } else {
      if (ct > 2) {
        ans = ans + (ct - 2);
      }
      ct = 0;
    }
  }
  if (cha[n - 1] == 'x' && ct > 2) {
    ans = ans + (ct - 2);
  }
  cout << ans;
  return 0;
}
