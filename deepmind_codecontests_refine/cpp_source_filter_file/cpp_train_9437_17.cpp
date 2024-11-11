#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    string s;
    int count[26] = {0}, d = 0;
    cin >> s;
    int l = s.length();
    for (int i = 0; i < l; i++) count[s[i] - 'a']++;
    for (int i = 0; i < 26; i++)
      if (count[i] > 0) d++;
    if (d > 4 || d == 1) {
      cout << "No";
      continue;
    }
    if (d == 2) {
      int flag = 0;
      for (int i = 0; i < 26; i++)
        if (count[i] != 0 && count[i] < 2) {
          flag = 1;
          break;
        }
      if (flag == 1) {
        cout << "No";
      } else {
        cout << "Yes";
      }
      continue;
    }
    if (d == 4) {
      cout << "Yes";
      continue;
    }
    if (d == 3) {
      int i;
      for (i = 0; i < 26; i++)
        if (count[i] % 2 == 0 && count[i] != 0) break;
      if (i < 26) {
        cout << "Yes";
      } else
        cout << "No";
    }
  }
  return 0;
}
