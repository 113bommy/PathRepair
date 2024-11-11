#include <bits/stdc++.h>
using namespace std;
const unsigned long long mod = 1e9 + 7;
int main() {
  string s;
  cin >> s;
  if (s.length() == 1) {
    cout << 51;
    return 0;
  }
  long ans;
  int val = 0;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) val++;
  }
  ans = 26 * (s.length() + 1);
  cout << (ans - s.length() + val);
}
