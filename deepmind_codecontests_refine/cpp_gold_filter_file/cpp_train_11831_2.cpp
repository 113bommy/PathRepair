#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++)
    cnt += (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
            s[i] == 'u' ||
            ((s[i] >= '0' && s[i] <= '9') && (s[i] - '0') % 2 == 1));
  cout << cnt;
  return 0;
}
