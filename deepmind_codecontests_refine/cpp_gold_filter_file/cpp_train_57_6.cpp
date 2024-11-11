#include <bits/stdc++.h>
using namespace std;
int main() {
  string s[1001], ss[1001];
  cin >> s[0] >> ss[0];
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i] >> ss[i];
  for (int i = 0; i <= n; i++) {
    if (i == 0) {
      cout << s[0] << " " << ss[0] << endl;
      continue;
    } else if (s[i] == s[i - 1]) {
      s[i] = ss[i];
      ss[i] = ss[i - 1];
      cout << s[i] << " " << ss[i] << endl;
    } else if (s[i] == ss[i - 1]) {
      s[i] = s[i - 1];
      cout << s[i] << " " << ss[i] << endl;
    }
  }
  return 0;
}
