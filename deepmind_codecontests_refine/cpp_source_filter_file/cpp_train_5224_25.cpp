#include <bits/stdc++.h>
using namespace std;
int a[10], n;
string s;
int main() {
  cin >> n >> s;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] != 'L' && s[i] != 'R')
      a[s[i] - '0'] = 0;
    else if (s[i] == 'L')
      for (int j = 0; i < 10; ++j) {
        if (!a[j]) {
          a[j] = 1;
          break;
        }
      }
    else
      for (int j = 9; i > -1; --j)
        if (!a[j]) {
          a[j] = 1;
          break;
        }
  }
  for (int i = 0; i < 10; ++i) cout << a[i];
}
