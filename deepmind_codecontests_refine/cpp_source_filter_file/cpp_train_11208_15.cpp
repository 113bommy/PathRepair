#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int j = 0, ans = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'x') {
      for (j = i; j < n; j++) {
        if (s[j] == 'x')
          cnt++;
        else
          break;
      }
      if (cnt >= 3) ans += cnt - 2;
      cnt = 0;
      i = j + 1;
    }
  }
  cout << ans;
  return 0;
}
