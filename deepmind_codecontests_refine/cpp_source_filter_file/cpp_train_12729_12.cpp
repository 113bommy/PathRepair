#include <bits/stdc++.h>
using namespace std;
int main() {
  string str1, str2, ans;
  while (cin >> str1 >> str2 >> ans) {
    int alpha[26] = {0};
    for (int i = 0; i < str1.size(); ++i) alpha[str1.at(i) - 'A']++;
    for (int i = 0; i < str2.size(); ++i) alpha[str2.at(i) - 'A']++;
    for (int i = 0; i < ans.size(); ++i) alpha[ans.at(i) - 'A']--;
    bool flag = false;
    for (int i = 0; i < 26; ++i) {
      if (alpha[i] < 0) {
        flag = true;
        break;
      }
    }
    if (flag)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
