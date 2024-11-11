#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
string vowel = "aouie";
string str;
bool judge(char c) {
  for (int i = 0; i < vowel.size(); i++) {
    if (c == vowel[i]) return true;
  }
  return false;
}
int main() {
  while (cin >> str) {
    int len = str.size();
    if (!judge(str[len - 1]) && str[len - 1] != 'n') {
      puts("NO");
      continue;
    }
    bool flag = true;
    for (int i = 0; i < len - 1; i++) {
      if (judge(str[i]) || str[i] == 'n') {
        continue;
      } else {
        if (judge(str[i + 1])) {
          continue;
        } else {
          flag = false;
          break;
        }
      }
    }
    if (flag)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
