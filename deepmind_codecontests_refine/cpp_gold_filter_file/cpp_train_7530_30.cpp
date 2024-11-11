#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  cin >> str;
  int i, j;
  char t = 'a';
  for (i = 0; i < str.size(); i++) {
    if (t < str[i]) t = str[i];
  }
  string ans = "";
  int k = 0, max = 0, now = 0;
  for (i = 0; i < str.size(); i++)
    if (str[i] == t) max++;
  while (k < str.size()) {
    if (now == max) {
      t = 'a';
      max = 0;
      now = 0;
      for (j = k; j < str.size(); j++) {
        if (t < str[j]) t = str[j];
      }
      for (j = k; j < str.size(); j++)
        if (str[j] == t) max++;
    }
    if (str[k] == t) {
      ans += t;
      now++;
    }
    k++;
  }
  cout << ans << endl;
  return 0;
}
