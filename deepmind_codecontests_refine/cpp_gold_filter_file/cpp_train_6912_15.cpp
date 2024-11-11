#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int R = 0;
  for (int i = n; i < s.length(); i += n)
    if (s[i - 1] == s[i - 2] && s[i - 2] == s[i - 3]) ++R;
  cout << R;
  return 0;
}
