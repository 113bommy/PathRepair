#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  while (cin >> str) {
    string ans;
    while (str.size()) {
      int count = 0;
      char maxn = 'a' - 1;
      int max_pos = 0;
      for (int i = 0; i < str.size(); i++) {
        if (str[i] > maxn) {
          maxn = str[i];
          count = 1;
        } else if (str[i] == maxn) {
          count++;
          max_pos = i;
        }
      }
      for (int i = 0; i < count; i++) ans += maxn;
      str = str.substr(max_pos + 1, str.size());
    }
    cout << ans << endl;
  }
  return 0;
}
