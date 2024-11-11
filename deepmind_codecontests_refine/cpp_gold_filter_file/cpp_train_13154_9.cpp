#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  int len = str.length();
  int alpha[26];
  for (int i = 0; i < len; ++i) {
    alpha[((int)str[i]) - 97] = 1;
  }
  int ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (alpha[i] == 1) {
      ans++;
    }
  }
  if (ans % 2 == 0)
    cout << "CHAT WITH HER!" << endl;
  else
    cout << "IGNORE HIM!" << endl;
  return 0;
}
