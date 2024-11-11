#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i + 2 < s.size(); i++) {
    set<char> qwe;
    for (int j = 0; j < 3; j++) {
      if (s[i + j] != '.') qwe.insert(s[i + j]);
    }
    if (qwe.size() == 3) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
  return 0;
}
