#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int now = 0;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (now != x) {
      ans += abs(now - x);
      now = x;
    }
  }
  cout << ans << endl;
  return 0;
}
