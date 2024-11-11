#include <bits/stdc++.h>
using namespace std;
bool color[205];
bool alp[30];
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int maxn = s[0] - 'a';
  bool F = 0;
  for (int i = 0; i < n; i++) {
    if (maxn > s[i] - 'a') {
      bool flag = 0;
      for (int j = s[i] - 'a' + 1; j <= maxn; j++) {
        if (alp[j]) {
          flag = 1;
          break;
        }
      }
      if (flag) {
        F = 1;
        break;
      } else
        color[i] = 1, alp[s[i] - 'a'] = 1;
    }
    maxn = max(maxn, s[i] - 'a');
  }
  if (F)
    cout << "NO" << '\n';
  else {
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++) cout << color[i];
  }
}
