#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  string s;
  cin >> s;
  long ans = 0, k = 1;
  for (int i = s.size() - 1; i >= 0; --i) {
    ans = ans * 2 % 1000000007;
    if (s[i] == '1') ans = (ans + k * k) % 1000000007;
    k = k * 2 % 1000000007;
  }
  cout << ans;
  return 0;
}
