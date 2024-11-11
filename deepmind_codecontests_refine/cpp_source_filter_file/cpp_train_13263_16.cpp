#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  s += ',';
  int len = s.length(), vis[2000];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < len; i++) {
    if (s[i] == ',') continue;
    int p = s[i] - '0';
    for (int j = i + 1; j < len; j++) {
      if (s[j] != ',') {
        p *= 10;
        p += s[j] - '0';
      } else {
        i = j;
        break;
      }
    }
    vis[p] = 1;
  }
  stringstream ss;
  string ans;
  for (int i = 0; i <= 1000; i++) {
    if (vis[i] == 1) {
      for (int j = i + 1; j <= 1000; j++) {
        if (vis[j] == 0 && j - i > 1) {
          ss << i << '-' << j - 1 << ',';
          i = j;
          break;
        } else if (vis[j] == 0 && j - i == 1) {
          ss << i << ',';
          i = j;
          break;
        }
      }
    }
  }
  ss >> ans;
  ans.erase(ans.length() - 1);
  cout << ans << endl;
}
