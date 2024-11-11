#include <bits/stdc++.h>
using namespace std;
char s[2000010], str[2000010], vis[50];
int main() {
  int n, m, len, loc, maxc = -0x3f3f3f3f, maxi = -0x3f3f3f3f, last = 0, pos = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str >> m;
    last = 0;
    pos = 0;
    len = strlen(str);
    for (int i = 0; i < len; i++) {
      int tmp = str[i] - 'a';
    }
    for (int j = 0; j < m; j++) {
      cin >> loc;
      maxi = max(maxi, loc + len - 1);
      pos = max(last + 1, loc);
      int t = pos;
      for (int k = pos - loc; k < len; k++) {
        s[t++] = str[k];
      }
      last = loc + len - 1;
    }
  }
  for (int i = 1; i <= maxi; i++) {
    if (s[i] >= 'a' && s[i] <= 'z')
      cout << s[i];
    else {
      cout << "a";
    }
  }
  return 0;
}
