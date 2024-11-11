#include <bits/stdc++.h>
using namespace std;
int main() {
  int c[4];
  while (cin >> c[0] >> c[1] >> c[2] >> c[3]) {
    int n = 0;
    for (int i = 0; i < 4; i++) n += c[i];
    for (int i = 0; i < 4; i++) {
      if (c[i]) {
        int b[4];
        for (int k = 0; k < 4; k++) b[k] = c[k];
        vector<int> ans{i};
        b[i]--;
        for (int k = 1; k < n; k++) {
          if (ans[k - 1] == 0) {
            if (b[1]) {
              ans.push_back(1);
              b[1]--;
            } else
              break;
          } else if (ans[k - 1] == 3) {
            if (b[2]) {
              ans.push_back(2);
              b[2]--;
            } else
              break;
          } else if (ans[k - 1] == 1) {
            if (b[0]) {
              ans.push_back(0);
              b[0]--;
            } else if (b[2]) {
              ans.push_back(2);
              b[2]--;
            } else
              break;
          } else if (ans[k - 1] == 2) {
            if (b[3]) {
              b[3]--;
              ans.push_back(3);
            } else if (b[1]) {
              ans.push_back(1);
              b[1]--;
            } else
              break;
          }
        }
        if (ans.size() == n) {
          puts("YES");
          for (auto x : ans) cout << x << " ";
          cout << endl;
          return 0;
        }
      }
    }
    puts("NO");
  }
  return 0;
}
