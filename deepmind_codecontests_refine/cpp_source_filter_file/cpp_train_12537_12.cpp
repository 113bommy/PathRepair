#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string str;
  cin >> str;
  int ans = 0;
  for (int i = 0; i < (int)str.size(); i++)
    if (str[i] == 'R')
      for (int j = i + 1; j < (int)str.size(); j++) {
        if (str[j] == 'L') {
          ans += (j - i - 1) % 2;
          i = j + 1;
          break;
        } else if (str[j] == 'R') {
          i = j;
        }
      }
  for (int i = 0; i < (int)str.size(); i++)
    if (str[i] == 'L')
      for (int j = i - 1; j >= 0; j--) {
        if (str[j] != '.') {
          i = j;
          break;
        }
        str[j] = 'L';
      }
    else if (str[i] == 'R')
      for (int j = i + 1; j < (int)str.size(); j++) {
        if (str[j] != '.') {
          i = j;
          break;
        }
        str[j] = 'R';
      }
  for (int i = 0; i < (int)str.size(); i++)
    if (str[i] == '.') ans++;
  cout << ans << endl;
}
