#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int m = pow(10, 9) + 7;
  long long ans = 0;
  long long a = 1;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] - '0') {
      ans += a;
      ans %= m;
    }
    a = a * 2;
    a %= m;
  }
  for (int i = 0; i < s.size() - 1; i++) {
    ans = ans * 2;
    ans %= m;
  }
  cout << ans;
}
