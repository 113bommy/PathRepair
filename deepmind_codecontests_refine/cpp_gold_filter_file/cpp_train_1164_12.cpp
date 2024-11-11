#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  for (int i = 0; i < n - 1 && k; ++i)
    if (s[i] == '4' && s[i + 1] == '7') {
      if ((i + 1) % 2 == 0) {
        if (i - 1 >= 0 && s[i - 1] == '4') {
          if (k % 2) s[i] = '7';
          k = 0;
        } else {
          s[i] = '7';
          k--;
        }
      } else {
        if (i + 2 < n && s[i + 2] == '7') {
          if (k % 2) s[i + 1] = '4';
          k = 0;
        } else {
          s[i + 1] = '4';
          k--;
        }
      }
    }
  cout << s << endl;
  return 0;
}
