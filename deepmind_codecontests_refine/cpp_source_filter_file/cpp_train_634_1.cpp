#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long ans = 1, c = 0;
  s.push_back('b');
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a')
      c++;
    else if (s[i] == 'b') {
      c++;
      ans = (ans * c) % 10000000007;
      c = 0;
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
