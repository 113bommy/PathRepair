#include <bits/stdc++.h>
using namespace std;
bool palyndrom(string s) {
  for (int i = 0, j = s.size() - 1; i < s.size(), j >= 0; i++, j--) {
    if (s[j] != s[i]) return false;
  }
  return true;
}
char mirror[11] = {'A', 'H', 'I', 'O', 'U', 'V', 'W', 'X', 'Y', 'T', 'M'};
int main() {
  string s;
  cin >> s;
  if (!palyndrom(s)) {
    printf("NO");
    return 0;
  }
  for (int i = 0; i < s.size(); ++i) {
    bool check = false;
    for (int j = 0; j < 11; ++j) {
      if (s[i] == mirror[j]) {
        check = true;
        break;
      }
    }
    if (!check) {
      printf("NO");
      return 0;
    }
  }
  printf("YES");
  return 0;
}
