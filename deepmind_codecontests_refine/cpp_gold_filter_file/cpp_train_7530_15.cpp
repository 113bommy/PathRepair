#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  char big = 'a';
  string s1 = "";
  cin >> s;
  for (int i = s.size() - 1; i >= 0; i--) {
    if (int(s[i]) >= int(big)) {
      s1 += s[i];
      big = s[i];
    }
  }
  reverse(s1.begin(), s1.end());
  cout << s1;
  return 0;
}
