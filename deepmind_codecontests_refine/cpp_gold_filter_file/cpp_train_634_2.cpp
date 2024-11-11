#include <bits/stdc++.h>
using namespace std;
int fact[100005];
int main() {
  string s;
  cin >> s;
  long long c = 0, ans = 1, i = 0;
  while (i < s.size()) {
    if (s[i] == 'a') {
      c++;
      i++;
    } else if (s[i] == 'b') {
      ans = ans * (c + 1) % 1000000007;
      c = 0;
      while (s[i] == 'b') i++;
    } else
      i++;
  }
  cout << (ans * (c + 1) - 1) % 1000000007 << endl;
}
