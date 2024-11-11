#include <bits/stdc++.h>
using namespace std;
int ans[1005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  ans[0] = 0;
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == 'a') {
      ans[i - 1] ^= 1;
      ans[i] = 1;
    }
  }
  for (int i = 0; i < s.length(); i++) cout << ans[i] << " ";
  return 0;
}
