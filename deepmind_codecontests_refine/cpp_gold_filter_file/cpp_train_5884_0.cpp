#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 2; (1ll << (i - 1)) <= b; i++) {
    for (int j = 0; j < i - 1; j++) {
      long long x = ((1ll << i) - 1) ^ (1ll << j);
      if (a <= x && x <= b) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}
