#include <bits/stdc++.h>
using namespace std;
int n, r, i, j, k, c, d, ans;
string s;
int main() {
  cin >> s;
  for (i = 0; i < s.size(); i++) {
    c++;
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y') {
      ans = max(ans, c);
      c = 0;
    }
  }
  c++;
  ans = max(ans, c);
  printf("%d\n", ans);
  return 0;
}
