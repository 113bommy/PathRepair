#include <bits/stdc++.h>
using namespace std;
int type[300005];
int main() {
  int n, m, c;
  cin >> n >> m;
  string str, stemp, s = "..";
  cin >> str;
  stemp = str;
  long int ans = 0;
  int ret;
  string ::iterator it;
  int i;
  for (it = str.begin(), i = 1; it != str.end(); it++, i++) {
    if ((*it) == '.') type[i] = 1;
  }
  for (int j = 1; j < n; j++) {
    if (str[j] == '.' && str[j - 1] == '.') ans++;
  }
  while (m--) {
    int x;
    char ch;
    cin >> x >> ch;
    if (ch == '.') {
      if (type[x] == 1) {
      } else {
        type[x] = 1;
        if (type[x - 1] && type[x + 1])
          ans += 2;
        else if (type[x - 1] || type[x + 1])
          ans += 1;
      }
    } else {
      if (type[x] == 0) {
      } else {
        type[x] = 0;
        if (type[x - 1] && type[x + 1])
          ans -= 2;
        else if (type[x - 1] || type[x + 1])
          ans -= 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
