#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  cin >> n >> k >> s;
  for (int i = 0; i < (int)s.size() - 1; i++)
    if (s[i] == '4' && s[i + 1] == '7') {
      if (i % 2) {
        if (i != 0 && s[i - 1] == '4') {
          if (k % 2) s[i] = s[i + 1] = '7';
          cout << s << endl;
          return 0;
        } else {
          s[i] = s[i + 1] = '7';
          k--;
        }
      } else {
        s[i] = s[i + 1] = '4';
        k--;
      }
    };
  cout << s << endl;
}
