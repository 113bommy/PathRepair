#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int even = 0, leven = 0, lodd = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      leven = i;
      even++;
    } else {
      lodd = i;
      even--;
    }
  }
  int ans = even > 0 ? lodd : leven;
  cout << ans;
}
