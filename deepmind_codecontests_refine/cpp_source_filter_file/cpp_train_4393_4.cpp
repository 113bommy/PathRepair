#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int i = 0;
  while (k && i < n - 1) {
    if (s[i] == '4' && s[i + 1] == '7') {
      if (i % 2 == 0)
        s[i + 1] = '4', k--;
      else {
        if (s[i - 1] == '4') {
          if (k % 2 == 1) s[i] = '7';
          break;
        } else
          s[i] = '7';
      }
    }
    i++;
  }
  cout << s;
  return 0;
}
