#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, st = "";
  cin >> s;
  long long ans = 1, sum = 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a' || s[i] == 'b') st += s[i];
  }
  for (int i = 0; i < st.length(); i++) {
    if (st[i] == 'a') {
      sum = (sum + 1) % 1000000007;
    } else {
      ans = (ans * sum) % 1000000007;
      sum = 1;
    }
  }
  if (sum > 1) {
    ans = (ans * sum) % 1000000007;
  }
  ans--;
  cout << ans << endl;
  return 0;
}
