#include <bits/stdc++.h>
using namespace std;
int main() {
  string st = "BCDEFGJKLNPQRSYZ";
  string str, s;
  getline(cin, str);
  s = str;
  reverse(s.begin(), s.end());
  for (int i = 0; i < str.length(); i++) {
    for (int j = 0; j < st.length(); j++) {
      if (str[i] == st[j]) {
        printf("NO\n");
        return 0;
      }
    }
  }
  for (int i = 0; i < str.length(); i++) {
    if (str[i] != s[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
