#include <bits/stdc++.h>
using namespace std;
string s[105];
int vis[105];
int main() {
  int n;
  string name;
  cin >> n;
  cin >> name;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i] && s[i].substr(0, 3) == name) {
      int flag = 0;
      for (int j = 0; j < n; ++j) {
        if (!vis[i] && s[i].substr(5, 3) == s[j].substr(0, 3)) {
          vis[i] = flag = 1;
          break;
        }
      }
      if (!flag) {
        printf("contest\n");
        return 0;
      }
    }
  }
  printf("home\n");
  return 0;
}
