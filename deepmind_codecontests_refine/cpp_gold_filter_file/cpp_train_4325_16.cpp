#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  cin >> str;
  int n = str.length();
  vector<bool> dp2(str.length(), false);
  vector<bool> dp3(str.length(), false);
  set<string> codewords;
  if (n >= 7) {
    dp2[n - 2] = true;
    codewords.insert(str.substr(n - 2, 2));
  }
  if (n >= 8) {
    dp3[n - 3] = true;
    codewords.insert(str.substr(n - 3, 3));
  }
  for (int i = n - 4; i > 4; i--) {
    if ((dp2[i + 2] && !(str[i] == str[i + 2] && str[i + 1] == str[i + 3])) ||
        dp3[i + 2]) {
      dp2[i] = true;
      codewords.insert(str.substr(i, 2));
    }
    if ((dp3[i + 3] && (str[i] != str[i + 3] || str[i + 1] != str[i + 4] ||
                        str[i + 2] != str[i + 5])) ||
        dp2[i + 3]) {
      dp3[i] = true;
      codewords.insert(str.substr(i, 3));
    }
  }
  cout << codewords.size() << endl;
  for (auto it = codewords.begin(); it != codewords.end(); ++it)
    std::cout << *it << endl;
}
