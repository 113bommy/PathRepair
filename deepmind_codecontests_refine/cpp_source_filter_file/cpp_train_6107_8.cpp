#include <bits/stdc++.h>
using namespace std;
int main() {
  int ct{0};
  string s;
  cin >> s;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == s[i + 1]) {
      ct++;
    } else {
      ct = 0;
    }
    if (ct == 7) {
      printf("YES");
      return 0;
    }
  }
  printf("NO");
}
