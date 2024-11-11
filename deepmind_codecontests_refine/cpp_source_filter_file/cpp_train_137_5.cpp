#include <bits/stdc++.h>
using namespace std;
int main() {
  int k;
  cin >> k;
  string str;
  cin >> str;
  string ans;
  int count[26];
  for (int i = 0; i < 26; i++) {
    count[i] = 0;
  }
  int j = 0;
  for (j = 0; j < str.length(); j++) {
    count[str[j] - 'a']++;
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] % k != 0) {
      cout << "-1";
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) {
      char ch = i + 'a';
      for (int u = 1; u <= count[i] / 2; u++) ans = ans + ch;
    }
  }
  for (int h = 1; h <= k; h++) cout << ans;
}
