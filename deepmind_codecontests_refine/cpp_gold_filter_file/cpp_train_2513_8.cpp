#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s >> s;
  long long ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    int dig = s[i] - '0';
    if (dig % 2 == 0) {
      ans += i + 1;
    }
  }
  cout << ans;
  return 0;
}
